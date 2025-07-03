#ifndef PWM_H
#define PWM_H

//PWMCON
#define PWMIE(N)			(N<<7)
#define PWMTOG(N)			(N<<6)

//PWMCFG
#define TOG(N)				(N<<7)


#define  PWM0IF		(1<<0)  //PWM0 中断标志位，写 1 清 0
#define  PWM1IF		(1<<1)  //PWM0 中断标志位，写 1 清 0
#define  PWM2IF		(1<<2)  //PWM0 中断标志位，写 1 清 0
#define  PWM3IF		(1<<3)  //PWM0 中断标志位，写 1 清 0

typedef enum {
	PWM_CH0 = 0,
	PWM_CH1 = 1,
	PWM_CH2 = 2,
	PWM_CH3 = 3,	
} PWM_Channel_TypeDef;
typedef enum {
	PWMIE_off = 0,
	PWMIE_on = 1,	
} PWMIE_TypeDef;
typedef enum {
	CKS_SYS=0,
	CKS_IL=1,	
	CKS_IH=2,
	CKS_TKRC=3,	
} PWM_CKS_TypeDef;
typedef enum {
	Toggle_Off = 0,
	Toggle_On = 1,
} PWM_Toggle_TypeDef;
#define PWM_MAX_NUM			4

void PWM_config(PWM_Channel_TypeDef pwm_ch,PWMIE_TypeDef ie,PWM_CKS_TypeDef cks,PWM_Toggle_TypeDef toggle,unsigned char Prescal);
void PWM_CfgDivDuty(PWM_Channel_TypeDef pwm_ch,unsigned int DIV,unsigned int DUT);
void PWM_EnContrl(unsigned char PWMEn_Bits);
void OpenPwm(unsigned char channel);
void ClosePwm(unsigned char channel);
void set_close_pwm_out_value(PWM_Channel_TypeDef pwm_ch,unsigned char value);
void set_open_pwm_out_channel(PWM_Channel_TypeDef pwm_ch);
void PWM_init(void);
void PWM_SetDivDuty(unsigned char channel,unsigned int Tot_value,unsigned int lev);
void PWM_SetFreqDuty(unsigned char channel,unsigned  int pwm_freq_value,unsigned char pwm_duty_value);

#endif