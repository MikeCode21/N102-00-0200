#ifndef _ADC_C_
#define _ADC_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
#ifdef ADC_ENABLE
/*********************************************************************************************************************/
/***********************************************************************************
函数名:		ADC_Config										 	
功能描述：ADC功能配置
输入参数：adc_ref 	ADC参考电压设置
					adc_int		ADC中断设置
返回值：  无
***********************************************************************************/
void ADC_Config(ADC_RefVolt_TypeDef adc_ref,InterruptSW_TypeDef adc_int)							
{
	/**********初始化ADC寄存器（设置ADC时钟、选择ADC参考电压、设置ADC运放、加载内部1.5V校准值）***********/
	ADCON = AST(0) | ADIE(adc_int) | HTME(7) | ADCALE(1)|VSEL(adc_ref);	
	/**********设置ADC通道和时钟分频*********************************************************************/
	ADCFGL = ACKD(7) | ADCHS(0);	
	//ADC中断设置
	if(adc_int == ADC_INT_ENABLE)
	{
		INT2EN = 1; 
	}
}
/***********************************************************************************
函数名:		ADC_ConfigChannel										 	
功能描述：设置ADC输入通道
输入参数：channel 	ADC通道
返回值：  无
***********************************************************************************/
void ADC_ConfigChannel(ADC_Channel_TypeDef channel)
{
	ADCFGL = (ADCFGL&0xE0) | ADCHS(channel);
}
/***********************************************************************************
函数名:		ADC_StartConversion										 	
功能描述：启动ADC转换
输入参数：无
返回值：  无
***********************************************************************************/
void ADC_StartConversion(void)
{
  ADCON |= AST(1);
}

/***********************************************************************************
函数名:		GetAdcValue										 	
功能描述：获取ADC转换数值
输入参数：无
返回值：  ADC值
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
函数名:		GetChannel8BitAdValue										 	
功能描述：获取ADC转换数值高8位
输入参数：无
返回值：  ADC值
***********************************************************************************/
u8_t GetChannel8BitAdValue(u8_t ch)
{	
	u8_t ADC_Value=0xff;
	if(ch > ADC_VDD) return 0xff;

		ADC_ConfigChannel(ch);	//配置ADC通道
		ADC_StartConversion();			//启动ADC转换
		ADC_Value = GetAdcValue()>>4;	//获取ADC数值

	return ADC_Value;	
}
/***********************************************************************************
函数名:		GetChannel12BitAdValue										 	
功能描述：获取ADC转换数值高12位
输入参数：无
返回值：  ADC值
***********************************************************************************/
u16_t GetChannel12BitAdValue(u8_t ch)
{	
	u16_t ADC_Value=0xffff;
	if(ch > ADC_VDD) return 0xffff;

		ADC_ConfigChannel(ch);	    //配置ADC通道
		ADC_StartConversion();		//启动ADC转换
		ADC_Value = GetAdcValue();	//获取ADC数值

	return ADC_Value;	
} 
/***********************************************************************************
函数名称： ADC_ISR										 	
功能描述： ADC中断服务函数
输入参数： 无
返 回 值： 无
***********************************************************************************/
#ifdef ADC_SR_ENABLE
bit adc_int_flag = 0;
unsigned int AD_Int_Value;
void ADC_ISR(void)
{
	if(ADCON & ADIF)
	{
		ADCON |= ADIF;										//清除ADC中断标志
		AD_Int_Value = ADCDH*256 + ADCDL;						//读取AD值
		AD_Int_Value >>= 4;	

		adc_int_flag = 1;
	}	
}
#endif
/***********************************************************************************
函数名:		ADC_init									 	
功能描述：初始化ADC功能
输入参数：无
返回值：  无
***********************************************************************************/

void ADC_init(void)
{
#ifdef ADC_ISR_ENABLE
		ADC_Config(ADC_REF_VDD,ADC_INT_ENABLE);	//ADC初始化
#else
		ADC_Config(ADC_REF_VDD,ADC_INT_DISABLE);	//ADC初始化
#endif
}
/***********************************************************************************
函数名:		Read_ADC									 	
功能描述：读取adc 取平均值
输入参数：channel：AD通道
					filter：采样次数
返回值：  ad值
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
