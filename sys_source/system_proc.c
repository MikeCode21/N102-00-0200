#ifndef SYSTEM_PROC_C
#define SYSTEM_PROC_C
/*********************************************************************************************************************/
#include "sys_include/sys_includes.h"
#include "user_source/user_includes.h"
/*********************************************************************************************************************/
#ifdef HAVE_TIME0_EN	
/******************************************************************************
函数名：	every_n_seconds
功能描述：定时执行程序内容（时间间隔单位以秒计算）。
输入参数: 
						second: 定时时间，单位为秒s

返回值：   1 or 0		
调用举例： 1、先调用every_n_seconds(0);恢复起始值
					 2、if(every_n_seconds(n))
					 {
					     //每n秒需要执行的任务
					 }
          
******************************************************************************/
unsigned char every_n_seconds(unsigned char second)
{
	  static unsigned char seccond_timer=0;
		if(second==0)
		{
			 seccond_timer=gp_1second_timer;
		}

		if((unsigned char)(seccond_timer-gp_1second_timer)>=second)
		{
			 seccond_timer=gp_1second_timer;
			 return 1;
		}
		else
			 return 0;


}
/******************************************************************************
函数名：	every_n_milliseconds
功能描述：定时执行程序内容（时间间隔单位以毫秒计算）。
输入参数: 
						millisecond: 定时时间，单位为毫秒s

返回值：   1 or 0
调用举例： 1、先调用every_n_milliseconds(0);恢复起始值
					 2、if(every_n_milliseconds(n))
					 {
					     //每n毫秒需要执行的任务

					 }
******************************************************************************/
unsigned char every_n_milliseconds(unsigned int millisecond)
{
	static unsigned int millisecond_timer=0;
		if(millisecond==0)
		{		
			 millisecond_timer=gp_1ms_timer;
		}

		if((unsigned int)(millisecond_timer-gp_1ms_timer)>=millisecond)
		{
			 millisecond_timer=gp_1ms_timer;
			 return 1;
		}
		else
			 return 0;
}
/******************************************************************************
函数名：	get_pin_status
功能描述：检测管脚消抖功能
输入参数: 
					pin_status:pin脚状态
					pPinSF:管脚功能配置寄存器地址
					filter: 消抖次数 
返回值：  消抖后管脚状态			
调用举例：
          管脚状态=get_pin_status(P14,&P14F,15);
******************************************************************************/
unsigned char get_pin_status(unsigned char pin_status,unsigned char *pPinSF,unsigned char filter)
{	
	  static unsigned char status=0;
		static unsigned char status_cnt=0,status2_cnt=0;
	   *pPinSF=INPUT|PU_EN;		 
	  if(gp_1ms_timer%2==0)
		{			
				if(pin_status)
				{
					   status2_cnt=0;
						if(status_cnt++>filter)
						{
						  status_cnt=0x00;  
							status=1;							

						}
				}
				else 
				{		
					   status_cnt=0;
						if(status2_cnt++>filter)
						{
						  status2_cnt=0x00;  
							status=0;							

						}
				}
					#ifdef DEBUG_PRINTF_EN
						uart_printf("status=%d \n",(int)status); 
					#endif	
		}	 	
		return status;	
}
#endif
#ifdef HAVE_SYSTEM_SLEEP
/*****************************************************************************
函数名：system_powersave_proc
功能描述：系统睡眠模式进入前设置管脚配置等
输入参数：无
返回值： 无
******************************************************************************/
void System_powersave_proc(void)
{
	/////////////IO 配置//////////////////////////
	
	///////////////////////////////////////////
}
/*****************************************************************************
函数名：Get_system_powersave_exit_proc
功能描述：是否退出系统睡眠模式
输入参数：无
返回值： 是否退出：0：不退出  1：退出省电
******************************************************************************/
u8_t Get_system_powersave_exit_proc(void)
{
  
	return 0;
}
/*****************************************************************************
函数名：   system_sleep_proc
功能描述:  系统睡眠模式
输入参数： 无
返回值：   是否退出
需要先设置:enter_sleep_enable = 0;
					:enter_sleep_timer = DEFAULT_SLEEP_TIMER;
******************************************************************************/
void system_sleep_proc(void)
{
	if(enter_sleep_enable&&enter_sleep_timer==0)
	{
#ifdef DEBUG_PRINTF_EN
		uart_printf("SLEEP!\n");
		Delay_ms(10);		
#endif	
		System_powersave_proc();
		System_sleep_enter();
		enter_sleep_enable=0;
		enter_sleep_timer = DEFAULT_SLEEP_TIMER;
#ifdef DEBUG_PRINTF_EN
		uart_printf("SLEEP EXIT!\n");
		Delay_ms(1);				
#endif		
	}
}
#endif
////////////////////////////////////////////////////////////////////////////
#ifdef HAVE_CLK_ADCAL_CALI
unsigned int  xdata adc_adcal = 0;	
unsigned char xdata clk_ihcfg = 0;
/***********************************************************************************
函数名称： Get_VoltValue                                                                                         
功能描述： 获取电压值
输入参数： val：ADC转换数值
					 vref：参考电压(单位mv)，
返 回 值： 电压值(单位mv)
***********************************************************************************/
unsigned int Get_VoltValue( unsigned int val,unsigned int vref)
{
    return ((unsigned int)((((unsigned long int)val)*(vref-57)/4095) + 25));
}
/***********************************************************************************
函数名称： Get_Mcu_Vdd_Volt									 	
功能描述： 利用AD采集内部vdd电压获取mcu vdd值
输入参数： 无
					
返回值：   vdd ad值
***********************************************************************************/
#define ADC_REF_VOLT     (1500*4) //1.5V
unsigned int Get_Mcu_Vdd_Volt(void)
{
	unsigned int bat_advalue,vdd_voltage;
	unsigned char adreg1,adreg2;
	adreg1 = ADCON;adreg2 = ADCFGL;
	ADCON  = AST(0) | ADIE(0) | HTME(7) | ADCALE(1) | VSEL(ADC_REF_INNER);	//设置ADC参考电压为内部1.5V
	ADCFGL = ACKD(7);
	bat_advalue = Read_ADC(ADC_VDD,5);
	vdd_voltage = Get_VoltValue(bat_advalue,ADC_REF_VOLT);	
	ADCON = adreg1;ADCFGL= adreg2;
	return vdd_voltage;
}

