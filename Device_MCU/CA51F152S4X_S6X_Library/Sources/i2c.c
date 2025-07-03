#ifndef _I2C_C_
#define _I2C_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
/*********************************************************************************************************************/
#ifdef I2C_ENABLE

#define I2C_ADDR    		    0XCA  // I2C 从机地址+写位
#define IIC_MAX_BUF_NUM	    20
unsigned char iic_TxRXBuf[IIC_MAX_BUF_NUM]={0};
///////////////////////////////////////////////////////////////////
#ifdef HAVE_MASTER_IIC
unsigned char iic_txIndex;
unsigned char I2C_CurrDeviceAddr;
unsigned char iic_regAddr;
unsigned char iic_txLength;  //发送数据的长度
	
bit iicEnd;
bit iicWriteRead; // 0：write  1：read
bit iic_rdSession; 
unsigned char iicWriteNoAck;
unsigned char I2CSTA_STAUST;	
unsigned char iic_rxIndex;
unsigned char iic_rxLength;
#endif
///////////////////////////////////////////////////////////////////
#ifdef HAVE_SLAVE_IIC
unsigned char I2CDataIndex;
unsigned char regAddr;
bit iicReadMode;
#endif
/*********************************************************************************************************************/
//  I2C主机从机通信的主机程序，主机读取20字节数据。  
//   ____________            _____________ 
//  |            |   SDA    |             |
//  |            |<-------->|             |
//  |            |          |             |
//  |  CA51F2(M) |          | CA51F2(S)   |
//  |(I2C_Master)|          | (I2C_Slave) |
//  |            |   SCL    |             |
//  |            |--------->|             |
//  |____________|          |_____________|
//
/*********************************************************************************************************************/
/******************************************************************************
函数名：  I2C_SelectComPin
功能描述：I2C 选择端口
输入参数: 无
返回值： 无					

******************************************************************************/
void I2C_SelectComPin(void)
{
	/**********选择I2C端口******************************************************************/
  //I2C引脚SCL/SDA功能可以映射到任意GPIO引脚，由寄存器SCLSEL/SDASEL设置不同的值来选择。
	P31_CFG_I2C_SDA;//P3.1设置为I2C_SDA引脚
	P24_CFG_I2C_SCL;//P2.4设置为I2C_SCL引脚
	SCLSEL =(SCLSEL&0x80)| I2CS_P01_INDEX;			//I2C工作时钟选择系统时钟，I2C_SCL引脚选择P2.4
	SDASEL = I2CS_P31_INDEX;								//I2C_SDA引脚选择P3.1
	
}
////////////////////////////////////////////////////////////////////////////////////////////

