#ifndef LVD_C
#define LVD_C
#include "includes\headfile.h"
#ifdef LVD_ENABLE
/******************************************************************************
函数名：	LVD_config
功能描述：LVD初始化
输入参数: LVDS_mode:  LVDS_reset：LVD复位
											LVDS_int：LVD 中断
				 LVDTH_value:  LVDTH_2_2V  
                       LVDTH_2_5V
                       LVDTH_2_7V
                       LVDTH_3_0V
                       LVDTH_3_3V
                       LVDTH_3_6V
                       LVDTH_3_9V
                       LVDTH_4_2V
返回值： 无					

******************************************************************************/
void LVD_config(unsigned char LVDS_mode,unsigned char LVDTH_value)	
{
    LVDCON = LVDE(1) | LVDS_mode | LVDTH_value;	//设置LVD使能,设置LVD为中断模式/复位模式,检测电压为
}
/******************************************************************************
函数名：	LVD_init
功能描述：LVD初始化
输入参数: 无
返回值： 无					

******************************************************************************/
void LVD_init(void)	
{
	#ifdef LVD_RST_ENABLE
    LVD_config(LVDS_reset,LVDTH_2_7V);
	#else
	  LVD_config(LVDS_int,LVDTH_2_2V);
		INT4EN = 1; 								//INT4 中断使能
	#endif
}
/******************************************************************************
函数名：	LVD_ISR_proc
功能描述：LVD中断服务程序
输入参数: 无
返回值： 无					

******************************************************************************/
void LVD_ISR_proc (void)	//LVD中断服务程序
{
	if(LVDCON & LVDF)
	{
		LVDCON |= LVDF;			    //清除LVD中断标志

	}		
}
/******************************************************************************
函数名：	LVD_proc
功能描述：LVD处理程序
输入参数: 
返回值： 无					

******************************************************************************/
void LVD_proc(void)
{

}
#endif
#endif