/***********************************************************************************
函数名称： Sys_Check_Parameter_Init									 	
功能描述： 系统参数初始化
输入参数： 无
					
返回值：   无
***********************************************************************************/
void Sys_Check_Parameter_Init(void)
{
	clk_ihcfg = IHCFG;
	adc_adcal = ((unsigned int)ADCALH<<8) | ADCALL;	
}
/***********************************************************************************
函数名称： Sys_Cali_Irch_Adcal_Reg									 	
功能描述： 校正IRCH、ADCAL寄存器参数
输入参数： MCU 供电电压
					
返回值：   无
***********************************************************************************/
void Sys_Cali_Irch_Adcal_Reg(unsigned char McuVddVolt)
{
	#define ADC_OFFSET  100
    code unsigned char VOLTAGE_STR[]={52,51,48,46,42,35,22};
	int i;
	unsigned int voltage;	
	unsigned int  reg1 = 0;	
	unsigned char reg2 = 0;
	static unsigned char cali_timer=0;
	if(cali_timer-gp_1second_timer>30)
	{
		cali_timer =gp_1second_timer;
		if(McuVddVolt != MCU_VDD_VOLT_5p0V)
		{
			reg1 = adc_adcal;	
			reg2 = clk_ihcfg;
			voltage = Get_Mcu_Vdd_Volt();
			for(i=0; i<sizeof(VOLTAGE_STR); i++)
			{
				if((voltage) > (VOLTAGE_STR[i]*100))
				{
					reg2 += (i-2); 
					IHCFG = reg2;
					reg1 += (2-i)*ADC_OFFSET;
					ADCALH = reg1>>8;
					ADCALL = reg1&0xff;				
					break;
				}
			}	
		}
 }
}
#endif
////////////////////////////////////////////////////////////////////////////
#endif
