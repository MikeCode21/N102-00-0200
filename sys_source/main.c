#ifndef _MAIN_C_
#define _MAIN_C_
/*********************************************************************************************************************/
#include "sys_include/sys_includes.h"
#include "user_source/user_includes.h"
/*********************************************************************************************************************/
/*****************************************************************************
��������main
����������ϵͳ������
�����������
����ֵ�� ��
******************************************************************************/
void main(void)
{	
		System_Init();    			//оƬ�ײ�ϵͳ��ʼ��
		EA = 1;									//��ȫ���ж�	 	 
		System_parameter_init();//ϵͳ������ʼ��
		System_fuction_init();	//ϵͳ������ʼ��
	 	user_init();//Ӧ�ó�ʼ��
		while(1)
		{
			#ifdef WATCHDOG_ENABLE
				WDT_FeedDog();			//ι���Ź�
			#endif			
			#ifdef  HAVE_MSG
				_get_msg();
			#endif
			#ifdef HAVE_CLK_ADCAL_CALI
      			Sys_Cali_Irch_Adcal_Reg(MCU_VDD_VOLT_3p3V);
			#endif
			////////Ӧ�ù��ܴ���//////////////
			user_app_proc();	 //	
			//////////////////////////////////
			#ifdef HAVE_SYSTEM_SLEEP
			system_sleep_proc(); 	//ϵͳ���ߴ�����
			#endif
		}
}
#endif
