#ifndef _PWM_C_
#define _PWM_C_

/*********************************************************************************************************************/
#include "includes\headfile.h"
#ifdef PWM_ENABLE
#if (SYSCLK_SRC == IRCH_16M)
	#define PWM_FOSC	(16000000) //pwm时钟
#else
	#define PWM_FOSC	(8000000) //pwm时钟
#endif
////////////////////////////////选择 PWM 口及设置管脚////////////////////////////////////////////////
#define PWM0_ENABLE
#define PWM1_ENABLE
#define PWM2_ENABLE
#define PWM3_ENABLE
/*********************************************************************************************************************
	CA51F152系列芯片最多支持4路PWM输出,每路可单独控制,在16位范围内可任意配置周期和占空比,每路PWM输出引脚可映射至不同的GPIO引脚.
	
//PWM0可映射至的引脚
	P00F = P00_PWM0_SETTING;
	P04F = P04_PWM0_SETTING;
	P10F = P10_PWM0_SETTING;
	P14F = P14_PWM0_SETTING;
	P20F = P20_PWM0_SETTING;
	P24F = P24_PWM0_SETTING;
	P30F = P30_PWM0_SETTING;
	
//PWM1可映射至的引脚	
	P01F = P01_PWM1_SETTING;
	P05F = P05_PWM1_SETTING;
	P11F = P11_PWM1_SETTING;
	P15F = P15_PWM1_SETTING;
	P21F = P21_PWM1_SETTING;
	P25F = P25_PWM1_SETTING;
	P31F = P31_PWM1_SETTING;
	
//PWM2可映射至的引脚	
	P02F = P02_PWM2_SETTING;
	P06F = P06_PWM2_SETTING;
	P12F = P12_PWM2_SETTING;
	P16F = P16_PWM2_SETTING;
	P22F = P22_PWM2_SETTING;
	P26F = P26_PWM2_SETTING;

//PWM3可映射至的引脚	
	P03F = P03_PWM3_SETTING;
	P07F = P07_PWM3_SETTING;
	P13F = P13_PWM3_SETTING;
	P17F = P17_PWM3_SETTING;
	P23F = P23_PWM3_SETTING;
	P27F = P27_PWM3_SETTING;
**********************************************************************************************************************/
/////////////////////////////////配置PWM 0 管脚/////////////////////////////////////////
#ifdef PWM0_ENABLE
	#define  PWM0_SET_PWM                        			 P10_CFG_PWM0
	#define  PWM0_SET_IO(n)                        		{P10_CFG_OUTPUT_PULL_NO;P10=(n);}
#endif
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////配置PWM 1 管脚/////////////////////////////////////////
#ifdef PWM1_ENABLE
	#define  PWM1_SET_PWM                        			 P11_CFG_PWM1
	#define  PWM1_SET_IO(n)                        		{P11_CFG_OUTPUT_PULL_NO;P11=(n);}
#endif
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////配置PWM 2 管脚/////////////////////////////////////////
#ifdef PWM2_ENABLE
	#define  PWM2_SET_PWM                        			 P12_CFG_PWM2
	#define  PWM2_SET_IO(n)                        		{P12_CFG_OUTPUT_PULL_NO;P12=(n);}
#endif
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////配置PWM 3 管脚/////////////////////////////////////////
#ifdef PWM3_ENABLE
	#define  PWM3_SET_PWM                        			 P13_CFG_PWM3
	#define  PWM3_SET_IO(n)                        		{P13_CFG_OUTPUT_PULL_NO;P13=(n);}
#endif
//////////////////////////////////////////////////////////////////////////////////////////

/******************************************************************************
函数名：  set_open_pwm_out_channel
功能描述：设置PWM管脚为PWM功能
输入参数: pwm_ch		PWM通道选择
返回值：  无					
******************************************************************************/
void set_open_pwm_out_channel(PWM_Channel_TypeDef pwm_ch)
{
  #ifdef PWM0_ENABLE
	if(pwm_ch==0) {PWM0_SET_PWM;}  		
	#endif
	#ifdef PWM1_ENABLE
	if(pwm_ch==1) {PWM1_SET_PWM;}  		
	#endif
	#ifdef PWM2_ENABLE
	if(pwm_ch==2) {PWM2_SET_PWM;}  		
	#endif
	#ifdef PWM3_ENABLE
	if(pwm_ch==3) {PWM3_SET_PWM;}  		
	#endif
}
/******************************************************************************
函数名：  set_close_pwm_out_value
功能描述：设置PWM管脚为关闭pwm功能，输出高低电平
输入参数: pwm_ch		PWM通道选择
返回值：  无					
******************************************************************************/
void set_close_pwm_out_value(PWM_Channel_TypeDef pwm_ch,unsigned char value)
{
 #ifdef PWM0_ENABLE
	if(pwm_ch==0) {PWM0_SET_IO(value);} 		
	#endif
	#ifdef PWM1_ENABLE
	if(pwm_ch==1) {PWM1_SET_IO(value);} 		
	#endif
	#ifdef PWM2_ENABLE
	if(pwm_ch==2) {PWM2_SET_IO(value);} 				
	#endif
	#ifdef PWM3_ENABLE
	if(pwm_ch==3) {PWM3_SET_IO(value);} 		
	#endif 
}
/////////////////////////////////////////////////////////////////////////////////////
/*********************************************************************************************************************/

