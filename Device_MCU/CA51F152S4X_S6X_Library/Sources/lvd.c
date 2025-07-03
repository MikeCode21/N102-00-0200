#ifndef LVD_C
#define LVD_C
#include "includes\headfile.h"
#ifdef LVD_ENABLE
/******************************************************************************
��������	LVD_config
����������LVD��ʼ��
�������: LVDS_mode:  LVDS_reset��LVD��λ
											LVDS_int��LVD �ж�
				 LVDTH_value:  LVDTH_2_2V  
                       LVDTH_2_5V
                       LVDTH_2_7V
                       LVDTH_3_0V
                       LVDTH_3_3V
                       LVDTH_3_6V
                       LVDTH_3_9V
                       LVDTH_4_2V
����ֵ�� ��					

******************************************************************************/
void LVD_config(unsigned char LVDS_mode,unsigned char LVDTH_value)	
{
    LVDCON = LVDE(1) | LVDS_mode | LVDTH_value;	//����LVDʹ��,����LVDΪ�ж�ģʽ/��λģʽ,����ѹΪ
}
/******************************************************************************
��������	LVD_init
����������LVD��ʼ��
�������: ��
����ֵ�� ��					

******************************************************************************/
void LVD_init(void)	
{
	#ifdef LVD_RST_ENABLE
    LVD_config(LVDS_reset,LVDTH_2_7V);
	#else
	  LVD_config(LVDS_int,LVDTH_2_2V);
		INT4EN = 1; 								//INT4 �ж�ʹ��
	#endif
}
/******************************************************************************
��������	LVD_ISR_proc
����������LVD�жϷ������
�������: ��
����ֵ�� ��					

******************************************************************************/
void LVD_ISR_proc (void)	//LVD�жϷ������
{
	if(LVDCON & LVDF)
	{
		LVDCON |= LVDF;			    //���LVD�жϱ�־

	}		
}
/******************************************************************************
��������	LVD_proc
����������LVD�������
�������: 
����ֵ�� ��					

******************************************************************************/
void LVD_proc(void)
{

}
#endif
#endif