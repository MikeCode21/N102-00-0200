#ifndef _PINDEF_H_
#define _PINDEF_H_
/*********P0.0******************************************************************************/
#define P00_CFG_INPUT_PULL_UP				GPIO_Init(P00F,INPUT | PU_EN);
#define P00_CFG_INPUT_PULL_DN				GPIO_Init(P00F,INPUT | PD_EN);

#define P00_CFG_INPUT_PULL_NO				GPIO_Init(P00F,INPUT);

#define P00_CFG_OUTPUT_PULL_UP			GPIO_Init(P00F,OUTPUT | PU_EN);
#define P00_CFG_OUTPUT_PULL_DN			GPIO_Init(P00F,OUTPUT | PD_EN);
#define P00_CFG_OUTPUT_PULL_OP			GPIO_Init(P00F,OUTPUT | OP_EN);
#define P00_CFG_OUTPUT_PULL_NO			GPIO_Init(P00F,OUTPUT);
#define P00_CFG_HIGH_Z							GPIO_Init(P00F,HIGH_Z);            

#define P00_CFG_ADC0								GPIO_Init(P00F,P00_ADC0_SETTING);
#define P00_CFG_PWM0								GPIO_Init(P00F,P00_PWM0_SETTING);
#define P00_CFG_TK0									GPIO_Init(P00F,P00_TK0_SETTING);
#define P00_CFG_T2CP								GPIO_Init(P00F,P00_T2CP_SETTING);
#define P00_CFG_UART2_TX						GPIO_Init(P00F,P00_UART2_TX_SETTING);
#define P00_CFG_UART2_RX						GPIO_Init(P00F,P00_UART2_RX_SETTING);
#define P00_CFG_I2C_SCL						  GPIO_Init(P00F,P00_I2C_SCL_SETTING);
#define P00_CFG_I2C_SDA						  GPIO_Init(P00F,P00_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P0.1******************************************************************************/
#define P01_CFG_INPUT_PULL_UP				GPIO_Init(P01F,INPUT | PU_EN);
#define P01_CFG_INPUT_PULL_DN				GPIO_Init(P01F,INPUT | PD_EN);

#define P01_CFG_INPUT_PULL_NO				GPIO_Init(P01F,INPUT);
#define P01_CFG_OUTPUT_PULL_UP			GPIO_Init(P01F,OUTPUT | PU_EN);
#define P01_CFG_OUTPUT_PULL_DN			GPIO_Init(P01F,OUTPUT | PD_EN);
#define P01_CFG_OUTPUT_PULL_OP			GPIO_Init(P01F,OUTPUT | OP_EN);
#define P01_CFG_OUTPUT_PULL_NO			GPIO_Init(P01F,OUTPUT);
#define P01_CFG_HIGH_Z							GPIO_Init(P01F,HIGH_Z);            

#define P01_CFG_ADC1								GPIO_Init(P01F,P01_ADC1_SETTING);
#define P01_CFG_PWM1								GPIO_Init(P01F,P01_PWM1_SETTING);
#define P01_CFG_TK1									GPIO_Init(P01F,P01_TK1_SETTING);
#define P01_CFG_T2CP								GPIO_Init(P01F,P01_T2CP_SETTING);
#define P01_CFG_UART2_TX						GPIO_Init(P01F,P01_UART2_TX_SETTING);
#define P01_CFG_UART2_RX						GPIO_Init(P01F,P01_UART2_RX_SETTING);
#define P01_CFG_I2C_SCL						  GPIO_Init(P01F,P01_I2C_SCL_SETTING);
#define P01_CFG_I2C_SDA						  GPIO_Init(P01F,P01_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P0.2******************************************************************************/
#define P02_CFG_INPUT_PULL_UP				GPIO_Init(P02F,INPUT | PU_EN);
#define P02_CFG_INPUT_PULL_DN				GPIO_Init(P02F,INPUT | PD_EN);

#define P02_CFG_INPUT_PULL_NO				GPIO_Init(P02F,INPUT);
#define P02_CFG_OUTPUT_PULL_UP			GPIO_Init(P02F,OUTPUT | PU_EN);
#define P02_CFG_OUTPUT_PULL_DN			GPIO_Init(P02F,OUTPUT | PD_EN);
#define P02_CFG_OUTPUT_PULL_OP			GPIO_Init(P02F,OUTPUT | OP_EN);
#define P02_CFG_OUTPUT_PULL_NO			GPIO_Init(P02F,OUTPUT);
#define P02_CFG_HIGH_Z							GPIO_Init(P02F,HIGH_Z);            

#define P02_CFG_ADC2								GPIO_Init(P02F,P02_ADC2_SETTING);
#define P02_CFG_PWM2								GPIO_Init(P02F,P02_PWM2_SETTING);
#define P02_CFG_TK2									GPIO_Init(P02F,P02_TK2_SETTING);
#define P02_CFG_T2CP								GPIO_Init(P02F,P02_T2CP_SETTING);
#define P02_CFG_UART2_TX						GPIO_Init(P02F,P02_UART2_TX_SETTING);
#define P02_CFG_UART2_RX						GPIO_Init(P02F,P02_UART2_RX_SETTING);
#define P02_CFG_I2C_SCL						  GPIO_Init(P02F,P02_I2C_SCL_SETTING);
#define P02_CFG_I2C_SDA						  GPIO_Init(P02F,P02_I2C_SDA_SETTING);
#define P02_CFG_T0						  		GPIO_Init(P02F,P02_T0_SETTING);
/*******************************************************************************************/
/*********P0.3******************************************************************************/
#define P03_CFG_INPUT_PULL_UP				GPIO_Init(P03F,INPUT | PU_EN);
#define P03_CFG_INPUT_PULL_DN				GPIO_Init(P03F,INPUT | PD_EN);

#define P03_CFG_INPUT_PULL_NO				GPIO_Init(P03F,INPUT);