/******************************************************************************
函数名：PWM_config
功能描述：PWM通道功能初始化
输入参数: 
					pwm_ch		PWM通道选择
					ie				PWM中断开关设置
					cks				PWM时钟源设置        
					toggle		PWM是否反相输出设置
					Prescal		PWM时钟分频设置				
返回值： 无	
           PWM0 可选择IRCH、IRCL、TKRC为时钟源。
					 PWM1/PWM2/PWM3 只可选择IRCH、IRCL为时钟源。
******************************************************************************/
void PWM_config(PWM_Channel_TypeDef pwm_ch,
								PWMIE_TypeDef ie,
								PWM_CKS_TypeDef cks,
								PWM_Toggle_TypeDef toggle,
								unsigned char Prescal)
{
	  INDEX = pwm_ch;
		PWMCON = PWMIE(ie) | PWMTOG(toggle) | cks;
		PWMCKD = Prescal;	
	  #ifdef PWM_ISR_ENABLE
	  INT2EN = 1;	
		#endif

}
/******************************************************************************
函数名：  PWM_CfgDivDuty
功能描述：设置PWM周期和占空比
输入参数: pwm_ch		PWM通道选择
					DIV		   PWM周期设置
					DUT		   PWM占空比设置
返回值：  无					
******************************************************************************/
void PWM_CfgDivDuty(PWM_Channel_TypeDef pwm_ch,unsigned int DIV,unsigned int DUT)
{
	INDEX = pwm_ch;
	PWMDIVH	= (unsigned char)(DIV>>8);
	PWMDIVL	= (unsigned char)(DIV);
	PWMDUTH	= (unsigned char)(DUT>>8);
	PWMDUTL	= (unsigned char)(DUT);	
}
/******************************************************************************
函数名：	PWM_EnContrl
功能描述：PWM使能
输入参数: PWMEn_Bits	，每一位对应PWM的一个通道
返回值：  无					
******************************************************************************/
void PWM_EnContrl(unsigned char PWMEn_Bits)
{
	PWMEN = PWMEn_Bits;
}
/******************************************************************************
函数名：  OpenPwm
功能描述：PWM打开
输入参数: channel	
返回值：  无					
******************************************************************************/
void OpenPwm(unsigned char channel) 
{
	if(channel>(PWM_MAX_NUM-1))return;
    	set_open_pwm_out_channel(channel);
	PWMEN |=(0x01<<channel);   						//enable channel   bit: 0~7   channel:0~7
}
/******************************************************************************
函数名：  ClosePwm
功能描述：PWM关闭
输入参数: channel	
返回值：  无					
******************************************************************************/
void ClosePwm(unsigned char channel) 
{
	if(channel>(PWM_MAX_NUM-1))return;
	PWMEN &=(~(0x01<<channel));
	set_close_pwm_out_value(channel,0);
}

/******************************************************************************
函数名：  PWM_init
功能描述：PWM初始化
输入参数: channel	 pwm 通道
		 cks 		PWM 时钟
返回值：  无					
******************************************************************************/
void PWM_init(void)
{
    PWM_config(PWM_CH0,0,CKS_SYS,0,0);	// 系统时钟，不反相,不分频，
	  PWM_config(PWM_CH1,0,CKS_SYS,0,0);	// 系统时钟，不反相,不分频，
	  PWM_config(PWM_CH2,0,CKS_SYS,0,0);	// 系统时钟，不反相,不分频，
	  PWM_config(PWM_CH3,0,CKS_SYS,0,0);	// 系统时钟，不反相,不分频，
}
/******************************************************************************
函数名：  PWM_SetDivDuty
功能描述：PWM设置频率和占空比  可以输出56HZ~1.85MHZ
输入参数: channel	 	 pwm 通道
		 Tot_value 		PWM 周期设置   
		 lev			PWM 占空比设置		 
返回值：  无					
******************************************************************************/
void PWM_SetDivDuty(unsigned char channel,unsigned int Tot_value,unsigned int lev)
{
	if(lev>=Tot_value||lev==0)
	{
		PWMEN &=(~(0x01<<channel));
		if(lev)
		{
			set_close_pwm_out_value(channel,1);
		}
		else
		{

			set_close_pwm_out_value(channel,0);
		}
	}
	else
	{
		set_open_pwm_out_channel(channel);
		PWM_CfgDivDuty(channel,Tot_value,lev);	
		OpenPwm(channel); //PWM 使能
	}
}
/******************************************************************************
函数名：  PWM_SetFreqDut
功能描述：PWM设置频率和占空比
输入参数: channel	 	 		 pwm 通道
		 pwm_freq_value 		PWM 输出频率范围: 57hz  ~65535hz  如果需要改更高频率，需要定义U32_T 变量
		 pwm_duty_value			PWM 占空比  0~255
返回值：  无					
******************************************************************************/
void PWM_SetFreqDuty(unsigned char channel,unsigned  int pwm_freq_value,unsigned char pwm_duty_value)
{   
	unsigned int duty;
	if(pwm_duty_value==0||pwm_duty_value==255)
	{
		PWMEN &=(~(0x01<<channel));
		if(pwm_duty_value)
		{
			set_close_pwm_out_value(channel,1);
		}
		else
		{
			set_close_pwm_out_value(channel,0);
		}
	}
	else
	{
		set_open_pwm_out_channel(channel);
		duty = ((u32_t)(PWM_FOSC/pwm_freq_value)*(u32_t)pwm_duty_value)/255;
		PWM_CfgDivDuty(channel,PWM_FOSC/pwm_freq_value,duty);	
		OpenPwm(channel); //PWM 使能
	}
}
#endif
#endif
