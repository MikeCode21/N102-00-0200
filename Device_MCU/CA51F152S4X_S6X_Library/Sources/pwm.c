#ifndef _PWM_C_
#define _PWM_C_

/*********************************************************************************************************************/
#include "includes\headfile.h"
#ifdef PWM_ENABLE
#if (SYSCLK_SRC == IRCH_16M)
	#define PWM_FOSC	(16000000) //pwmʱ��
#else
	#define PWM_FOSC	(8000000) //pwmʱ��
#endif
////////////////////////////////ѡ�� PWM �ڼ����ùܽ�////////////////////////////////////////////////
#define PWM0_ENABLE
#define PWM1_ENABLE
#define PWM2_ENABLE
#define PWM3_ENABLE
/*********************************************************************************************************************
	CA51F152ϵ��оƬ���֧��4·PWM���,ÿ·�ɵ�������,��16λ��Χ�ڿ������������ں�ռ�ձ�,ÿ·PWM������ſ�ӳ������ͬ��GPIO����.
	
//PWM0��ӳ����������
	P00F = P00_PWM0_SETTING;
	P04F = P04_PWM0_SETTING;
	P10F = P10_PWM0_SETTING;
	P14F = P14_PWM0_SETTING;
	P20F = P20_PWM0_SETTING;
	P24F = P24_PWM0_SETTING;
	P30F = P30_PWM0_SETTING;
	
//PWM1��ӳ����������	
	P01F = P01_PWM1_SETTING;
	P05F = P05_PWM1_SETTING;
	P11F = P11_PWM1_SETTING;
	P15F = P15_PWM1_SETTING;
	P21F = P21_PWM1_SETTING;
	P25F = P25_PWM1_SETTING;
	P31F = P31_PWM1_SETTING;
	
//PWM2��ӳ����������	
	P02F = P02_PWM2_SETTING;
	P06F = P06_PWM2_SETTING;
	P12F = P12_PWM2_SETTING;
	P16F = P16_PWM2_SETTING;
	P22F = P22_PWM2_SETTING;
	P26F = P26_PWM2_SETTING;

//PWM3��ӳ����������	
	P03F = P03_PWM3_SETTING;
	P07F = P07_PWM3_SETTING;
	P13F = P13_PWM3_SETTING;
	P17F = P17_PWM3_SETTING;
	P23F = P23_PWM3_SETTING;
	P27F = P27_PWM3_SETTING;
**********************************************************************************************************************/
/////////////////////////////////����PWM 0 �ܽ�/////////////////////////////////////////
#ifdef PWM0_ENABLE
	#define  PWM0_SET_PWM                        			 P10_CFG_PWM0
	#define  PWM0_SET_IO(n)                        		{P10_CFG_OUTPUT_PULL_NO;P10=(n);}
#endif
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////����PWM 1 �ܽ�/////////////////////////////////////////
#ifdef PWM1_ENABLE
	#define  PWM1_SET_PWM                        			 P11_CFG_PWM1
	#define  PWM1_SET_IO(n)                        		{P11_CFG_OUTPUT_PULL_NO;P11=(n);}
#endif
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////����PWM 2 �ܽ�/////////////////////////////////////////
#ifdef PWM2_ENABLE
	#define  PWM2_SET_PWM                        			 P12_CFG_PWM2
	#define  PWM2_SET_IO(n)                        		{P12_CFG_OUTPUT_PULL_NO;P12=(n);}
#endif
//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////����PWM 3 �ܽ�/////////////////////////////////////////
#ifdef PWM3_ENABLE
	#define  PWM3_SET_PWM                        			 P13_CFG_PWM3
	#define  PWM3_SET_IO(n)                        		{P13_CFG_OUTPUT_PULL_NO;P13=(n);}
#endif
//////////////////////////////////////////////////////////////////////////////////////////