#define P03_CFG_OUTPUT_PULL_UP			GPIO_Init(P03F,OUTPUT | PU_EN);
#define P03_CFG_OUTPUT_PULL_DN			GPIO_Init(P03F,OUTPUT | PD_EN);
#define P03_CFG_OUTPUT_PULL_OP			GPIO_Init(P03F,OUTPUT | OP_EN);
#define P03_CFG_OUTPUT_PULL_NO			GPIO_Init(P03F,OUTPUT);
#define P03_CFG_HIGH_Z							GPIO_Init(P03F,HIGH_Z); 

#define P03_CFG_ADC3								GPIO_Init(P03F,P03_ADC3_SETTING);
#define P03_CFG_PWM3								GPIO_Init(P03F,P03_PWM3_SETTING);
#define P03_CFG_TK3									GPIO_Init(P03F,P03_TK3_SETTING);
#define P03_CFG_T2CP								GPIO_Init(P03F,P03_T2CP_SETTING);
#define P03_CFG_UART2_TX						GPIO_Init(P03F,P03_UART2_TX_SETTING);
#define P03_CFG_UART2_RX						GPIO_Init(P03F,P03_UART2_RX_SETTING);
#define P03_CFG_I2C_SCL						  GPIO_Init(P03F,P03_I2C_SCL_SETTING);
#define P03_CFG_I2C_SDA						  GPIO_Init(P03F,P03_I2C_SDA_SETTING);
#define P03_CFG_T1						  		GPIO_Init(P03F,P03_T1_SETTING);
/*******************************************************************************************/
/*********P0.4******************************************************************************/
#define P04_CFG_INPUT_PULL_UP				GPIO_Init(P04F,INPUT | PU_EN);
#define P04_CFG_INPUT_PULL_DN				GPIO_Init(P04F,INPUT | PD_EN);

#define P04_CFG_INPUT_PULL_NO				GPIO_Init(P04F,INPUT);

#define P04_CFG_OUTPUT_PULL_UP			GPIO_Init(P04F,OUTPUT | PU_EN);
#define P04_CFG_OUTPUT_PULL_DN			GPIO_Init(P04F,OUTPUT | PD_EN);
#define P04_CFG_OUTPUT_PULL_OP			GPIO_Init(P04F,OUTPUT | OP_EN);
#define P04_CFG_OUTPUT_PULL_NO			GPIO_Init(P04F,OUTPUT);
#define P04_CFG_HIGH_Z							GPIO_Init(P04F,HIGH_Z);            

#define P04_CFG_ADC4								GPIO_Init(P04F,P04_ADC4_SETTING);
#define P04_CFG_PWM0								GPIO_Init(P04F,P04_PWM0_SETTING);
#define P04_CFG_TK4									GPIO_Init(P04F,P04_TK4_SETTING);
#define P04_CFG_T2CP								GPIO_Init(P04F,P04_T2CP_SETTING);
#define P04_CFG_UART2_TX						GPIO_Init(P04F,P04_UART2_TX_SETTING);
#define P04_CFG_UART2_RX						GPIO_Init(P04F,P04_UART2_RX_SETTING);
#define P04_CFG_I2C_SCL						  GPIO_Init(P04F,P04_I2C_SCL_SETTING);
#define P04_CFG_I2C_SDA						  GPIO_Init(P04F,P04_I2C_SDA_SETTING);
/************************************************************************************************/
/*********P0.5***********************************************************************************/
#define P05_CFG_INPUT_PULL_UP				GPIO_Init(P05F,INPUT | PU_EN);
#define P05_CFG_INPUT_PULL_DN				GPIO_Init(P05F,INPUT | PD_EN);

#define P05_CFG_INPUT_PULL_NO				GPIO_Init(P05F,INPUT);

#define P05_CFG_OUTPUT_PULL_UP			GPIO_Init(P05F,OUTPUT | PU_EN);
#define P05_CFG_OUTPUT_PULL_DN			GPIO_Init(P05F,OUTPUT | PD_EN);
#define P05_CFG_OUTPUT_PULL_OP			GPIO_Init(P05F,OUTPUT | OP_EN);
#define P05_CFG_OUTPUT_PULL_NO			GPIO_Init(P05F,OUTPUT);

#define P05_CFG_HIGH_Z							GPIO_Init(P05F,HIGH_Z);            

#define P05_CFG_ADC5								GPIO_Init(P05F,P05_ADC5_SETTING);
#define P05_CFG_PWM1								GPIO_Init(P05F,P05_PWM1_SETTING);
#define P05_CFG_TK5									GPIO_Init(P05F,P05_TK4_SETTING);
#define P05_CFG_T2CP								GPIO_Init(P05F,P05_T2CP_SETTING);
#define P05_CFG_UART2_TX						GPIO_Init(P05F,P05_UART2_TX_SETTING);
#define P05_CFG_UART2_RX						GPIO_Init(P05F,P05_UART2_RX_SETTING);
#define P05_CFG_I2C_SCL						  GPIO_Init(P05F,P05_I2C_SCL_SETTING);
#define P05_CFG_I2C_SDA						  GPIO_Init(P05F,P05_I2C_SDA_SETTING);
/************************************************************************************************/
/*********P0.6***********************************************************************************/
#define P06_CFG_INPUT_PULL_UP				GPIO_Init(P06F,INPUT | PU_EN);
#define P06_CFG_INPUT_PULL_DN				GPIO_Init(P06F,INPUT | PD_EN);

#define P06_CFG_INPUT_PULL_NO				GPIO_Init(P06F,INPUT);

#define P06_CFG_OUTPUT_PULL_UP			GPIO_Init(P06F,OUTPUT | PU_EN);
#define P06_CFG_OUTPUT_PULL_DN			GPIO_Init(P06F,OUTPUT | PD_EN);
#define P06_CFG_OUTPUT_PULL_OP			GPIO_Init(P06F,OUTPUT | OP_EN);
#define P06_CFG_OUTPUT_PULL_NO			GPIO_Init(P06F,OUTPUT);
#define P06_CFG_HIGH_Z							GPIO_Init(P06F,HIGH_Z);            