#ifdef HAVE_MASTER_IIC
/******************************************************************************
函数名：  I2C_Master_Config
功能描述：I2C做主模式功能初始化
输入参数: 
					i2cadr	 //从设备地址
					i2ccr		//时钟频率 50~100KHZ
					I2C SCL输出时钟频率设置，SCL输出时钟频率为采样频率的(I2CCKD +1)分频，即：
							Fscl= Fsample /(I2CCKD +1))==》Fsample= FOSC 2的smpdiv次幂分频
					1. 当SMPDIV= 0时，如果设置I2CCKD小于9，将自动按9计算。
					2. 当 SMPDIV>0 时，如果设置 I2CCKD 小于 7，将自动按 7 计算。 
					Fscl= Fsample /(I2CCKD +1))==>>Fscl= (FOSC 2的smpdiv次幂分频) /(I2CCKD +1)分频)==》i2ccr=FOSC/i2c_frq-1
返回值： 无					

******************************************************************************/
void I2C_Master_Config(unsigned char i2cadr,unsigned char i2c_frq)
{	
	I2CCON = I2CE(1) | I2CIE(1) | STA(0) | STP(0)| CKHD(1) | AAK(1)| CBSE(0) | STFE(1); 
	//使能 I2C，开启I2C 中断，设置 I2CF 置 1 后拉低 SCL，设置 START 信号产生中断	
	I2CADR = GCE(0)|(i2cadr>>1);//从设备地址
	//I2CCCR = i2ccr;//设置 I2C 时钟
//////////////////////////////////////////////////////////////////////
	I2CCCR=(0x80)|(((((unsigned long int)FOSC/16/(i2c_frq))/1000) -1)&0x1f);
	SCLSEL = I2CKS(0); //I2C 工作时钟选择位 0：系统时钟 1：内部高速时钟
	INT4EN = 1; //使能 INT4 中断
}
/***********************************************************************************
函 数 名：	I2C_Write										 	
功能描述：	I2C 写数据													
输    入：	 DevAdr：从设备地址
			addr： 起始地址
			dat：数组
			len: 数据长度
返    回：	 写入是否成功														
***********************************************************************************/
unsigned char I2C_Write(unsigned char DevAdr,unsigned char addr,unsigned char *dat,unsigned char len)
{
	unsigned  char i;
	iicWriteRead=0;
	iic_txIndex=0;
	I2C_CurrDeviceAddr=DevAdr;
	iic_regAddr = addr; 			//复位数据地址
	iicEnd = 0; 			//结束标志清 0
	iic_txLength = len; 	//设置发送数据长度
	iicWriteNoAck=0;
	for(i=0;i<len;i++)
	{
		iic_TxRXBuf[i]=*dat++;
	}
	I2CCON |= STA(1); //发送 START 信号，启动数据发送
	while(!iicEnd&&!iicWriteNoAck)//; 	//等待数据发送完  
	{
		I2CSTA_STAUST=0;
		iicWriteNoAck=0;
		Delay_ms(10);
	}		
	return iicWriteNoAck; 
}
/***********************************************************************************
函 数 名：	I2C_Read										 	
功能描述：	I2C 读数据													
输    入：	 DevAdr：从设备地址
			addr： 起始地址
			dat：数组
			len: 数据长度							
返    回：	 读取是否成功														
***********************************************************************************/
unsigned char I2C_Read(unsigned char DevAdr,unsigned char addr,unsigned char *dat,unsigned char len)
{
	  unsigned  char i;
		iicWriteRead=1;
	  I2C_CurrDeviceAddr=DevAdr;
	  iic_regAddr = addr; 			//复位数据地址
		iicEnd = 0; //结束标志清 0
		iic_rxLength= len; //设置发送数据长度
	  iicWriteNoAck=0;
		I2CCON |= STA(1); //发送 START 信号，启动 I2C 通信
		while(!iicEnd&&!iicWriteNoAck); 	//等待数据发送完
		//在此处可读取 I2C 接收缓存 rxBuf
		 for(i=0;i<len;i++)
		{
			 *dat++=iic_TxRXBuf[i];
		}
	  return iicWriteNoAck;
}
#endif
///////////////////////////////////////////////////////////////////////////////////
#ifdef HAVE_SLAVE_IIC
/******************************************************************************
函数名：  I2C_Slave_Config
功能描述：I2C做从模式功能初始化
输入参数: 
					i2cadr	 //从设备地址

返回值： 无					

******************************************************************************/
void I2C_Slave_Config(unsigned char i2cadr)
{	
	I2CCON = I2CE(1) | I2CIE(1) | STA(0) | STP(0)| CKHD(1) | AAK(1)| CBSE(0) | STFE(0); 
	//使能 I2C，开启I2C 中断，设置 I2CF 置 1 后拉低 SCL，设置 START 信号产生中断	
	I2CADR = GCE(0)|(i2cadr>>1);//从设备地址
//////////////////////////////////////////////////////////////////////

	I2CCCR = 0x20;
	INT4EN = 1; //使能 INT4 中断
}
#endif
/***********************************************************************************
函 数 名：	I2C_ISR										 	
功能描述：	I2C 中断处理函数													
输    入：	 无								
返    回：	 无														
***********************************************************************************/
void I2C_ISR(void)
{
	unsigned char Sta_Temp;
	///////////////////////主模式中断处理////////////////////////////////////////////
	#ifdef HAVE_MASTER_IIC	
	if(I2CFLG & I2CF) //I2C 中断
	{
			Sta_Temp = I2CSTA; //读取 I2C 状态
			I2CSTA_STAUST=Sta_Temp;
			if(Sta_Temp == 0x08) //START 信号已产生
			{
					if(iicWriteRead && iic_rdSession)
					{
					I2CDAT = I2C_CurrDeviceAddr|1; //读数据阶段，发送从机地址+读位
					}
					else
					{
					I2CDAT = I2C_ADDR; //写数据阶段，发送从机地址+写位
					}
			}
			else if(Sta_Temp == 0x18) //地址+写位已发送，收到从机应答
			{
					I2CDAT = iic_regAddr; //发送数据首地址
					iic_txIndex = 0;
					iicWriteNoAck=0;
			}
			else if(Sta_Temp == 0x20) //地址+写位已发送，没有收到应答信号
			{
					iicWriteNoAck=1;				
			}		
			else if(Sta_Temp == 0x28) //已发送或接收到一字节数据，收到从机应答
			{
				  if(iicWriteRead)
					{
							if(iic_rdSession) //判断是写数据阶段还是读数据阶段
							{
								if(iic_rxIndex >= iic_rxLength) //如果是读数据阶段，判断是否已读取完数据
								{
									I2CCON |= STP(1); //如果已读取完，发送 STOP 信号
									iicEnd = 1; //置位结束标志
								}
								else
								{
									iic_TxRXBuf[iic_rxIndex+iic_regAddr] = I2CDAT; //读取一字节数据
									iic_rxIndex++;
									if(iic_rxIndex <= (iic_rxLength-1))
									{
									I2CCON |= AAK(1); //如果不是最后一字节数据，发送应答信号
									}
									else
									{
									I2CCON &= ~AAK(1);//最后一字节数据发送不应答信号
									} 
								} 
							}						
							else
							{
								I2CCON |= STA(1); //如果是写数据阶段，重新发送 START 信号
								iic_rdSession = 1;
							}
					}
					else
					{
						/////////////////////发送数据//////////////////////////////////
						if(iic_txIndex >= iic_txLength) //判断是否所有数据已发送完
						{
								iicWriteNoAck=0XFF;
								I2CCON |= STP(1); //如果已发送完所有数据则发送 STOP 信号
								iicEnd = 1; //置位结束标志
						}
						else
						{
								I2CDAT = iic_TxRXBuf[iic_txIndex+iic_regAddr]; //如未发送则发送下一字节数据
								iic_txIndex++;
								iicWriteNoAck=iic_txIndex;
						} 
						//iicWriteNoAck=0;
						/////////////////////////////////////////////////////
					} 
			
			}
			else if(Sta_Temp == 0x30) //主机发送/接收一字节数据，没有收到应答信号
			{
				  if(iicWriteRead)
					{
						if(iic_rdSession)
						{
								if(iic_rxIndex >= iic_rxLength) //判断如果是最后一字节数据，则发送 STOP 信号
								{
									I2CCON |= STP(1);
								} 
								iicWriteNoAck=1;
						} 
					}		
					else
					{
								iicWriteNoAck=1;
					}
			}
			else if(Sta_Temp == 0x40) //从机地址+读位已发送，已收到应答信号
			{
				   I2CCON |= AAK(1); //先设置好应答位
				   iic_rxIndex=0;
					 iicWriteNoAck=0;
			}
			else if(Sta_Temp == 0x48) //从机地址+读位已发送，没有收到应答信号
			{
						iicWriteNoAck=1;
			}			
			I2CFLG |= I2CF; //清除 I2C 中断标志
	}
	#else
	///////////////////////从模式中断处理////////////////////////////////////////////
	if(I2CFLG & I2CF)					 		//IIC  interrupt
	{						
		Sta_Temp = I2CSTA;			
		if(Sta_Temp == 0x60)			    	//接收到从机地址+写位
		{			
			I2CDataIndex = 0xFF;				//设置为0xFF表示后面接收到的第一个字节为地址
			iicReadMode = 0;					//设置为从机接收状态
			I2CCON |= AAK(1);			
		}
		else if(Sta_Temp == 0x80)				//发送或接收一字节数据，已检测到应答信号
		{					
			if(iicReadMode)	 					//发送一字节数据
			{
				I2CDataIndex++;
				I2CDAT = iic_TxRXBuf[I2CDataIndex + regAddr];		//把数据装载到发送寄存器，等待主机读取
			}
			else												//接收到一字节数据
			{				
				if(I2CDataIndex == 0xFF) 	//地址
				{
					regAddr = I2CDAT;	 						//接收到的第一个字节认为是地址
			   	I2CDataIndex = 0;								//设置索引值为0
					I2CCON |= AAK(1);
				}
				else				   		//数据
				{
					iic_TxRXBuf[I2CDataIndex + regAddr] = I2CDAT;		//接收到的数据装载到数据寄存器	
					I2CDataIndex++;									//索引值累加
					I2CCON |= AAK(1);		
				}
			}	
		}
		else if(Sta_Temp==0xA8)				//接收到从机地址+读位，发送ACK信号
		{								
			I2CDAT = iic_TxRXBuf[I2CDataIndex + regAddr];	//把数据装载到发送寄存器，等待主机读取
			iicReadMode = 1;							//设置为从机发送状态
		}
		else if(Sta_Temp == 0x88)						//发送或接收一字节数据，已检测到应答信号
		{
		}
		I2CFLG  |= I2CF;					//清除中断标志
	}		
	#endif
}
/***********************************************************************************
函 数 名：	I2C_Init										 	
功能描述：	I2C 初始化													
输    入：	 无								
返    回：	 无														
***********************************************************************************/
void I2C_Init(void)
{
	#ifdef HAVE_MASTER_IIC
	I2C_Master_Config(I2C_ADDR,50);//50~100KHZ 通讯频率 
	#endif
	#ifdef HAVE_SLAVE_IIC
	I2C_Slave_Config(I2C_ADDR);//50~100KHZ 通讯频率 
	#endif	
	
	I2C_SelectComPin();//必须先配置i2c寄存器，再配置管脚
}
/***********************************************************************************/
#endif
#endif

