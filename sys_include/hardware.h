#ifndef _HARDWARE_H
#define _HARDWARE_H
/***************************************************************************************
									ɨ�谴�� IO ����
****************************************************************************************/
#ifdef HAVE_SCAN_KEY
#define POWER_KEY_IN				P14_CFG_INPUT_PULL_UP
#define POWER_KEY						P14
#endif
/***************************************************************************************
									������Դ����
****************************************************************************************/
										
#define MAIN_POWER_OUT						_nop_()//P34_CFG_OUTPUT
#define MAIN_POWER_ON   					_nop_()//P34 = 0;
#define MAIN_POWER_OFF						_nop_()//P34 = 1;
																										
//////////////////////////////////////////////////////////////////////////////////////
#endif