#define P06_CFG_ADC6								GPIO_Init(P06F,P06_ADC6_SETTING);
#define P06_CFG_PWM2								GPIO_Init(P06F,P06_PWM2_SETTING);
#define P06_CFG_TK6									GPIO_Init(P06F,P06_TK6_SETTING);
#define P06_CFG_T2CP								GPIO_Init(P06F,P06_T2CP_SETTING);
#define P06_CFG_UART2_TX						GPIO_Init(P06F,P06_UART2_TX_SETTING);
#define P06_CFG_UART2_RX						GPIO_Init(P06F,P06_UART2_RX_SETTING);
#define P06_CFG_I2C_SCL						  GPIO_Init(P06F,P06_I2C_SCL_SETTING);
#define P06_CFG_I2C_SDA						  GPIO_Init(P06F,P06_I2C_SDA_SETTING);
/************************************************************************************************/
/*********P0.7***********************************************************************************/
#define P07_CFG_INPUT_PULL_UP				GPIO_Init(P07F,INPUT | PU_EN);
#define P07_CFG_INPUT_PULL_DN				GPIO_Init(P07F,INPUT | PD_EN);

#define P07_CFG_INPUT_PULL_NO				GPIO_Init(P07F,INPUT);

#define P07_CFG_OUTPUT_PULL_UP			GPIO_Init(P07F,OUTPUT | PU_EN);
#define P07_CFG_OUTPUT_PULL_DN			GPIO_Init(P07F,OUTPUT | PD_EN);
#define P07_CFG_OUTPUT_PULL_OP			GPIO_Init(P07F,OUTPUT | OP_EN);
#define P07_CFG_OUTPUT_PULL_NO			GPIO_Init(P07F,OUTPUT);

#define P07_CFG_HIGH_Z							GPIO_Init(P07F,HIGH_Z);            

#define P07_CFG_ADC7								GPIO_Init(P07F,P07_ADC7_SETTING);
#define P07_CFG_PWM3								GPIO_Init(P07F,P07_PWM3_SETTING);
#define P07_CFG_TK7									GPIO_Init(P07F,P07_TK7_SETTING);
#define P07_CFG_T2CP								GPIO_Init(P07F,P07_T2CP_SETTING);
#define P07_CFG_UART2_TX						GPIO_Init(P07F,P07_UART2_TX_SETTING);
#define P07_CFG_UART2_RX						GPIO_Init(P07F,P07_UART2_RX_SETTING);
#define P07_CFG_I2C_SCL						  GPIO_Init(P07F,P07_I2C_SCL_SETTING);
#define P07_CFG_I2C_SDA						  GPIO_Init(P07F,P07_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P1.0******************************************************************************/
#define P10_CFG_INPUT_PULL_UP				GPIO_Init(P10F,INPUT | PU_EN);
#define P10_CFG_INPUT_PULL_DN				GPIO_Init(P10F,INPUT | PD_EN);

#define P10_CFG_INPUT_PULL_NO				GPIO_Init(P10F,INPUT);

#define P10_CFG_OUTPUT_PULL_UP			GPIO_Init(P10F,OUTPUT | PU_EN);
#define P10_CFG_OUTPUT_PULL_DN			GPIO_Init(P10F,OUTPUT | PD_EN);
#define P10_CFG_OUTPUT_PULL_OP			GPIO_Init(P10F,OUTPUT | OP_EN);
#define P10_CFG_OUTPUT_PULL_NO			GPIO_Init(P10F,OUTPUT);

#define P10_CFG_HIGH_Z						  GPIO_Init(P10F,HIGH_Z);            

#define P10_CFG_ADC8								GPIO_Init(P10F,P10_ADC8_SETTING);
#define P10_CFG_PWM0								GPIO_Init(P10F,P10_PWM0_SETTING);
#define P10_CFG_TK8									GPIO_Init(P10F,P10_TK8_SETTING);
#define P10_CFG_T2CP								GPIO_Init(P10F,P10_T2CP_SETTING);

#define P10_CFG_UART2_RX						GPIO_Init(P10F,P10_UART2_RX_SETTING);
#define P10_CFG_I2C_SCL						  GPIO_Init(P10F,P10_I2C_SCL_SETTING);
#define P10_CFG_I2C_SDA						  GPIO_Init(P10F,P10_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P1.1******************************************************************************/
#define P11_CFG_INPUT_PULL_UP				GPIO_Init(P11F,INPUT | PU_EN);
#define P11_CFG_INPUT_PULL_DN				GPIO_Init(P11F,INPUT | PD_EN);

#define P11_CFG_INPUT_PULL_NO				GPIO_Init(P11F,INPUT);

#define P11_CFG_OUTPUT_PULL_UP			GPIO_Init(P11F,OUTPUT | PU_EN);
#define P11_CFG_OUTPUT_PULL_DN			GPIO_Init(P11F,OUTPUT | PD_EN);
#define P11_CFG_OUTPUT_PULL_OP			GPIO_Init(P11F,OUTPUT | OP_EN);
#define P11_CFG_OUTPUT_PULL_NO			GPIO_Init(P11F,OUTPUT);

#define P11_CFG_HIGH_Z							GPIO_Init(P11F,HIGH_Z);            

#define P11_CFG_ADC9								GPIO_Init(P11F,P11_ADC9_SETTING);
#define P11_CFG_PWM1								GPIO_Init(P11F,P11_PWM1_SETTING);
#define P11_CFG_TK9									GPIO_Init(P11F,P11_TK9_SETTING);
#define P11_CFG_T2CP								GPIO_Init(P11F,P11_T2CP_SETTING);
#define P11_CFG_UART2_TX						GPIO_Init(P11F,P11_UART2_TX_SETTING);
#define P11_CFG_UART2_RX						GPIO_Init(P11F,P11_UART2_RX_SETTING);
#define P11_CFG_I2C_SCL						  GPIO_Init(P11F,P11_I2C_SCL_SETTING);
#define P11_CFG_I2C_SDA						  GPIO_Init(P11F,P11_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P1.2******************************************************************************/
#define P12_CFG_INPUT_PULL_UP				GPIO_Init(P12F,INPUT | PU_EN);
#define P12_CFG_INPUT_PULL_DN				GPIO_Init(P12F,INPUT | PD_EN);

