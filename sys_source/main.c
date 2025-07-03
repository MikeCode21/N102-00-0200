#ifndef _MAIN_C_
#define _MAIN_C_
/*********************************************************************************************************************/
#include "sys_include/sys_includes.h"
#include "user_source/user_includes.h"
/*********************************************************************************************************************/
/*****************************************************************************
函数名：main
功能描述：系统主函数
输入参数：无
返回值： 无
******************************************************************************/
void main(void)
{	
		System_Init();    			//芯片底层系统初始化
		EA = 1;									//开全局中断	 	 
		System_parameter_init();//系统变量初始化
		System_fuction_init();	//系统函数初始化
	 	user_init();//应用初始化
		while(1)
		{
			#ifdef WATCHDOG_ENABLE
				WDT_FeedDog();			//喂看门狗
			#endif			
			#ifdef  HAVE_MSG
				_get_msg();
			#endif
			#ifdef HAVE_CLK_ADCAL_CALI
      			Sys_Cali_Irch_Adcal_Reg(MCU_VDD_VOLT_3p3V);
			#endif
			////////应用功能处理//////////////
			user_app_proc();	 //	
			//////////////////////////////////
			#ifdef HAVE_SYSTEM_SLEEP
			system_sleep_proc(); 	//系统休眠处理函数
			#endif
		}
}
#endif
