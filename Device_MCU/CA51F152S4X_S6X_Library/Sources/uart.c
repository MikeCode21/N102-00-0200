#ifndef _UART_C_
#define _UART_C_
#include "includes\headfile.h"
#ifdef HAVE_UART
/*********************************************************************************************************************/
//注意： 以下波特率参数对应主时钟为8M，如选择另外的主时钟频率，参数须重新计算。
code unsigned long int BR_TAB[]=
{
	1200,
	2400,
	4800,
	9600,
	19200,
	38400,
	57600,
	115200,
};
#if (SYSCLK_SRC == IRCH_16M)
code unsigned int BR_SET_TAB[][2]=
{
	{606,21},//  1200,
	{303,10},//  2400,
	{303,10}, //  4800,
	{98,16}, //  9600,
	{49,16}, //  19200,
	{13,13},  //  38400,
	{9,30},  //  57600,
	{6,22},  //  115200,
};
#else
//8M 主频
code unsigned int BR_SET_TAB[][2]=
{
	{303,21},//  1200,
	{303,10},//  2400,
	{98,16}, //  4800,
	{49,16}, //  9600,
	{13,31}, //  19200,
	{9,22},  //  38400,
	{6,22},  //  57600,
	{3,22},  //  115200,
};
#endif
/*********************************************************************************************************************/
//注意： 以下波特率参数对应主时钟为24M，如选择另外的主时钟频率，参数须重新计算。
#ifdef UART1_EN
/******************************************************************************
函数名：  Uart1_Initial
功能描述：串口1 初始化
输入参数: baudrate	 	 	 波特率为 CPUCLK/(32 * (1024 - S1REL))
返回值：  无					
******************************************************************************/
void Uart1_Initial(unsigned long int baudrate)
{
	unsigned int value_temp;
  unsigned char i;
	uart1_send.head=0;
	uart1_send.tail=0;
	uart1_rev.head=0;
	uart1_rev.tail=0;
	uart1_tx_flag=0;
	//////////配置UART 1 管脚/////////////////////////////////
	P30_CFG_UART1_TX;
 	P31_CFG_UART1_RX;
	/////////////////////////////////////////////////////////
	for(i=0;i<sizeof(BR_TAB)/4;i++)
	{
		if(baudrate == BR_TAB[i])
		{
			value_temp = 0x400 - BR_SET_TAB[i][0];
			UDCKS1 = 0x80 | BR_SET_TAB[i][1]; 
			break;
		}
	}
	if(i == sizeof(BR_TAB)/4) return;	//如果所设置的波特率不在表格中，可自行添加。
	////////////////////////////////////////////////////////////////////////	
	S1RELH = (unsigned char)(value_temp>>8);
	S1RELL = (unsigned char)(value_temp);
	
	S1CON = 0xD0;
	INT2EN =	1;	
}
/******************************************************************************
函数名：  Uart1_PutChar
功能描述：串口1 输出一个字符
输入参数: bdat	 	 	输出字符
返回值：  无					
******************************************************************************/
void Uart1_PutChar(unsigned char bdat)
{
	unsigned char free_space;
	unsigned char tail_tmp;

	while(1)
	{		
		tail_tmp = uart1_send.tail;
		if(uart1_send.head < tail_tmp)
		{
			free_space = tail_tmp - uart1_send.head;
		}
		else
		{
			free_space = UART1_TX_BUF_SIZE + tail_tmp - uart1_send.head;
		}		
		if(free_space > 1)
		{
			INT2EN = 0; 
			uart1_send.head++;
			uart1_send.head %= UART1_TX_BUF_SIZE;
			uart1_tx_buf[uart1_send.head] = bdat;
			if(!uart1_tx_flag)
			{
				INT2EN = 1;
				uart1_send.tail++;
				uart1_send.tail %= UART1_TX_BUF_SIZE;		
				S1BUF = uart1_tx_buf[uart1_send.tail];				
				uart1_tx_flag = 1;		
			}
			else
			{
				INT2EN = 1;	
			}			
			break;
		}
	}
}
/******************************************************************************
函数名：  Uart1_PutChar
功能描述：串口1 中断处理
输入参数: 无
返回值：  无					
******************************************************************************/
void UART1_ISR_Proc (void) 	
{
	if(S1CON & BIT0)
	{
		S1CON = (S1CON&~(BIT0|BIT1))|BIT0;			 
		uart1_rev.head++;
	 	uart1_rev.head %= UART1_RX_BUF_SIZE;
		uart1_rx_buf[uart1_rev.head]=S1BUF;

	}
	if(S1CON & BIT1)
	{
		S1CON = (S1CON&~(BIT0|BIT1))|BIT1;	
		if(uart1_send.head!=uart1_send.tail)
		{
	
			uart1_send.tail++;
			uart1_send.tail %= UART1_TX_BUF_SIZE;
			S1BUF=uart1_tx_buf[uart1_send.tail];				
		}
		else
		{
			uart1_tx_flag=0;
		}		
	}
}
#endif
#ifdef UART2_EN
/******************************************************************************
函数名：  Uart2_Initial
功能描述：串口2 初始化
输入参数: baudrate	 	 	波特率
返回值：  无					  
					S1REL=0x400-FOC/(DNUM+1)/BAUDRATE
******************************************************************************/
void Uart2_Initial(unsigned long int baudrate)
{
	unsigned int value_temp;
  unsigned char i;
	uart2_send.head=0;
	uart2_send.tail=0;
	uart2_rev.head=0;
	uart2_rev.tail=0;
	uart2_tx_flag=0;

	//////////配置UART 2 管脚/////////////////////////////////
	P00_CFG_UART2_TX;
 	P01_CFG_UART2_RX;
	/////////////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////////////////////
	for(i=0;i<sizeof(BR_TAB)/4;i++)
	{
		if(baudrate == BR_TAB[i])
		{
			value_temp = 0x400 - BR_SET_TAB[i][0];
			UDCKS2 = 0x80 | BR_SET_TAB[i][1]; 
			break;
		}
	}
	if(i == sizeof(BR_TAB)/4) return;	//如果所设置的波特率不在表格中，可自行添加。
	///////////////////////////////////////////////////////////////////////////
	
	S2RELH = (unsigned char)(value_temp>>8);
	S2RELL = (unsigned char)(value_temp);
	
	S2CON = 0xD0;
	INT4EN = 1;	
}
/******************************************************************************
函数名：  Uart2_PutChar
功能描述：串口2 输出一个字符
输入参数: bdat	 	 	输出字符
返回值：  无					
******************************************************************************/
void Uart2_PutChar(unsigned char bdat)
{
	unsigned char free_space;
	unsigned char tail_tmp;
	while(1)
	{		
		tail_tmp = uart2_send.tail;
		if(uart2_send.head < tail_tmp)
		{
			free_space = tail_tmp - uart2_send.head;
		}
		else
		{
			free_space = UART2_TX_BUF_SIZE + tail_tmp - uart2_send.head;
		}		
		if(free_space > 1)
		{
			INT4EN = 0; 
			uart2_send.head++;
			uart2_send.head %= UART2_TX_BUF_SIZE;
			uart2_tx_buf[uart2_send.head] = bdat;			
			if(!uart2_tx_flag)
			{
				INT4EN = 1;
				uart2_send.tail++;
				uart2_send.tail %= UART2_TX_BUF_SIZE;			
				S2BUF = uart2_tx_buf[uart2_send.tail];				
				uart2_tx_flag = 1;		
			}
			else
			{
				INT4EN = 1;	
			}			
			break;
		}
	}
}
/******************************************************************************
函数名：  Uart2_PutChar
功能描述：串口2 中断处理
输入参数: 无
返回值：  无					
******************************************************************************/
void UART2_ISR_Proc (void) 
{
	if(S2CON & BIT0)
	{
		S2CON = (S2CON&~(BIT0|BIT1))|BIT0;			 
		uart2_rev.head++;
		uart2_rev.head %= UART2_RX_BUF_SIZE;
		uart2_rx_buf[uart2_rev.head]=S2BUF;
	}
	if(S2CON & BIT1)
	{
		S2CON = (S2CON&~(BIT0|BIT1))|BIT1;	
		if(uart2_send.head!=uart2_send.tail)
		{
			uart2_send.tail++;
			uart2_send.tail %= UART2_TX_BUF_SIZE;
			S2BUF=uart2_tx_buf[uart2_send.tail];				
		}
		else
		{
			uart2_tx_flag=0;
		}		
	}
}
#endif
void Uart_Initial(void)
{
	#ifdef UART1_EN
		Uart1_Initial(UART1_BAUTRATE);
	#endif
	#ifdef UART2_EN
		Uart2_Initial(UART2_BAUTRATE);
	#endif
}
#endif
/*********************************************************************************************************************/
#endif