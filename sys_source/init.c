#ifndef INIT_C
#define INIT_C
#include "sys_include/sys_includes.h"
#include "user_source/user_includes.h"
/***********************************************************************************
������  ��		System_parameter_init										 	
����������		ϵͳ������ʼ��
���������		��
����ֵ  ��		��
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
������  ��		Port_IO_Init										 	
����������		IO��ʼ��
���������		��
����ֵ  ��		��
***********************************************************************************/
void Port_IO_Init(void)
{
	MAIN_POWER_OUT;
	MAIN_POWER_OFF;
}
/***********************************************************************************
������  ��		System_parameter_init										 	
����������		ϵͳ������ʼ��
���������		��
����ֵ  ��		��
***********************************************************************************/
void  System_fuction_init(void)
{	
	Port_IO_Init();
	#ifdef  HAVE_MSG
	msg_initial();     			//���밴����Ϣ��ʼ��
	#endif	 
  #ifdef HAVE_CLK_ADCAL_CALI
	Sys_Check_Parameter_Init();//�ڵ�ز�Ʒ����VDD��3.3V����ʱʹ�øù���
	#endif
}
/////////////////////////////////////////////
#endif