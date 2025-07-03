#ifndef _INTERRUPT_C_
#define _INTERRUPT_C_
//////////////////////////////////////////////////////////////////////////////
#include "sys_include/sys_includes.h"
//////////////////////////////////////////////////////////////////////////////
/*****************************************************************************
函数名：EXINT0_ISR
功能描述：EXINT0中断处理
输入参数：无
返回值： 无
******************************************************************************/
void EXINT0_ISR (void) interrupt 0 //using 1
{
	#ifdef HAVE_EXINT0_EN
	//////////////外部中断0处理//////////////
	EXINT0_isr_proc();
	////////////////////////////
	#endif
}
/*****************************************************************************
函数名：EXINT1_ISR
功能描述：EXINT1中断处理
输入参数：无
返回值： 无
******************************************************************************/
void EXINT1_ISR (void) interrupt 2 //using 1
{
	#ifdef HAVE_EXINT1_EN
	//////////////外部中断1处理//////////////
	EXINT1_isr_proc();
	////////////////////////////
	#endif		
}
/*****************************************************************************
函数名：INT2_ISR
功能描述：ADC/模拟比较器/外部中断 2/uart1/pwm/spi
输入参数：无
返回值： 无
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
函数名：INT3_ISR
功能描述：EXINT3中断处理  含UART2_ISR  TS_ISR
输入参数：无
返回值： 无
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
函数名：INT4_ISR
功能描述：EXINT4中断处理  含lvd、wdt i2c uart2
输入参数：无
返回值： 无
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
		// 看门狗中断服务程序
	#ifdef WATCHDOG_ENABLE
			WDT_ISR_proc();
	#endif	
}
#endif
