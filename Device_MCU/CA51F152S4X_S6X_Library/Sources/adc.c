#ifndef _ADC_C_
#define _ADC_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
#ifdef ADC_ENABLE
/*********************************************************************************************************************/
/***********************************************************************************
������:		ADC_Config										 	
����������ADC��������
���������adc_ref 	ADC�ο���ѹ����
					adc_int		ADC�ж�����
����ֵ��  ��
***********************************************************************************/
void ADC_Config(ADC_RefVolt_TypeDef adc_ref,InterruptSW_TypeDef adc_int)							
{
	/**********��ʼ��ADC�Ĵ���������ADCʱ�ӡ�ѡ��ADC�ο���ѹ������ADC�˷š������ڲ�1.5VУ׼ֵ��***********/
	ADCON = AST(0) | ADIE(adc_int) | HTME(7) | ADCALE(1)|VSEL(adc_ref);	
	/**********����ADCͨ����ʱ�ӷ�Ƶ*********************************************************************/
	ADCFGL = ACKD(7) | ADCHS(0);	
	//ADC�ж�����
	if(adc_int == ADC_INT_ENABLE)
	{
		INT2EN = 1; 
	}
}
/***********************************************************************************
������:		ADC_ConfigChannel										 	
��������������ADC����ͨ��
���������channel 	ADCͨ��
����ֵ��  ��
***********************************************************************************/
void ADC_ConfigChannel(ADC_Channel_TypeDef channel)
{
	ADCFGL = (ADCFGL&0xE0) | ADCHS(channel);
}
/***********************************************************************************
������:		ADC_StartConversion										 	
��������������ADCת��
�����������
����ֵ��  ��
***********************************************************************************/
void ADC_StartConversion(void)
{
  ADCON |= AST(1);
}

/***********************************************************************************
������:		GetAdcValue										 	
������������ȡADCת����ֵ
�����������
����ֵ��  ADCֵ
***********************************************************************************/
unsigned int GetAdcValue(void)
{
	unsigned int ADC_Value;

	while(!(ADCON & ADIF));
	ADCON |= ADIF;
	ADC_Value = ADCDH*256 + ADCDL;
	ADC_Value >>= 4;
	return ADC_Value;
}
/***********************************************************************************
������:		GetChannel8BitAdValue										 	
������������ȡADCת����ֵ��8λ
�����������
����ֵ��  ADCֵ
***********************************************************************************/
u8_t GetChannel8BitAdValue(u8_t ch)
{	
	u8_t ADC_Value=0xff;
	if(ch > ADC_VDD) return 0xff;

		ADC_ConfigChannel(ch);	//����ADCͨ��
		ADC_StartConversion();			//����ADCת��
		ADC_Value = GetAdcValue()>>4;	//��ȡADC��ֵ

	return ADC_Value;	
}
/***********************************************************************************
������:		GetChannel12BitAdValue										 	
������������ȡADCת����ֵ��12λ
�����������
����ֵ��  ADCֵ
***********************************************************************************/
u16_t GetChannel12BitAdValue(u8_t ch)
{	
	u16_t ADC_Value=0xffff;
	if(ch > ADC_VDD) return 0xffff;

		ADC_ConfigChannel(ch);	    //����ADCͨ��
		ADC_StartConversion();		//����ADCת��
		ADC_Value = GetAdcValue();	//��ȡADC��ֵ

	return ADC_Value;	
} 
/***********************************************************************************
�������ƣ� ADC_ISR										 	
���������� ADC�жϷ�����
��������� ��
�� �� ֵ�� ��
***********************************************************************************/
#ifdef ADC_SR_ENABLE
bit adc_int_flag = 0;
unsigned int AD_Int_Value;
void ADC_ISR(void)
{
	if(ADCON & ADIF)
	{
		ADCON |= ADIF;										//���ADC�жϱ�־
		AD_Int_Value = ADCDH*256 + ADCDL;						//��ȡADֵ
		AD_Int_Value >>= 4;	

		adc_int_flag = 1;
	}	
}
#endif
/***********************************************************************************
������:		ADC_init									 	
������������ʼ��ADC����
�����������
����ֵ��  ��
***********************************************************************************/

void ADC_init(void)
{
#ifdef ADC_ISR_ENABLE
		ADC_Config(ADC_REF_VDD,ADC_INT_ENABLE);	//ADC��ʼ��
#else
		ADC_Config(ADC_REF_VDD,ADC_INT_DISABLE);	//ADC��ʼ��
#endif
}
/***********************************************************************************
������:		Read_ADC									 	
������������ȡadc ȡƽ��ֵ
���������channel��ADͨ��
					filter����������
����ֵ��  adֵ
***********************************************************************************/
unsigned int Read_ADC(unsigned char channel,unsigned char filter)
{
	unsigned int i,adc_val;
	unsigned long sum = 0;
	unsigned int ad_min,ad_max;
	ad_min = 0xfff;
	ad_max = 0;
	for(i=0; i<filter; i++)
	{
		adc_val=GetChannel12BitAdValue(channel);
		sum += adc_val; 
		if(ad_min > adc_val) ad_min = adc_val;
		if(ad_max < adc_val) ad_max = adc_val;
			_nop_();_nop_();
	}	
	sum -= ad_min+ad_max;
	return (unsigned int)(sum/(filter-2));
}
/*********************************************************************************************************************/
#endif
#endif
