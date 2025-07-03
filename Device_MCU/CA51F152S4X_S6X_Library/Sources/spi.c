#ifndef _SPI_C_
#define _SPI_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
/*********************************************************************************************************************/
#ifdef SPI_ENABLE
/*********************************************************************************************************************/
//  SPI主机从机通信的主机程序，主机写入数据。  
//   ____________            _____________ 
//  |            |   SSB    |             |
//  |            |<-------->|             |
//  |            |   SCK    |             |
//  |  CA51F2(M) |<-------->|  CA51F2(S)  |
//  |(SPI_Master)|   MOSI   | (SPI_Slave) |
//  |            |<-------->|             |
//  |            |	 MISO		|             |
//  |            |<-------->|             |
//  |____________|          |_____________|

/*********************************************************************************************************************/
unsigned char spi_int_flag;

#ifdef HAVE_SLAVE_SPI
#define SPI_MAX_RXDATA	20
unsigned char	xdata spi_rxBuf[SPI_MAX_RXDATA];
unsigned char spi_head;
unsigned char spi_tail;
#endif
void SPI_ISR_proc (void)
{
	if(SPSTA & SPIF)					 //SPI  interrupt
	{
		SPSTA |= SPIF;
		spi_int_flag = 1;
		#ifdef HAVE_SLAVE_SPI
		SPSTA |= SPIF; 				//清除SPI中断标志
		//接收一字节数据
		spi_head++;
	 	spi_head %= SPI_MAX_RXDATA;
		spi_rxBuf[spi_head]=SPDAT;	//接收一字节数据			
		#endif
	}	
	if(SPSTA&MODF)
	{
		SPSTA|=MODF;	
	}	
	if(SPSTA&WCOL)
	{
		SPSTA|=WCOL;
	}	
}

#define SPI_SSB_SET_OUT 				P17_CFG_SPI_SCS//spi片选
#define SPI_SCK_SET_OUT 				P16_CFG_SPI_SCK//spi 时钟
#define SPI_SPI_MOSI_SET_OUT 		P15_CFG_SPI_SDO//spi 数据输出
#define SPI_SPI_MISO_SET_IN 		P14_CFG_SPI_SDI//spi 数据输入
#if 0
void Timer1_init(void)
{	
	TMOD = (TMOD&0x0F)|0x20; 	//模式选择: 定时器1，模式2。
	TH1 = 0xfe;    					//高8位装初值
	TL1 = 0xfe;    					//低8位装初值	
	TR1 = 1;       //定时器1使能  
	ET1 = 1;       //定时器1中断使能
	//PT1 = 1;       //设置定时器1中断优先级为低优先级	
}
#endif
#ifdef HAVE_MASTER_SPI
void SPI_Master_Init(void)
{
 	SPI_SSB_SET_OUT;	//spi片选
	SPI_SCK_SET_OUT;	//spi 时钟
	SPI_SPI_MOSI_SET_OUT;//spi 数据输出
	SPI_SPI_MISO_SET_IN; //spi 数据输入
	#if 0 //输出时钟选择位使用定时器 1 溢出标志，每两次溢出传输一次数据 
	Timer1_init();
	SPCON =	SPEN(1) | LSBF(0) | SSIG(1) | MSTR(1) | CPOL(0) | CPHA(0) |CKOS(2);	   //2  使用定时器 1 溢出标志，每两次溢出传输一次数据
	#else
	SPCON = SPEN(1) | LSBF(0) | SSIG(1) | MSTR(1) | CPOL(0) | CPHA(0) |CKOS(0); 	  //CKOS  0： 高位先发, SSB 有效，主机, 1/8 系统时钟  CKOS 00：1/8 系统时钟 1：1/24 系统时钟 10：使用定时器 1 溢出标志，每两次溢出传输一次数据
	#endif
	SPSTA |= SPIE;	
	INT2EN = 0;//查询等等数据发送完成
	spi_int_flag=0;
}

/****************************************************************************
* 名    称：void SPI_Master_Write(u8 idx)
* 功    能：写 spi 写数据
* 入口参数：idx   寄存器地址
* 出口参数：无
* 说    明：
* 调用方法：SPI_Master_Write(0x00);
****************************************************************************/
void SPI_Master_Write(unsigned char idx)
{
		SPDAT=idx;	 
		while(!(SPSTA & SPIF));	
		SPSTA |= SPIF;
		spi_int_flag=0;
}
/****************************************************************************
* 名    称：unsigned 	char SPI_Master_WriteRead(u8 idx)
* 功    能：写 spi 读写数据
* 入口参数：idx   寄存器地址
* 出口参数：无
* 说    明：
* 调用方法：SPI_Master_WriteRead(0x00);
****************************************************************************/
unsigned 	char SPI_Master_WriteRead(unsigned char idx)
{
		SPDAT=idx;	 
		while(!(SPSTA & SPIF));	
		SPSTA |= SPIF;
		spi_int_flag=0;
	    return SPDAT;
		
}
#endif
//////////////////////////////////////////////////////////////////////
#ifdef HAVE_SLAVE_SPI
void SPI_Slave_Init(void)
{
 	SPI_SSB_SET_OUT;	//spi片选
	SPI_SCK_SET_OUT;	//spi 时钟
	SPI_SPI_MOSI_SET_OUT;//spi 数据输出
	SPI_SPI_MISO_SET_IN; //spi 数据输入
	
	SPCON = SPEN(1) | LSBF(0) | SSIG(1) | MSTR(0) | CPOL(0) | CPHA(0) |CKOS(0); //高位先发, SSB 有效，从机, 1/8 系统时钟
	SPSTA |= SPIE;	
	INT2EN = 1;
	//Timer2_init();
	spi_int_flag=0;
	spi_head=spi_tail=0;
}
/****************************************************************************
* 名    称：SPI_SlaveRead
* 功    能：spi 读写数据
* 入口参数:	pdat：接收数据放入字符数组指针
* 返回值：  1：接收成功 0：无数据接收
* 说    明：
* 调用方法：
****************************************************************************/
bit SPI_SlaveRead(u8_t *pdat)
{
	if(spi_head!=spi_tail)
	{
		if(spi_tail==SPI_MAX_RXDATA-1)
		{
			spi_tail=0;
		}
		else
		{
			spi_tail++;
		}		
		*pdat=spi_rxBuf[spi_tail];
		return 1;
	}
	return 0;
}
#endif
/****************************************************************************
* 名    称：SPI_init
* 功    能：spi 初始化
* 入口参数:	无
* 返回值：  无
* 说    明：
* 调用方法：
****************************************************************************/
void SPI_init(void)
{
	#ifdef HAVE_MASTER_SPI       //SPI主机配置
	   SPI_Master_Init();
  #endif
	
	#ifdef HAVE_SLAVE_SPI        //SPI从机配置
	   SPI_Slave_Init();
  #endif	
}
//////////////////////////////////////////////////////////////////////
#endif
#endif