#define P12_CFG_INPUT_PULL_NO				GPIO_Init(P12F,INPUT);

#define P12_CFG_OUTPUT_PULL_UP			GPIO_Init(P12F,OUTPUT | PU_EN);
#define P12_CFG_OUTPUT_PULL_DN			GPIO_Init(P12F,OUTPUT | PD_EN);
#define P12_CFG_OUTPUT_PULL_OP			GPIO_Init(P12F,OUTPUT | OP_EN);
#define P12_CFG_OUTPUT_PULL_NO			GPIO_Init(P12F,OUTPUT);

#define P12_CFG_HIGH_Z							GPIO_Init(P12F,HIGH_Z);            

#define P12_CFG_ADC10								GPIO_Init(P12F,P12_ADC10_SETTING);
#define P12_CFG_PWM2								GPIO_Init(P12F,P12_PWM2_SETTING);
#define P12_CFG_TK10								GPIO_Init(P12F,P12_TK10_SETTING);
#define P12_CFG_T2CP								GPIO_Init(P12F,P12_T2CP_SETTING);
#define P12_CFG_UART2_TX						GPIO_Init(P12F,P12_UART2_TX_SETTING);
#define P12_CFG_UART2_RX						GPIO_Init(P12F,P12_UART2_RX_SETTING);
#define P12_CFG_I2C_SCL						  GPIO_Init(P12F,P12_I2C_SCL_SETTING);
#define P12_CFG_I2C_SDA						  GPIO_Init(P12F,P12_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P1.3******************************************************************************/
#define P13_CFG_INPUT_PULL_UP				GPIO_Init(P13F,INPUT | PU_EN);
#define P13_CFG_INPUT_PULL_DN				GPIO_Init(P13F,INPUT | PD_EN);

#define P13_CFG_INPUT_PULL_NO				GPIO_Init(P13F,INPUT);


#define P13_CFG_OUTPUT_PULL_UP			GPIO_Init(P13F,OUTPUT | PU_EN);
#define P13_CFG_OUTPUT_PULL_DN			GPIO_Init(P13F,OUTPUT | PD_EN);
#define P13_CFG_OUTPUT_PULL_OP			GPIO_Init(P13F,OUTPUT | OP_EN);
#define P13_CFG_OUTPUT_PULL_NO			GPIO_Init(P13F,OUTPUT);
#define P13_CFG_HIGH_Z							GPIO_Init(P13F,HIGH_Z);            

#define P13_CFG_ADC11								GPIO_Init(P13F,P13_ADC11_SETTING);
#define P13_CFG_PWM3								GPIO_Init(P13F,P13_PWM3_SETTING);
#define P13_CFG_TK11								GPIO_Init(P13F,P13_TK11_SETTING);
#define P13_CFG_T2CP								GPIO_Init(P13F,P13_T2CP_SETTING);
#define P13_CFG_UART2_TX						GPIO_Init(P13F,P13_UART2_TX_SETTING);
#define P13_CFG_UART2_RX						GPIO_Init(P13F,P13_UART2_RX_SETTING);
#define P13_CFG_I2C_SCL						  GPIO_Init(P13F,P13_I2C_SCL_SETTING);
#define P13_CFG_I2C_SDA						  GPIO_Init(P13F,P13_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P1.4******************************************************************************/
#define P14_CFG_INPUT_PULL_UP				GPIO_Init(P14F,INPUT | PU_EN);
#define P14_CFG_INPUT_PULL_DN				GPIO_Init(P14F,INPUT | PD_EN);

#define P14_CFG_INPUT_PULL_NO				GPIO_Init(P14F,INPUT);

#define P14_CFG_OUTPUT_PULL_UP			GPIO_Init(P14F,OUTPUT | PU_EN);
#define P14_CFG_OUTPUT_PULL_DN			GPIO_Init(P14F,OUTPUT | PD_EN);
#define P14_CFG_OUTPUT_PULL_OP			GPIO_Init(P14F,OUTPUT | OP_EN);
#define P14_CFG_OUTPUT_PULL_NO			GPIO_Init(P14F,OUTPUT);

#define P14_CFG_HIGH_Z						  GPIO_Init(P14F,HIGH_Z);            

#define P14_CFG_ADC12								GPIO_Init(P14F,P14_ADC12_SETTING);
#define P14_CFG_PWM0								GPIO_Init(P14F,P14_PWM0_SETTING);
#define P14_CFG_TK12								GPIO_Init(P14F,P14_TK12_SETTING);

#define P14_CFG_UART2_TX						GPIO_Init(P14F,P14_UART2_TX_SETTING);
#define P14_CFG_UART2_RX						GPIO_Init(P14F,P14_UART2_RX_SETTING);
#define P14_CFG_I2C_SCL						  GPIO_Init(P14F,P14_I2C_SCL_SETTING);
#define P14_CFG_I2C_SDA						  GPIO_Init(P14F,P14_I2C_SDA_SETTING);
#define P14_CFG_SPI_SDI						  GPIO_Init(P14F,P14_SPI_SDI_SETTING);
/*******************************************************************************************/
/*********P1.5******************************************************************************/
#define P15_CFG_INPUT_PULL_UP				GPIO_Init(P15F,INPUT | PU_EN);
#define P15_CFG_INPUT_PULL_DN				GPIO_Init(P15F,INPUT | PD_EN);

#define P15_CFG_INPUT_PULL_NO				GPIO_Init(P15F,INPUT);

#define P15_CFG_OUTPUT_PULL_UP			GPIO_Init(P15F,OUTPUT | PU_EN);
#define P15_CFG_OUTPUT_PULL_DN			GPIO_Init(P15F,OUTPUT | PD_EN);
#define P15_CFG_OUTPUT_PULL_OP			GPIO_Init(P15F,OUTPUT | OP_EN);
#define P15_CFG_OUTPUT_PULL_NO			GPIO_Init(P15F,OUTPUT);
#define P15_CFG_HIGH_Z							GPIO_Init(P15F,HIGH_Z);            

