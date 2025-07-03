#ifndef _UART_DEBUG_C
#define _UART_DEBUG_C
/***************************************************************************************/
#include "sys_include/sys_includes.h"
#include "user_source/user_includes.h"
#include < stdlib.h>
/***************************************************************************************/
#ifdef UART1_EN
/*****************************************************************************
函数名：_uart1_send_byte
功能描述：串口1发送一个数据
输入参数：bdat
返回值： 无
******************************************************************************/
void _uart1_send_byte(u8_t bdat)
{
	Uart1_PutChar(bdat);
}
/*****************************************************************************
函数名：_uart1_send_string
功能描述：串口1发送字符串
输入参数：bytes：字符长度
					string：字符串数组
返回值： 无
******************************************************************************/
void _uart1_send_string(u8_t *string,u8_t bytes)
{
	u8_t i;
	for(i=0;i<bytes;i++)
	{
		_uart1_send_byte(*string++);	
	}
}
/*****************************************************************************
函数名：_uart1_get_byte
功能描述：串口1接收数据
输入参数：pdat：接收数据放入字符数组指针

返回值： 1：接收成功 0：无数据接收
******************************************************************************/
bit _uart1_get_byte(u8_t *pdat)
{
	if(uart1_rev.head!=uart1_rev.tail)
	{
		if(uart1_rev.tail==UART1_RX_BUF_SIZE-1)
		{
			uart1_rev.tail=0;
		}
		else
		{
			uart1_rev.tail++;
		}		
		*pdat=uart1_rx_buf[uart1_rev.tail];
		return 1;
	}
	return 0;
}
#endif
#ifdef UART2_EN
/*****************************************************************************
函数名：_uart2_send_byte
功能描述：串口2发送一个数据
输入参数：bdat
返回值： 无
******************************************************************************/
void _uart2_send_byte(u8_t bdat)
{
	Uart2_PutChar(bdat);	
}
/*****************************************************************************
函数名：_uart2_send_string
功能描述：串口2发送字符串
输入参数：bytes：字符长度
					string：字符串数组
返回值： 无
******************************************************************************/
 void _uart2_send_string(u8_t *string,u8_t bytes)
{
	u8_t i;
	for(i=0;i<bytes;i++)
	{
		_uart2_send_byte(*string++);	
	}
} 
/*****************************************************************************
函数名：_uart2_get_byte
功能描述：串口2接收数据
输入参数：pdat：接收数据放入字符数组指针

返回值： 1：接收成功 0：无数据接收
******************************************************************************/
 bit _uart2_get_byte(u8_t *pdat)
{
	if(uart2_rev.head!=uart2_rev.tail)
	{
		if(uart2_rev.tail==UART2_RX_BUF_SIZE-1)
		{
			uart2_rev.tail=0;
		}
		else
		{
			uart2_rev.tail++;
		}		
		*pdat=uart2_rx_buf[uart2_rev.tail];
		return 1;
	}
	return 0;
} 
#endif

#ifdef DEBUG_PRINTF_EN
/*****************************************************************************
函数名：PutStr
功能描述：串口调试打印字符串
输入参数：str：字符数组指针

返回值：无
******************************************************************************/
//uart_printf("\n func_mode=%x\r\n",func_mode);打印变量的格式
void PutStr(unsigned char *str)
{
	while(*str)
	{
		///////////////////////////////////////
		#ifdef USE_UART1_DEBUGGING
		Uart1_PutChar(*str++);
		#endif
		#ifdef USE_UART2_DEBUGGING
		Uart2_PutChar(*str++);
		#endif				
	}
}
/*****************************************************************************
函数名：uart_printf
功能描述：串口调试格式化打印字符
输入参数：fmt：字符输入

返回值：无
******************************************************************************/
void uart_printf(char *fmt,...) 
{
    va_list xdata ap;
    char xdata string[100];
    va_start(ap,fmt);
    vsprintf(string,fmt,ap);
    PutStr(string);
    va_end(ap);
}
#endif
#endif