#ifndef ADC_H
#define ADC_H

//ADCON定义
#define AST(N)		(N<<7)					//ADC启动 ， AST=0结束
#define ADIE(N)		(N<<6)					//中断使能
#define ADIF			(1<<5)					 	//中断标志
#define HTME(N) 	(N<<2)					//N=0-7			 //采样时间设置, 时间为2的HTME次方的时钟周期
#define ADCALE(N) (N<<1)			//N=0-1，ADC校准使能位，1有效
#define VSEL(N) 	(N)							//N=0-3			 //选择参考电压 0-内部 1-VDD 2-外部

//ADCFGL定义													   
#define ACKD(N)			(N<<5)  			//N=0-7			 //ADC时钟分频	  分频倍数=（ACKD+1)
#define ADCHS(N)		(N) 					//N=0-15		 //ADC通道选择 ， 1-13对应通道0-12

typedef enum {
  ADC_REF_INNER  	= 0,//内部参考
  ADC_REF_VDD  		= 1,//VDD 参考
} ADC_RefVolt_TypeDef;

typedef enum {
ADC_CH0  		= 1,
	ADC_CH1  		= 2,
	ADC_CH2  		= 3,
	ADC_CH3  		= 4,
	ADC_CH4  		= 5,
	ADC_CH5  		= 6,
	ADC_CH6  		= 7,
	ADC_CH7  		= 8,
	ADC_CH8  		= 9,
	ADC_CH9  		= 10,
	ADC_CH10  		= 11,
	ADC_CH11  		= 12,		
	ADC_CH12  		= 13,
	ADC_CH13  		= 14,
	ADC_CH14  		= 15,
	ADC_CH15  		= 16,
	ADC_CH16  		= 17,
	ADC_CH17  		= 18,
	ADC_CH18  		= 19,
	ADC_CH19  		= 20,
	ADC_CH20  		= 21,
	ADC_CH21  		= 22,
	ADC_CH22  		= 23,
	ADC_CH23  		= 24,
	ADC_CH24  		= 25,
	ADC_CH25 		= 26,		
	ADC_VDD  		= 27,
} ADC_Channel_TypeDef;

typedef enum {
  ADC_INT_DISABLE = 0,//adc 中断关闭
  ADC_INT_ENABLE  = 1 //adc 中断使能
}
InterruptSW_TypeDef;
void ADC_StartConversion(void);
void ADC_Config(ADC_RefVolt_TypeDef adc_ref,InterruptSW_TypeDef adc_int);
unsigned int GetAdcValue(void);
unsigned char GetChannel8BitAdValue(unsigned char ch);
unsigned int GetChannel12BitAdValue(unsigned char ch);
void ADC_ConfigChannel(ADC_Channel_TypeDef channel);
void ADC_init(void);
void ADC_ISR(void);
unsigned int Read_ADC(unsigned char channel,unsigned char filter);
#endif