#ifndef INIT_C
#define INIT_C
#include "sys_include/sys_includes.h"
#include "user_source/user_includes.h"
/***********************************************************************************
函数名  ：		System_parameter_init										 	
功能描述：		系统变量初始化
输入参数：		无
返回值  ：		无
***********************************************************************************/
void System_parameter_init(void)
{
   func_mode= MODE_STANDBY;
	 sub_state=SUB_STATE_NORMAL;
#ifdef HAVE_SYSTEM_SLEEP
   enter_sleep_enable=0;
   enter_sleep_timer = DEFAULT_SLEEP_TIMER;
#endif

}
/***********************************************************************************
函数名  ：		Port_IO_Init										 	
功能描述：		IO初始化
输入参数：		无
返回值  ：		无
***********************************************************************************/
void Port_IO_Init(void)
{
	MAIN_POWER_OUT;
	MAIN_POWER_OFF;
}
/***********************************************************************************
函数名  ：		System_parameter_init										 	
功能描述：		系统函数初始化
输入参数：		无
返回值  ：		无
***********************************************************************************/
void  System_fuction_init(void)
{	
	Port_IO_Init();
	#ifdef  HAVE_MSG
	msg_initial();     			//输入按键消息初始化
	#endif	 
  #ifdef HAVE_CLK_ADCAL_CALI
	Sys_Check_Parameter_Init();//在电池产品或是VDD在3.3V供电时使用该功能
	#endif
}
/////////////////////////////////////////////
#endif