/******************************************************************************
��������  set_open_pwm_out_channel
��������������PWM�ܽ�ΪPWM����
�������: pwm_ch		PWMͨ��ѡ��
����ֵ��  ��					
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
��������  set_close_pwm_out_value
��������������PWM�ܽ�Ϊ�ر�pwm���ܣ�����ߵ͵�ƽ
�������: pwm_ch		PWMͨ��ѡ��
����ֵ��  ��					
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
��������PWM_config
����������PWMͨ�����ܳ�ʼ��
�������: 
					pwm_ch		PWMͨ��ѡ��
					ie				PWM�жϿ�������
					cks				PWMʱ��Դ����        
					toggle		PWM�Ƿ����������
					Prescal		PWMʱ�ӷ�Ƶ����				
����ֵ�� ��	
           PWM0 ��ѡ��IRCH��IRCL��TKRCΪʱ��Դ��
					 PWM1/PWM2/PWM3 ֻ��ѡ��IRCH��IRCLΪʱ��Դ��
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
��������  PWM_CfgDivDuty
��������������PWM���ں�ռ�ձ�
�������: pwm_ch		PWMͨ��ѡ��
					DIV		   PWM��������
					DUT		   PWMռ�ձ�����
����ֵ��  ��					
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
��������	PWM_EnContrl
����������PWMʹ��
�������: PWMEn_Bits	��ÿһλ��ӦPWM��һ��ͨ��
����ֵ��  ��					
******************************************************************************/
void PWM_EnContrl(unsigned char PWMEn_Bits)
{
	PWMEN = PWMEn_Bits;
}
/******************************************************************************
��������  OpenPwm
����������PWM��
�������: channel	
����ֵ��  ��					
******************************************************************************/
void OpenPwm(unsigned char channel) 
{
	if(channel>(PWM_MAX_NUM-1))return;
    	set_open_pwm_out_channel(channel);
	PWMEN |=(0x01<<channel);   						//enable channel   bit: 0~7   channel:0~7
}
/******************************************************************************
��������  ClosePwm
����������PWM�ر�
�������: channel	
����ֵ��  ��					
******************************************************************************/
void ClosePwm(unsigned char channel) 
{
	if(channel>(PWM_MAX_NUM-1))return;
	PWMEN &=(~(0x01<<channel));
	set_close_pwm_out_value(channel,0);
}

/******************************************************************************
��������  PWM_init
����������PWM��ʼ��
�������: channel	 pwm ͨ��
		 cks 		PWM ʱ��
����ֵ��  ��					
******************************************************************************/
void PWM_init(void)
{
    PWM_config(PWM_CH0,0,CKS_SYS,0,0);	// ϵͳʱ�ӣ�������,����Ƶ��
	  PWM_config(PWM_CH1,0,CKS_SYS,0,0);	// ϵͳʱ�ӣ�������,����Ƶ��
	  PWM_config(PWM_CH2,0,CKS_SYS,0,0);	// ϵͳʱ�ӣ�������,����Ƶ��
	  PWM_config(PWM_CH3,0,CKS_SYS,0,0);	// ϵͳʱ�ӣ�������,����Ƶ��
}
/******************************************************************************
��������  PWM_SetDivDuty
����������PWM����Ƶ�ʺ�ռ�ձ�  �������56HZ~1.85MHZ
�������: channel	 	 pwm ͨ��
		 Tot_value 		PWM ��������   
		 lev			PWM ռ�ձ�����		 
����ֵ��  ��					
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
		OpenPwm(channel); //PWM ʹ��
	}
}
/******************************************************************************
��������  PWM_SetFreqDut
����������PWM����Ƶ�ʺ�ռ�ձ�
�������: channel	 	 		 pwm ͨ��
		 pwm_freq_value 		PWM ���Ƶ�ʷ�Χ: 57hz  ~65535hz  �����Ҫ�ĸ���Ƶ�ʣ���Ҫ����U32_T ����
		 pwm_duty_value			PWM ռ�ձ�  0~255
����ֵ��  ��					
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
		OpenPwm(channel); //PWM ʹ��
	}
}
#endif
#endif
