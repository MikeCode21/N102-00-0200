#ifndef _INTERRUPT_C_
#define _INTERRUPT_C_
//////////////////////////////////////////////////////////////////////////////
#include "sys_include/sys_includes.h"
//////////////////////////////////////////////////////////////////////////////
/*****************************************************************************
��������EXINT0_ISR
����������EXINT0�жϴ���
�����������
����ֵ�� ��
******************************************************************************/
void EXINT0_ISR (void) interrupt 0 //using 1
{
	#ifdef HAVE_EXINT0_EN
	//////////////�ⲿ�ж�0����//////////////
	EXINT0_isr_proc();
	////////////////////////////
	#endif
}
/*****************************************************************************
��������EXINT1_ISR
����������EXINT1�жϴ���
�����������
����ֵ�� ��
******************************************************************************/
void EXINT1_ISR (void) interrupt 2 //using 1
{
	#ifdef HAVE_EXINT1_EN
	//////////////�ⲿ�ж�1����//////////////
	EXINT1_isr_proc();
	////////////////////////////
	#endif		
}
/*****************************************************************************
��������INT2_ISR
����������ADC/ģ��Ƚ���/�ⲿ�ж� 2/uart1/pwm/spi
�����������
����ֵ�� ��
******************************************************************************/
void INT2_ISR (void) interrupt 4 //using 1	
{
	#ifdef UART1_EN
	UART1_ISR_Proc();
	#endif
	#ifdef SPI_ENABLE
	SPI_ISR_proc();
	#endif
	#ifdef HAVE_EXINT2_EN
	if(EPIF & BIT0)
	{
		EPIF = BIT0;
		EXINT2_isr_proc();
	}
	#endif
	#ifdef PWM_ISR_ENABLE	
	 pwm_isr_proc();
	#endif	
	#ifdef ADC_ENABLE
	  #ifdef ADC_SR_ENABLE
			ADC_ISR();
	  #endif
	#endif
}
/*****************************************************************************
��������INT3_ISR
����������EXINT3�жϴ���  ��UART2_ISR  TS_ISR
�����������
����ֵ�� ��
******************************************************************************/
//UART2//External interrupt 3
void INT3_ISR (void) interrupt 5 //using 1		 
{
	#ifdef  HAVE_TIME2_EN
  Timer2_isr();
	#endif
	#ifdef CA_TOUCH_KEY
		TS_ISR();
	#endif
	/////////////////////////////////////
	#ifdef HAVE_TMC_TIME_EN
	TMC_timer_isr_proc();
	#endif
	#ifdef HAVE_EXINT3_EN
	if(EPIF & BIT1)
	{
		EPIF = BIT1;	
		EXINT3_isr_proc();
	}
	#endif
}
/*****************************************************************************
��������INT4_ISR
����������EXINT4�жϴ���  ��lvd��wdt i2c uart2
�����������
����ֵ�� ��
******************************************************************************/

//External interrupt 4
void INT4_ISR (void) interrupt 6		 
{
	// clear interrupt in 8051
	#ifdef UART2_EN
	UART2_ISR_Proc();
	#endif
	#ifdef LVD_ENABLE
	LVD_ISR_proc();
	#endif
	#ifdef HAVE_EXINT4_EN
	if(EPIF & BIT2)
	{
		EPIF = BIT2;
		EXINT4_isr_proc();	
	}	
	#endif
	#ifdef HAVE_TOUCH_KEY	
	#if TS_I2C_DEBUG	  
			I2C_ISR();
	#endif
	#else
	#ifdef I2C_ENABLE
		I2C_ISR();
	#endif
	#endif
		// ���Ź��жϷ������
	#ifdef WATCHDOG_ENABLE
			WDT_ISR_proc();
	#endif	
}
#endif
