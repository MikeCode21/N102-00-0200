#ifndef _Delay_C_
#define _Delay_C_
#include "includes\headfile.h"
/***************************延时功能函数*******************************/
/******************************************************************************
函数名：  Delay_50us
功能描述：50us 延时
输入参数: n	 	 
返回值：  无					
******************************************************************************/
void Delay_50us(unsigned int n)	   
{
	unsigned char i;	
#if (SYSCLK_SRC == IRCH_16M)
	n *= 2;
#endif
	while(n--)
	{
		for(i=0;i<35;i++);//33
	}
}
/******************************************************************************
函数名：  Delay_ms
功能描述：1ms 延时
输入参数: n	 	 
返回值：  无					
******************************************************************************/
void Delay_ms(unsigned int n)
{
	while(n--)
	{
		Delay_50us(20);
	}
}
/********************************************************************/
#endif
