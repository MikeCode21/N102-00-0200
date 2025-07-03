#ifndef SYSTEM_PROC_C
#define SYSTEM_PROC_C
/*********************************************************************************************************************/
#include "sys_include/sys_includes.h"
#include "user_source/user_includes.h"
/*********************************************************************************************************************/
#ifdef HAVE_TIME0_EN	
/******************************************************************************
��������	every_n_seconds
������������ʱִ�г������ݣ�ʱ������λ������㣩��
�������: 
						second: ��ʱʱ�䣬��λΪ��s

����ֵ��   1 or 0		
���þ����� 1���ȵ���every_n_seconds(0);�ָ���ʼֵ
					 2��if(every_n_seconds(n))
					 {
					     //ÿn����Ҫִ�е�����
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
��������	every_n_milliseconds
������������ʱִ�г������ݣ�ʱ������λ�Ժ�����㣩��
�������: 
						millisecond: ��ʱʱ�䣬��λΪ����s

����ֵ��   1 or 0
���þ����� 1���ȵ���every_n_milliseconds(0);�ָ���ʼֵ
					 2��if(every_n_milliseconds(n))
					 {
					     //ÿn������Ҫִ�е�����

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
��������	get_pin_status
�������������ܽ���������
�������: 
					pin_status:pin��״̬
					pPinSF:�ܽŹ������üĴ�����ַ
					filter: �������� 
����ֵ��  ������ܽ�״̬			
���þ�����
          �ܽ�״̬=get_pin_status(P14,&P14F,15);
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
��������system_powersave_proc
����������ϵͳ˯��ģʽ����ǰ���ùܽ����õ�
�����������
����ֵ�� ��
******************************************************************************/
void System_powersave_proc(void)
{
	/////////////IO ����//////////////////////////
	
	///////////////////////////////////////////
}
/*****************************************************************************
��������Get_system_powersave_exit_proc
�����������Ƿ��˳�ϵͳ˯��ģʽ
�����������
����ֵ�� �Ƿ��˳���0�����˳�  1���˳�ʡ��
******************************************************************************/
u8_t Get_system_powersave_exit_proc(void)
{
  
	return 0;
}
/*****************************************************************************
��������   system_sleep_proc
��������:  ϵͳ˯��ģʽ
��������� ��
����ֵ��   �Ƿ��˳�
��Ҫ������:enter_sleep_enable = 0;
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
�������ƣ� Get_VoltValue                                                                                         
���������� ��ȡ��ѹֵ
��������� val��ADCת����ֵ
					 vref���ο���ѹ(��λmv)��
�� �� ֵ�� ��ѹֵ(��λmv)
***********************************************************************************/
unsigned int Get_VoltValue( unsigned int val,unsigned int vref)
{
    return ((unsigned int)((((unsigned long int)val)*(vref-57)/4095) + 25));
}
/***********************************************************************************
�������ƣ� Get_Mcu_Vdd_Volt									 	
���������� ����AD�ɼ��ڲ�vdd��ѹ��ȡmcu vddֵ
��������� ��
					
����ֵ��   vdd adֵ
***********************************************************************************/
#define ADC_REF_VOLT     (1500*4) //1.5V
unsigned int Get_Mcu_Vdd_Volt(void)
{
	unsigned int bat_advalue,vdd_voltage;
	unsigned char adreg1,adreg2;
	adreg1 = ADCON;adreg2 = ADCFGL;
	ADCON  = AST(0) | ADIE(0) | HTME(7) | ADCALE(1) | VSEL(ADC_REF_INNER);	//����ADC�ο���ѹΪ�ڲ�1.5V
	ADCFGL = ACKD(7);
	bat_advalue = Read_ADC(ADC_VDD,5);
	vdd_voltage = Get_VoltValue(bat_advalue,ADC_REF_VOLT);	
	ADCON = adreg1;ADCFGL= adreg2;
	return vdd_voltage;
}

/***********************************************************************************
�������ƣ� Sys_Check_Parameter_Init									 	
���������� ϵͳ������ʼ��
��������� ��
					
����ֵ��   ��
***********************************************************************************/
void Sys_Check_Parameter_Init(void)
{
	clk_ihcfg = IHCFG;
	adc_adcal = ((unsigned int)ADCALH<<8) | ADCALL;	
}
/***********************************************************************************
�������ƣ� Sys_Cali_Irch_Adcal_Reg									 	
���������� У��IRCH��ADCAL�Ĵ�������
��������� MCU �����ѹ
					
����ֵ��   ��
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