#define P15_CFG_ADC13								GPIO_Init(P15F,P15_ADC13_SETTING);
#define P15_CFG_PWM1								GPIO_Init(P15F,P15_PWM1_SETTING);
#define P15_CFG_TK13								GPIO_Init(P15F,P15_TK13_SETTING);

#define P15_CFG_UART1_TX						GPIO_Init(P15F,P15_UART1_TX_SETTING);
#define P15_CFG_UART1_RX						GPIO_Init(P15F,P15_UART1_RX_SETTING);
#define P15_CFG_I2C_SCL						  GPIO_Init(P15F,P15_I2C_SCL_SETTING);
#define P15_CFG_I2C_SDA						  GPIO_Init(P15F,P15_I2C_SDA_SETTING);
#define P15_CFG_SPI_SDO						  GPIO_Init(P15F,P15_SPI_SDO_SETTING);
/*************************************************************************************************/
/*********P1.6************************************************************************************/
#define P16_CFG_INPUT_PULL_UP				GPIO_Init(P16F,INPUT | PU_EN);
#define P16_CFG_INPUT_PULL_DN				GPIO_Init(P16F,INPUT | PD_EN);

#define P16_CFG_INPUT_PULL_NO				GPIO_Init(P16F,INPUT);

#define P16_CFG_OUTPUT_PULL_UP			GPIO_Init(P16F,OUTPUT | PU_EN);
#define P16_CFG_OUTPUT_PULL_DN			GPIO_Init(P16F,OUTPUT | PD_EN);
#define P16_CFG_OUTPUT_PULL_OP			GPIO_Init(P16F,OUTPUT | OP_EN);
#define P16_CFG_OUTPUT_PULL_NO			GPIO_Init(P16F,OUTPUT);

#define P16_CFG_HIGH_Z							GPIO_Init(P16F,HIGH_Z);            

#define P16_CFG_ADC14								GPIO_Init(P16F,P16_ADC14_SETTING);
#define P16_CFG_PWM2								GPIO_Init(P16F,P16_PWM2_SETTING);
#define P16_CFG_TK14								GPIO_Init(P16F,P16_TK14_SETTING);

#define P16_CFG_UART1_TX						GPIO_Init(P16F,P16_UART1_TX_SETTING);
#define P16_CFG_UART1_RX						GPIO_Init(P16F,P16_UART1_RX_SETTING);
#define P16_CFG_I2C_SCL						  GPIO_Init(P16F,P16_I2C_SCL_SETTING);
#define P16_CFG_I2C_SDA						  GPIO_Init(P16F,P16_I2C_SDA_SETTING);
#define P16_CFG_SPI_SCK						  GPIO_Init(P16F,P16_SPI_SCK_SETTING);
/*************************************************************************************************/
/*********P1.7************************************************************************************/
#define P17_CFG_INPUT_PULL_UP				GPIO_Init(P17F,INPUT | PU_EN);
#define P17_CFG_INPUT_PULL_DN				GPIO_Init(P17F,INPUT | PD_EN);

#define P17_CFG_INPUT_PULL_NO				GPIO_Init(P17F,INPUT);

#define P17_CFG_OUTPUT_PULL_UP			GPIO_Init(P17F,OUTPUT | PU_EN);
#define P17_CFG_OUTPUT_PULL_DN			GPIO_Init(P17F,OUTPUT | PD_EN);
#define P17_CFG_OUTPUT_PULL_OP			GPIO_Init(P17F,OUTPUT | OP_EN);
#define P17_CFG_OUTPUT_PULL_NO			GPIO_Init(P17F,OUTPUT);
#define P17_CFG_HIGH_Z							GPIO_Init(P17F,HIGH_Z);            

#define P17_CFG_ADC15								GPIO_Init(P17F,P17_ADC15_SETTING);
#define P17_CFG_PWM3								GPIO_Init(P17F,P17_PWM3_SETTING);
#define P17_CFG_TK15								GPIO_Init(P17F,P17_TK15_SETTING);

#define P17_CFG_UART1_TX						GPIO_Init(P17F,P17_UART1_TX_SETTING);
#define P17_CFG_UART1_RX						GPIO_Init(P17F,P17_UART1_RX_SETTING);
#define P17_CFG_I2C_SCL						  GPIO_Init(P17F,P17_I2C_SCL_SETTING);
#define P17_CFG_I2C_SDA						  GPIO_Init(P17F,P17_I2C_SDA_SETTING);
#define P17_CFG_SPI_SCS						  GPIO_Init(P17F,P17_SPI_SCS_SETTING);
/*******************************************************************************************/
/*********P2.0******************************************************************************/
#define P20_CFG_INPUT_PULL_UP				GPIO_Init(P20F,INPUT | PU_EN);
#define P20_CFG_INPUT_PULL_DN				GPIO_Init(P20F,INPUT | PD_EN);

#define P20_CFG_INPUT_PULL_NO				GPIO_Init(P20F,INPUT);

#define P20_CFG_OUTPUT_PULL_UP			GPIO_Init(P20F,OUTPUT | PU_EN);
#define P20_CFG_OUTPUT_PULL_DN			GPIO_Init(P20F,OUTPUT | PD_EN);
#define P20_CFG_OUTPUT_PULL_OP			GPIO_Init(P20F,OUTPUT | OP_EN);
#define P20_CFG_OUTPUT_PULL_NO			GPIO_Init(P20F,OUTPUT);
#define P20_CFG_HIGH_Z							GPIO_Init(P20F,HIGH_Z);            

#define P20_CFG_ADC16								GPIO_Init(P20F,P20_ADC16_SETTING);
#define P20_CFG_PWM0								GPIO_Init(P20F,P20_PWM0_SETTING);
#define P20_CFG_TK16								GPIO_Init(P20F,P20_TK16_SETTING);

