#ifndef _SYS_INIT_C_
#define _SYS_INIT_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
/*********************************************************************************************************************/
/*********************************************************************************************************************
	INT2~INT4控制例程
	1、INT0~1 支持上升沿、下降沿触发
	2、INT2~4 支持上升沿、下降沿、双沿触发
	3、INT0~3 中断输入引脚为固定引脚，
	4、INT4   可配置信号引脚(P1.0~P1.7/P2.0~P2.7/P0.4~P0.7/P3.0/P3.1)作为中断输入引脚
*********************************************************************************************************************/

//////////////////////////////////////////////////////////////////////////////////////
#ifdef HAVE_EXINT0_EN
/***********************************************************************************
函数名  ：		INT0_init										 	
功能描述：		外部中断0初始化
输入参数：		无
返回值  ：		无
***********************************************************************************/
void INT0_IO_init(void)
{
	P00_CFG_INPUT_PULL_UP;   //INT0中断触发源为固定输入引脚P00		
	EX0 = 1;								//INT0中断使能
	IE0 = 1;								//外部中断0中断使能
	IT0 = 1;								//设置INT0为下降沿触发
	PX0 = 1;								//设置INT0中断为最高优先级
}
#endif
#ifdef HAVE_EXINT1_EN
/***********************************************************************************
函数名  ：		INT1_init										 	
功能描述：		外部中断1初始化
输入参数：		无
返回值  ：		无
***********************************************************************************/
void INT1_IO_init(void)
{
	P01_CFG_INPUT_PULL_UP;   //INT1中断触发源为固定输入引脚P01		
	EX1 = 1;								//INT1中断使能
	IE1 = 1;								//外部中断1中断使能
	IT1 = 1;								//设置INT1为下降沿触发
	//PX1 = 1;								//设置INT1中断为最高优先级
}
#endif
#ifdef HAVE_EXINT2_EN
/***********************************************************************************
函数名  ：		INT2_init										 	
功能描述：		外部中断2初始化
输入参数：		无
返回值  ：		无
外部中断触发沿选择位		EPPL(n) 00：上升沿01：下降沿  1x：双沿
***********************************************************************************/
void INT2_IO_init(void)
{	
  P02_CFG_INPUT_PULL_UP;         ////INT2中断触发源为固定输入引脚P02		
//	EP0CON = EPIE(1) | EPPL(1);		//使能外部中断，并选择下降沿触发,	
	EP0CON = EPIE(1) | EPPL(2);		//使能外部中断，并选择双沿触发,
	INT2EN = 1;						//外部中断2中断使能	
}
#endif
#ifdef HAVE_EXINT3_EN
/***********************************************************************************
函数名  ：		INT3_init										 	
功能描述：		外部中断3初始化
输入参数：		无
返回值  ：		无
外部中断触发沿选择位		EPPL(n) 00：上升沿01：下降沿  1x：双沿
***********************************************************************************/
void INT3_IO_init(void)
{
	P03_CFG_INPUT_PULL_UP;         ////INT3中断触发源为固定输入引脚P03		
//	EP1CON = EPIE(1) | EPPL(1);		//使能外部中断，并选择下降沿触发,
	EP1CON = EPIE(1) | EPPL(2);		//使能外部中断，并选择双沿触发,
	INT3EN = 1;						//外部中断3中断使能
}
#endif
#ifdef HAVE_EXINT4_EN
/***********************************************************************************
函数名  ：		INT4_init										 	
功能描述：		外部中断4初始化
输入参数：		无
返回值  ：		无  
					外部中断触发沿选择位		EPPL(n) 00：上升沿 01：下降沿  1x：双沿
***********************************************************************************/
void INT4_IO_init(void)
{	
	P14_CFG_INPUT_PULL_UP;         	//INT4可配置信号引脚(P1.0~P1.7/P2.0~P2.7/P0.4~P0.7/P3.0/P3.1)作为中断输入引脚		
	EP2CON = EPIE(1) | EPPL(1) | EPPSEL(P14_INDEX); //使能外部中断，并选择下降沿触发, 设置P10为INT4中断引脚
	INT4EN = 1;						//外部中断4中断使能	
	
}
#endif
/***********************************************************************************
函数名  ：		System_Init										 	
功能描述：		系统初始化
输入参数：		无
返回值  ：		无
***********************************************************************************/
extern unsigned char IRCL_fosc;
void System_Init(void)
{
#ifdef LVD_ENABLE
		LVD_init();
#endif
#ifdef HAVE_CHANGE_SYS_CLK	
		IHCFG = ReadIHCFG();
		TKCCFG = ReadTKCCFG();
		IRCL_fosc = ReadIRCL_Freq();
#endif
#ifdef HAVE_CHANGE_SYS_CLK	  //设置系统时钟频率
		#if (SYSCLK_SRC == IRCH_16M)
			Sys_Clk_Set_IRCH();
		#elif (SYSCLK_SRC == IRCH_8M)
			Sys_Clk_Set_HALF_IRCH();	
		#else
			Sys_Clk_Set_IRCL();
		#endif
#endif	

#ifdef HAVE_UART
	Uart_Initial();
#endif

#ifdef WATCHDOG_ENABLE
	WDT_init();			//开启看门狗复位 2s
#endif
#ifdef  HAVE_TIME0_EN	 
	Timer0_init();	   //定时器0初始化
#endif
#ifdef  HAVE_TIME1_EN	 
	Timer1_init();	   //定时器0初始化
#endif
#ifdef  HAVE_TIME2_EN
	Timer2_init();	   //定时器2初始化
#endif
#ifdef HAVE_TMC_TIME_EN
	TMC_timer_init();    //约4ms 定时	
#endif
#ifdef PWM_ENABLE
	PWM_init();
#endif
#ifdef FLASH_ENABLE
	FlashRom_init();
#endif
  
#ifdef SPI_ENABLE    //SPI 初始化
	SPI_init();
#endif
	
#ifdef I2C_ENABLE    //IIC 初始化	
  I2C_Init();
#endif
}
/***********************************************************************************
函数名  ：		System_sleep_enter										 	
功能描述：		系统进入stop 模式省电，用RTC 唤醒
输入参数：		无
返回值  ：		无
***********************************************************************************/
#ifdef HAVE_SYSTEM_SLEEP
void System_sleep_enter(void)
{
	unsigned char ck_bak;
/************************************************************************************************************
	所有时钟关闭，所有输出引脚无负载，所有数字输入引脚不浮动，所有外设关闭， Flash进入睡眠模式，CPU进入STOP模式。
	备注：进入STOP模式前应关闭相应的外设电路，如未使用到的IO尽量不要为悬浮状态(可设置为高阻态+上拉)，如下：
*************************************************************************************************************/
#ifdef WATCHDOG_ENABLE
		WDT_KILL();			//关闭看门狗
#endif

	ck_bak = CKCON & 0xFE;				//备份时钟状态 

 	LVDCON = 0;	//关闭LVD	
	I2CCON = 0;//关闭I2C功能，因为I2C默认是使能的，如果I2C不关闭将无法关闭IRCH时钟 	
/////////////////////外部中断唤醒需要打开/////////////////////////////////////////////////////////////
//使用外部中断 INT2/ INT3/ INT4 唤醒 MCU,在进入 STOP 前需把系统时钟设置为 IRCL 时钟，同时保持 IRCL 时钟打开。在 STOP 模式保持 IRCL 时钟运行	
////////////////////////////////////////////////////////////////////////////////////////////////
#if 0//功耗小于 20 uA  需关闭TMC功能
	CKCON = (CKCON&0x41)| ILCKE;		//IRCL时钟使能，并关闭其它时钟
	Delay_ms(1);						//使能IRCL后延时1ms，等待IRCL稳定
	CKCON = (CKCON&0xFE) | CKSEL_IRCL;	//系统时钟切换到IRCL	
#else
	 CKCON = 0;					//关闭所有时钟    静态功耗小于 7uA   外部中断0   外部中断1 可以唤醒 
#endif
	MECON |= BIT6;  //设置FLASH进入深度睡眠模式

	while(1)
	{
		#ifdef WATCHDOG_ENABLE
			WDT_FeedDog();			//喂看门狗
		#endif
		PCON = 0x02;
		_nop_();
		_nop_();
		_nop_();
		_nop_();

		if(Get_system_powersave_exit_proc())
		{
		#ifdef WATCHDOG_ENABLE
			WDT_FeedDog();			//喂看门狗
		#endif		
			break;
		}
	}
#ifdef HAVE_CHANGE_SYS_CLK	  //设置系统时钟频率
		#if (SYSCLK_SRC == IRCH_16M)
			Sys_Clk_Set_IRCH();
		#elif (SYSCLK_SRC == IRCH_8M)
			Sys_Clk_Set_HALF_IRCH();	
		#else
			Sys_Clk_Set_IRCL();
		#endif
#endif		
	MECON &= ~BIT6;	
	CKCON |= ck_bak;					//恢复所关闭的时钟	
#ifdef LVD_ENABLE
	LVD_init();
#endif	
	EA = 1;
#ifdef  HAVE_TIME0_EN	 
	Timer0_init();	   //定时器0初始化
#endif
#ifdef  HAVE_TIME1_EN	 
	Timer1_init();	   //定时器0初始化
#endif
#ifdef  HAVE_TIME2_EN
	Timer2_init();	   //定时器2初始化
#endif
#ifdef WATCHDOG_ENABLE
	WDT_init();
	WDT_FeedDog();			//喂看门狗
#endif
#ifdef HAVE_UART
	Uart_Initial();
#endif
}
#endif
#endif
