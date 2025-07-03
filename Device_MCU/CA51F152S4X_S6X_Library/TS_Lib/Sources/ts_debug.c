#ifndef TS_I2C_C_
#define TS_I2C_C_
#include "includes\headfile.h"
#include "sys_include/sys_includes.h"
/*********************************************************************************************************************/
#ifdef CA_TOUCH_KEY 
#if TS_I2C_DEBUG
/*********************************************************************************************************************/

#define I2C_ADDR		0xCA
unsigned char xdata TouchDebugID = '3';
unsigned char rxOffset;
unsigned char regAddr;
bit iicReadMode;
extern TSState_T 	  				xdata 	TS_State_Debug;
extern unsigned char 				xdata 	Key_Cnt_Debug;
extern unsigned char 				xdata 	TS_CH_Debug[OPENED_TS_COUNT];	
extern unsigned int  				xdata 	TS_RefChBaseLineData;
extern unsigned int 				xdata 	TS_RefPostData;
extern unsigned long int    xdata 	KeysFlagSN_Debug;
///////////////////////////////////////////////////////////////
//I2CCON定义
#define I2CE(N)		(N<<7)
#define I2CIE(N)	(N<<6)
#define STA(N)		(N<<5)
#define STP(N)		(N<<4)
#define CKHD(N)		(N<<3)
#define AAK(N)		(N<<2)
#define CBSE(N)		(N<<1)
#define STFE(N)		(N<<0)

//I2CADR定义
#define   GCE(N)		(N<<7) //N = 0~1

//I2CADM定义
#define   SPFE(N)		(N<<7) //N = 0~1

//I2CFLG定义
#define I2CF		(1<<0)
//#define I2CSTP		(1<<1)
//SCLSEL
#define I2CKS(N)		(N<<7) //N = 0~1
enum
{
	I2CS_P00_INDEX = 0,
	I2CS_P01_INDEX = 1,
	I2CS_P02_INDEX = 2,
	I2CS_P03_INDEX = 3,
	I2CS_P04_INDEX = 4,
	I2CS_P05_INDEX = 5,
	I2CS_P06_INDEX = 6,
	I2CS_P07_INDEX = 7,

	I2CS_P10_INDEX = 8,
	I2CS_P11_INDEX = 9,
	I2CS_P12_INDEX = 10,
	I2CS_P13_INDEX = 11,
	I2CS_P14_INDEX = 12,
	I2CS_P15_INDEX = 13,
	I2CS_P16_INDEX = 14,
	I2CS_P17_INDEX = 15,
	
	I2CS_P20_INDEX = 16,
	I2CS_P21_INDEX = 17,
	I2CS_P22_INDEX = 18,
	I2CS_P23_INDEX = 19,
	I2CS_P24_INDEX = 20,
	I2CS_P25_INDEX = 21,
	I2CS_P26_INDEX = 22,
	I2CS_P27_INDEX = 23,

	I2CS_P30_INDEX = 24,
	I2CS_P31_INDEX = 25,
};
///////////////////////////////////////////////////////////////
code unsigned char *TS_INFO[]=
{
	&TouchDebugID,
	&TS_State_Debug,
	&Key_Cnt_Debug,
	&TS_RefChBaseLineData,
	&TS_RefPostData,
	&KeysFlagSN_Debug,
	&TS_BaseLineData[0],
	&TS_PostData[0],
	&TSKey_FingerThd[0],
	&TS_CH_Debug[0],
};
unsigned char *pTS_Info;
void I2C_ISR(void)
{
	unsigned char Sta_Temp;
	TouchDebugID = '3';				
	Sta_Temp = I2CSTA;			
	if(Sta_Temp == 0x60)			   //接收到从机地址+写位
	{			
		rxOffset = 0xff;
		iicReadMode = 0;
		I2CCON |= AAK(1);			
	}
	else if(Sta_Temp == 0x80)			   
	{					
		if(iicReadMode)	 						//发送一字节数据
		{
			rxOffset++;
			I2CDAT = *(pTS_Info+rxOffset);			
		}
		else									//接收到一字节数据
		{				
			if(rxOffset == 0xff) 				//地址
			{
				regAddr=I2CDAT;	 
				pTS_Info = TS_INFO[regAddr];
				rxOffset=0;
				I2CCON |= AAK(1);
			}
			else				   				//数据
			{
				*(pTS_Info+rxOffset) = I2CDAT;
				rxOffset++;	
				I2CCON |= AAK(1);		
			}
		}	
	}
	else if(Sta_Temp==0xA8)						//接收到从机地址+读位，发送ACK信号
	{								
		I2CDAT = *(pTS_Info+rxOffset);
		iicReadMode = 1;
	}
	else if(Sta_Temp == 0x88)	
	{
	}
	I2CFLG  |= I2CF;
}
void TS_Debug_init(void)
{	
//I2C引脚SCL/SDA功能可以映射到任意GPIO引脚，由寄存器SCLSEL/SDASEL设置不同的值来选择。
	P00F = P00_I2C_SDA_SETTING|PU_EN;			//P0.0设置为I2C_SDA引脚
	P01F = P01_I2C_SCL_SETTING|PU_EN;			//P0.1设置为I2C_SCL引脚
	
	SCLSEL = I2CKS(0) | I2CS_P01_INDEX;			//I2C工作时钟选择系统时钟，I2C_SCL引脚选择P0.1
	SDASEL = I2CS_P00_INDEX;					//I2C_SDA引脚选择P0.0
	
	I2CCON = I2CE(1) | I2CIE(1) | STA(0) | STP(0)| CKHD(0) | AAK(1)| CBSE(0) | STFE(0);		
	I2CADR = (I2C_ADDR>>1);
	I2CCCR = 0x20;
	
	INT4EN = 1;
	PX4 = 1;									//优先级设置为最高
}
void Debug_ParamLoad(void)
{
	unsigned char i;
	KeysFlagSN_Debug = (unsigned long int)KeysFlagSN;
	TS_State_Debug = TS_State;
	Key_Cnt_Debug = KEY_CH_COUNT;
	for(i = 0; i < KEY_CH_COUNT; i++)
	{
		TS_CH_Debug[i] = TS_CH[i];
	}
	TS_RefPostData  = 0;
	TS_RefChBaseLineData  = 0;
}
#endif
#endif
#endif
