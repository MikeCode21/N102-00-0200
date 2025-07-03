#ifndef _WDT_C_
#define _WDT_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
#ifdef  WATCHDOG_ENABLE
/*********************************************************************************************************************/
/*****************************************************************************
函数名：WDT_Config
功能描述：初始化看门狗
输入参数：wdts		看门狗时钟源设置
					wdre		看门狗模式设置
					wdtch		看门狗时间设置 0.56ms- 36.4s
返回值： 无
******************************************************************************/
void WDT_Config(WDTS_TypeDef wdts,WDRE_TypeDef wdre,unsigned int wdtvh)
{
	WDCON = WDTS(wdts) | WDRE(wdre);
	WDVTHH = (unsigned char)(wdtvh>>8);
	WDVTHL = (unsigned char)(wdtvh);	
	WDFLG = 0xA5; //刷新看门狗
	if(wdre==WDRE_int)	INT4EN = 1;	
}
/*****************************************************************************
函数名：WDT_KILL
功能描述：关闭看门狗
输入参数：无
返回值： 无
******************************************************************************/
void WDT_KILL(void)
{
	WDCON =0;
	WDFLG = 0xA5; //刷新看门狗
}
/*****************************************************************************
函数名：WDT_FeedDog
功能描述：刷新看门狗
输入参数：无
返回值： 无
******************************************************************************/
void WDT_FeedDog(void)
{
	WDFLG = 0xA5;
}
/*********************************************************************************************************************/
/*****************************************************************************
函数名：WDT_init
功能描述：初始化看门狗
输入参数：无
返回值： 无   WDT 触发时间＝ (WDVTH * 800H+7FFH) * clock cycle
			        WDVTH= ((WDT 触发时间)*FOSC-7ffH)/800H
					 WDVTH= ((WDT 触发时间)*IRCL_FOSC/4-7ffH)/800H    
******************************************************************************/
extern unsigned char IRCL_fosc;
#define WDT_TIMMER_MS 				3000//毫秒
#define WDT_TIMMER_WDVTH 		 (((WDT_TIMMER_MS/1000)*(((unsigned long int)IRCL_fosc*1000)/4)-0x7ff)/0X800)
//#define WDT_TIMMER_WDVTH 		 (((WDT_TIMMER_MS/1000)*(FOSC)-0x7ff)/0X800)
void WDT_init(void)
{
	CKCON |= ILCKE;							//使能IRCL
	DelayNop(50);
	WDT_Config(WDTS_IRCL,WDRE_reset,WDT_TIMMER_WDVTH);		 //开启低速IRCL/4看门狗复位 
  //WDT_Config(WDTS_IRCL,WDRE_int,WDT_TIMMER_WDVTH);		 //开启低速IRCL/4看门狗中断 
  //WDT_Config(WDTS_IRCH,WDRE_int,WDT_TIMMER_WDVTH);         //开启高速IRCH看门狗中断 

}
/******************************************************************************
函数名：	WDT_ISR_proc
功能描述：LVD中断服务程序
输入参数: 
返回值： 无					

******************************************************************************/
void WDT_ISR_proc(void)	//LVD中断服务程序
{
	if(WDFLG&0x02)//中断标志
	{
		//看门狗中断服务程序
		WDFLG = 0xA5;//刷新看门狗
	}
	if(WDFLG&0x01)//复位标志
	{
		//看门狗中断服务程序
		WDFLG = 0xA5;//刷新看门狗
	}
}
#endif
#endif