#define P20_CFG_UART1_TX						GPIO_Init(P20F,P20_UART1_TX_SETTING);
#define P20_CFG_UART1_RX						GPIO_Init(P20F,P20_UART1_RX_SETTING);
#define P20_CFG_I2C_SCL						  GPIO_Init(P20F,P20_I2C_SCL_SETTING);
#define P20_CFG_I2C_SDA						  GPIO_Init(P20F,P20_I2C_SDA_SETTING);
#define P20_CFG_SPI_SDI						  GPIO_Init(P20F,P20_SPI_SDI_SETTING);
/*******************************************************************************************/
/*********P2.1******************************************************************************/
#define P21_CFG_INPUT_PULL_UP				GPIO_Init(P21F,INPUT | PU_EN);
#define P21_CFG_INPUT_PULL_DN				GPIO_Init(P21F,INPUT | PD_EN);

#define P21_CFG_INPUT_PULL_NO				GPIO_Init(P21F,INPUT);

#define P21_CFG_OUTPUT_PULL_UP			GPIO_Init(P21F,OUTPUT | PU_EN);
#define P21_CFG_OUTPUT_PULL_DN			GPIO_Init(P21F,OUTPUT | PD_EN);
#define P21_CFG_OUTPUT_PULL_OP			GPIO_Init(P21F,OUTPUT | OP_EN);
#define P21_CFG_OUTPUT_PULL_NO			GPIO_Init(P21F,OUTPUT);
#define P21_CFG_HIGH_Z							GPIO_Init(P21F,HIGH_Z);            

#define P21_CFG_ADC17								GPIO_Init(P21F,P21_ADC17_SETTING);
#define P21_CFG_PWM1								GPIO_Init(P21F,P21_PWM1_SETTING);
#define P21_CFG_TK17								GPIO_Init(P21F,P21_TK17_SETTING);

#define P21_CFG_UART1_TX						GPIO_Init(P21F,P21_UART1_TX_SETTING);
#define P21_CFG_UART1_RX						GPIO_Init(P21F,P21_UART1_RX_SETTING);
#define P21_CFG_I2C_SCL						  GPIO_Init(P21F,P21_I2C_SCL_SETTING);
#define P21_CFG_I2C_SDA						  GPIO_Init(P21F,P21_I2C_SDA_SETTING);
#define P21_CFG_SPI_SCK						  GPIO_Init(P21F,P21_SPI_SCK_SETTING);
/*******************************************************************************************/
/*********P2.2******************************************************************************/
#define P22_CFG_INPUT_PULL_UP				GPIO_Init(P22F,INPUT | PU_EN);
#define P22_CFG_INPUT_PULL_DN				GPIO_Init(P22F,INPUT | PD_EN);

#define P22_CFG_INPUT_PULL_NO				GPIO_Init(P22F,INPUT);

#define P22_CFG_OUTPUT_PULL_UP			GPIO_Init(P22F,OUTPUT | PU_EN);
#define P22_CFG_OUTPUT_PULL_DN			GPIO_Init(P22F,OUTPUT | PD_EN);
#define P22_CFG_OUTPUT_PULL_OP			GPIO_Init(P22F,OUTPUT | OP_EN);
#define P22_CFG_OUTPUT_PULL_NO			GPIO_Init(P22F,OUTPUT);
#define P22_CFG_HIGH_Z							GPIO_Init(P22F,HIGH_Z);            

#define P22_CFG_ADC18								GPIO_Init(P22F,P22_ADC18_SETTING);
#define P22_CFG_PWM2								GPIO_Init(P22F,P22_PWM2_SETTING);
#define P22_CFG_TK18								GPIO_Init(P22F,P22_TK18_SETTING);

#define P22_CFG_UART1_TX						GPIO_Init(P22F,P22_UART1_TX_SETTING);
#define P22_CFG_UART1_RX						GPIO_Init(P22F,P22_UART1_RX_SETTING);
#define P22_CFG_I2C_SCL						  GPIO_Init(P22F,P22_I2C_SCL_SETTING);
#define P22_CFG_I2C_SDA						  GPIO_Init(P22F,P22_I2C_SDA_SETTING);
#define P22_CFG_XOSCL_OUT						GPIO_Init(P22F,P22_XOSCL_OUT_SETTING);
/*******************************************************************************************/
/*********P2.3******************************************************************************/
#define P23_CFG_INPUT_PULL_UP				GPIO_Init(P23F,INPUT | PU_EN);
#define P23_CFG_INPUT_PULL_DN				GPIO_Init(P23F,INPUT | PD_EN);

#define P23_CFG_INPUT_PULL_NO				GPIO_Init(P23F,INPUT);

#define P23_CFG_OUTPUT_PULL_UP			GPIO_Init(P23F,OUTPUT | PU_EN);
#define P23_CFG_OUTPUT_PULL_DN			GPIO_Init(P23F,OUTPUT | PD_EN);
#define P23_CFG_OUTPUT_PULL_OP			GPIO_Init(P23F,OUTPUT | OP_EN);
#define P23_CFG_OUTPUT_PULL_NO			GPIO_Init(P23F,OUTPUT);
#define P23_CFG_HIGH_Z							GPIO_Init(P23F,HIGH_Z);            

#define P23_CFG_ADC19								GPIO_Init(P23F,P23_ADC19_SETTING);
#define P23_CFG_PWM3								GPIO_Init(P23F,P23_PWM3_SETTING);
#define P23_CFG_TK19								GPIO_Init(P23F,P23_TK19_SETTING);

#define P23_CFG_UART1_TX						GPIO_Init(P23F,P23_UART1_TX_SETTING);
#define P23_CFG_UART1_RX						GPIO_Init(P23F,P23_UART1_RX_SETTING);
#define P23_CFG_I2C_SCL						  GPIO_Init(P23F,P23_I2C_SCL_SETTING);
#define P23_CFG_I2C_SDA						  GPIO_Init(P23F,P23_I2C_SDA_SETTING);
#define P23_CFG_XOSCL_IN						GPIO_Init(P23F,P23_XOSCL_IN_SETTING);
/*******************************************************************************************/
/*********P2.4******************************************************************************/
#define P24_CFG_INPUT_PULL_UP				GPIO_Init(P24F,INPUT | PU_EN);
#define P24_CFG_INPUT_PULL_DN				GPIO_Init(P24F,INPUT | PD_EN);

#define P24_CFG_INPUT_PULL_NO				GPIO_Init(P24F,INPUT);

#define P24_CFG_OUTPUT_PULL_UP			GPIO_Init(P24F,OUTPUT | PU_EN);
#define P24_CFG_OUTPUT_PULL_DN			GPIO_Init(P24F,OUTPUT | PD_EN);
#define P24_CFG_OUTPUT_PULL_OP			GPIO_Init(P24F,OUTPUT | OP_EN);
#define P24_CFG_OUTPUT_PULL_NO			GPIO_Init(P24F,OUTPUT);
#define P24_CFG_HIGH_Z							GPIO_Init(P24F,HIGH_Z);            

#define P24_CFG_ADC20								GPIO_Init(P24F,P24_ADC20_SETTING);
#define P24_CFG_PWM0								GPIO_Init(P24F,P24_PWM0_SETTING);
#define P24_CFG_TK20								GPIO_Init(P24F,P24_TK20_SETTING);
#define P24_CFG_T2CP								GPIO_Init(P24F,P24_T2CP_SETTING);
#define P24_CFG_UART1_TX						GPIO_Init(P24F,P24_UART1_TX_SETTING);
#define P24_CFG_UART1_RX						GPIO_Init(P24F,P24_UART1_RX_SETTING);
#define P24_CFG_I2C_SCL						  GPIO_Init(P24F,P24_I2C_SCL_SETTING);
#define P24_CFG_I2C_SDA						  GPIO_Init(P24F,P24_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P2.5******************************************************************************/
#define P25_CFG_INPUT_PULL_UP				GPIO_Init(P25F,INPUT | PU_EN);
#define P25_CFG_INPUT_PULL_DN				GPIO_Init(P25F,INPUT | PD_EN);

#define P25_CFG_INPUT_PULL_NO				GPIO_Init(P25F,INPUT);

#define P25_CFG_OUTPUT_PULL_UP			GPIO_Init(P25F,OUTPUT | PU_EN);
#define P25_CFG_OUTPUT_PULL_DN			GPIO_Init(P25F,OUTPUT | PD_EN);
#define P25_CFG_OUTPUT_PULL_OP			GPIO_Init(P25F,OUTPUT | OP_EN);
#define P25_CFG_OUTPUT_PULL_NO			GPIO_Init(P25F,OUTPUT);
#define P25_CFG_HIGH_Z							GPIO_Init(P25F,HIGH_Z);            

#define P25_CFG_ADC21								GPIO_Init(P25F,P25_ADC21_SETTING);
#define P25_CFG_PWM1								GPIO_Init(P25F,P25_PWM1_SETTING);
#define P25_CFG_TK21								GPIO_Init(P25F,P25_TK21_SETTING);
#define P25_CFG_T2CP								GPIO_Init(P25F,P25_T2CP_SETTING);
#define P25_CFG_UART1_TX						GPIO_Init(P25F,P25_UART1_TX_SETTING);
#define P25_CFG_UART1_RX						GPIO_Init(P25F,P25_UART1_RX_SETTING);
#define P25_CFG_I2C_SCL						  GPIO_Init(P25F,P25_I2C_SCL_SETTING);
#define P25_CFG_I2C_SDA						  GPIO_Init(P25F,P25_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P2.6******************************************************************************/
#define P26_CFG_INPUT_PULL_UP				GPIO_Init(P26F,INPUT | PU_EN);
#define P26_CFG_INPUT_PULL_DN				GPIO_Init(P26F,INPUT | PD_EN);

#define P26_CFG_INPUT_PULL_NO				GPIO_Init(P26F,INPUT);

#define P26_CFG_OUTPUT_PULL_UP			GPIO_Init(P26F,OUTPUT | PU_EN);
#define P26_CFG_OUTPUT_PULL_DN			GPIO_Init(P26F,OUTPUT | PD_EN);
#define P26_CFG_OUTPUT_PULL_OP			GPIO_Init(P26F,OUTPUT | OP_EN);
#define P26_CFG_OUTPUT_PULL_NO			GPIO_Init(P26F,OUTPUT);
#define P26_CFG_HIGH_Z							GPIO_Init(P26F,HIGH_Z);            

#define P26_CFG_ADC22								GPIO_Init(P26F,P26_ADC22_SETTING);
#define P26_CFG_PWM2								GPIO_Init(P26F,P26_PWM2_SETTING);
#define P26_CFG_TK22								GPIO_Init(P26F,P26_TK22_SETTING);
#define P26_CFG_T2CP								GPIO_Init(P26F,P26_T2CP_SETTING);
#define P26_CFG_UART1_TX						GPIO_Init(P26F,P26_UART1_TX_SETTING);
#define P26_CFG_UART1_RX						GPIO_Init(P26F,P26_UART1_RX_SETTING);
#define P26_CFG_I2C_SCL						  GPIO_Init(P26F,P26_I2C_SCL_SETTING);
#define P26_CFG_I2C_SDA						  GPIO_Init(P26F,P26_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P2.7******************************************************************************/
#define P27_CFG_INPUT_PULL_UP				GPIO_Init(P27F,INPUT | PU_EN);
#define P27_CFG_INPUT_PULL_DN				GPIO_Init(P27F,INPUT | PD_EN);

#define P27_CFG_INPUT_PULL_NO				GPIO_Init(P27F,INPUT);

#define P27_CFG_OUTPUT_PULL_UP			GPIO_Init(P27F,OUTPUT | PU_EN);
#define P27_CFG_OUTPUT_PULL_DN			GPIO_Init(P27F,OUTPUT | PD_EN);
#define P27_CFG_OUTPUT_PULL_OP			GPIO_Init(P27F,OUTPUT | OP_EN);
#define P27_CFG_OUTPUT_PULL_NO			GPIO_Init(P27F,OUTPUT);
#define P27_CFG_HIGH_Z							GPIO_Init(P27F,HIGH_Z);            

#define P27_CFG_ADC23								GPIO_Init(P27F,P27_ADC23_SETTING);
#define P27_CFG_PWM3								GPIO_Init(P27F,P27_PWM3_SETTING);
#define P27_CFG_TK23								GPIO_Init(P27F,P27_TK23_SETTING);
#define P27_CFG_T2CP								GPIO_Init(P27F,P27_T2CP_SETTING);
#define P27_CFG_UART1_TX						GPIO_Init(P27F,P27_UART1_TX_SETTING);
#define P27_CFG_UART1_RX						GPIO_Init(P27F,P27_UART1_RX_SETTING);
#define P27_CFG_I2C_SCL						  GPIO_Init(P27F,P27_I2C_SCL_SETTING);
#define P27_CFG_I2C_SDA						  GPIO_Init(P27F,P27_I2C_SDA_SETTING);

/*******************************************************************************************/
/*********P3.0******************************************************************************/
#define P30_CFG_INPUT_PULL_UP				GPIO_Init(P30F,INPUT | PU_EN);
#define P30_CFG_INPUT_PULL_DN				GPIO_Init(P30F,INPUT | PD_EN);

#define P30_CFG_INPUT_PULL_NO				GPIO_Init(P30F,INPUT);

#define P30_CFG_OUTPUT_PULL_UP			GPIO_Init(P30F,OUTPUT | PU_EN);
#define P30_CFG_OUTPUT_PULL_DN			GPIO_Init(P30F,OUTPUT | PD_EN);
#define P30_CFG_OUTPUT_PULL_OP			GPIO_Init(P30F,OUTPUT | OP_EN);
#define P30_CFG_OUTPUT_PULL_NO			GPIO_Init(P30F,OUTPUT);

#define P30CFG_HIGH_Z								GPIO_Init(P30F,HIGH_Z);            

#define P30_CFG_ADC24								GPIO_Init(P30F,P30_ADC24_SETTING);
#define P30_CFG_PWM0								GPIO_Init(P30F,P30_PWM0_SETTING);
#define P30_CFG_TK24								GPIO_Init(P30F,P30_TK24_SETTING);
#define P30_CFG_T2CP								GPIO_Init(P30F,P30_T2CP_SETTING);
#define P30_CFG_UART1_TX						GPIO_Init(P30F,P30_UART1_TX_SETTING);
#define P30_CFG_UART1_RX						GPIO_Init(P30F,P30_UART1_RX_SETTING);
#define P30_CFG_I2C_SCL						  GPIO_Init(P30F,P30_I2C_SCL_SETTING);
#define P30_CFG_I2C_SDA						  GPIO_Init(P30F,P30_I2C_SDA_SETTING);
/*******************************************************************************************/
/*********P3.1******************************************************************************/
#define P31_CFG_INPUT_PULL_UP				GPIO_Init(P31F,INPUT | PU_EN);
#define P31_CFG_INPUT_PULL_DN				GPIO_Init(P31F,INPUT | PD_EN);

#define P31_CFG_INPUT_PULL_NO				GPIO_Init(P31F,INPUT);

#define P31_CFG_OUTPUT_PULL_UP			GPIO_Init(P31F,OUTPUT | PU_EN);
#define P31_CFG_OUTPUT_PULL_DN			GPIO_Init(P31F,OUTPUT | PD_EN);
#define P31_CFG_OUTPUT_PULL_OP			GPIO_Init(P31F,OUTPUT | OP_EN);
#define P31_CFG_OUTPUT_PULL_NO			GPIO_Init(P31F,OUTPUT);

#define P31CFG_HIGH_Z								GPIO_Init(P31F,HIGH_Z);            

#define P31_CFG_ADC25								GPIO_Init(P31F,P31_ADC25_SETTING);
#define P31_CFG_PWM1								GPIO_Init(P31F,P31_PWM1_SETTING);
#define P31_CFG_TK25								GPIO_Init(P31F,P31_TK25_SETTING);
#define P31_CFG_T2CP								GPIO_Init(P31F,P31_T2CP_SETTING);
#define P31_CFG_UART1_TX						GPIO_Init(P31F,P31_UART1_TX_SETTING);
#define P31_CFG_UART1_RX						GPIO_Init(P31F,P31_UART1_RX_SETTING);
#define P31_CFG_I2C_SCL						  GPIO_Init(P31F,P31_I2C_SCL_SETTING);
#define P31_CFG_I2C_SDA						  GPIO_Init(P31F,P31_I2C_SDA_SETTING);
/************************IO  ‰≥ˆ…Ë÷√*************************************************************************/
#define P00_OUT_SET(n)					       P00=n 
#define P01_OUT_SET(n)					       P01=n 
#define P02_OUT_SET(n)					       P02=n 
#define P03_OUT_SET(n)					       P03=n 
#define P04_OUT_SET(n)					       P04=n 
#define P05_OUT_SET(n)					       P05=n 
#define P06_OUT_SET(n)					       P06=n 
#define P07_OUT_SET(n)					       P07=n 
                                       
#define P10_OUT_SET(n)					       P10=n 
#define P11_OUT_SET(n)					       P11=n 
#define P12_OUT_SET(n)					       P12=n 
#define P13_OUT_SET(n)					       P13=n 
#define P14_OUT_SET(n)					       P14=n 
#define P15_OUT_SET(n)					       P15=n 
#define P16_OUT_SET(n)					       P16=n 
#define P17_OUT_SET(n)					       P17=n 
                                       
#define P20_OUT_SET(n)					       P20=n 
#define P21_OUT_SET(n)					       P20=n 
#define P22_OUT_SET(n)					       P20=n 
#define P23_OUT_SET(n)					       P20=n 
#define P24_OUT_SET(n)					       P20=n 
#define P25_OUT_SET(n)					       P20=n 
#define P26_OUT_SET(n)					       P20=n 
#define P27_OUT_SET(n)					       P20=n 
                                       
#define P30_OUT_SET(n)					       P30=n 
#define P31_OUT_SET(n)					       P30=n                            
#endif                                                                                               
