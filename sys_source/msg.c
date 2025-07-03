#ifndef MSG_C
#define MSG_C
#include "sys_include/sys_includes.h"
#include "user_source/user_includes.h"
#ifdef  HAVE_MSG
/********************************************************************************************************************/
//#define MSG_DBG

#define TOUCH_DEBUG  

/*********************************************************************************************************************/
/***********************************************************************************
������  ��		msg_initial										 	
����������		������Ϣ��ʼ��
���������		��
����ֵ  ��		��
***********************************************************************************/
void msg_initial(void)
{
		msg=0;
		f_key_invalid=0;
		msg_channel=0;
	  key_pressed = 0;
#ifdef HAVE_TOUCH_KEY
	_touch_init();
#endif
#ifdef HAVE_SCAN_KEY
	_scan_init();
#endif
}
/***********************************************************************************
������  ��		msg_timer_proc										 	
����������		������Ϣ��ʱ����������
���������		��
����ֵ  ��		��
***********************************************************************************/
void msg_timer_proc(void)
{
		if(msg_scan_timer) msg_scan_timer--;
		if(long_key_timer) long_key_timer--;		
}
/***********************************************************************************
������  ��		_get_msg										 	
����������		������Ϣ���
���������		��
����ֵ  ��		��
***********************************************************************************/
void _get_msg(void)
{
	static u8_t  msg_state=NO_ACTIVE;	
	static unsigned char debounce_cnt = 0;//,debounce_cnt2 = 0;
	static unsigned char last_key;
	unsigned char key=0;

#ifdef HAVE_TOUCH_KEY
	u8_t touth_msg=0;
#endif 
#ifdef HAVE_SCAN_KEY
	u8_t  scan_msg=0;
#endif 
	msg=KEY_INVALID;
//	if(!msg_scan_timer)
	{
		//msg_scan_timer = 1;
#ifdef HAVE_TOUCH_KEY
	touth_msg = _touth_get_msg();
#endif 
#ifdef HAVE_SCAN_KEY
	scan_msg = _scan_get_msg();
#endif 
  
	if(msg_state==NO_ACTIVE)
	{
		msg_channel = NO_ACTIVE;
		if(0)
		{
		
		}
#ifdef HAVE_TOUCH_KEY
		else if(touth_msg!=KEY_INVALID)
		{
			msg_state=TOUTH_ACTIVE;
			key=touth_msg;
			msg_channel = TOUTH_ACTIVE;
		}
#endif
#ifdef HAVE_SCAN_KEY
		else if(scan_msg!=KEY_INVALID)
		{
			msg_state=SCAN_ACTIVE;
			key=scan_msg;
			msg_channel = SCAN_ACTIVE;
		}
#endif		
	}
	else
	{
		switch(msg_state)
		{		
#ifdef HAVE_TOUCH_KEY
			case TOUTH_ACTIVE:
				key=touth_msg;
				break;
#endif		
#ifdef HAVE_SCAN_KEY
			case SCAN_ACTIVE:
				key=scan_msg;
				break;
#endif		
			default:
				break;
		}
	}
		if(!key_pressed)
		{
			if(key != 0)
			{
				debounce_cnt++;
				if(debounce_cnt > 2)
				{
					debounce_cnt = 0;
					key_long = 0;
					long_key_timer = LONG_KEY_START_TIME;
					key_pressed = 1;
					key_long_cnt = 0;
					last_key = key;	
					msg = key;	
				}	
			}
			else
			{
				msg_state=NO_ACTIVE;//�������̫�̣�����ס��ͬһ���Ͱ�������Ч�ϣ�
				debounce_cnt = 0;	
			}
		}
		else
		{
			if(key == 0)
			{
				debounce_cnt++;
				if(debounce_cnt > 2)
				{
					key_pressed = 0;
					msg_state=NO_ACTIVE;
					if(key_long)
					{	
						msg = 	(last_key|KEY_LONG_BREAK);
					}
					else
					{
						msg =	(last_key|KEY_BREAK);	
					}						
				}	
			}	
			else
			{
			    ///////////////������������������ͬʱ���£��л�������İ���ֵ/////////////////////////
				if(key != last_key)
				{
					last_key=key;
					msg=(u16_t)last_key;
					long_key_timer = LONG_KEY_START_TIME;
					key_long = 0;
				}
				//////////////////////////////////////////////////////////////////////
				if(!long_key_timer)
				{
					long_key_timer = LONG_KEY_TIME;	
					key_long_cnt++;
					if(key_long)
					{
						msg = (last_key | KEY_LONG);		
					}
					else
					{
						key_long = 1;
						msg = (last_key | KEY_LONG_START);	
					}
				}
			}
		}

	}
	/////////////ʹ�ܰ���ǰ�°����������������Ϣ��Чֱ������̧��/////////////////////////////
	if(f_key_invalid)
	{
		if(msg!=KEY_INVALID)
		{
			if((msg&KEY_BREAK))//||(msg&KEY_LONG_BREAK)
			{
				f_key_invalid=0;
			}
			msg=KEY_INVALID;
		}
	}
	/////////////////////////////////////////////////////////////////////////////////
#ifdef MSG_DBG	
	if(msg != KEY_INVALID)
	{
	#ifdef DEBUG_PRINTF_EN
		uart_printf("msg=0x%x\n",msg);
	#endif
	}
#endif 
}
#ifdef HAVE_TOUCH_KEY
#ifdef CA_TOUCH_KEY
/***********************************************************************************
������  ��		_touch_init										 	
����������		����������ʼ��
���������		��
����ֵ  ��		��
***********************************************************************************/
void _touch_init(void)
{
	TS_init();	
}
u16_t _get_touth_code(void)
{
	TS_Action();
//#if SUPPORT_WHEEL_SLIDER
//	if(WheelSliderPosition != -1)
//	{
//		//��WheelSliderPosition[n]������-1ʱ�� ��ʾ������Բ���д����¼�������WheelSliderPosition[n]��ֵ��ʾ������Բ����λ�á�
//	}
//#endif
#ifdef TOUCH_DEBUG	
	 if(KeysFlagSN)
	 {
		 Debug_UartSendByte(0x44);
		 Debug_UartSendByte(KeysFlagSN>>8);
		 Debug_UartSendByte(KeysFlagSN); 
	 }
#endif
	return KeysFlagSN;
}
code u16_t TOUCH_KEY_TAB[][2]=
{
	{0x0001,KEY_POWER},
	{0x0002,KEY_PLAY},
	{0x0004,KEY_STOP},
	{0x0008,KEY_VOL_UP},
	{0x0010,KEY_VOL_DN},
	{0x0080,KEY_NEXT},
	{0x0040,KEY_PREVIOUS},
	{0x0020,KEY_PROG},
};
/***********************************************************************************
������  ��		_touth_get_msg										 	
����������		������������
���������		��
����ֵ  ��		��
***********************************************************************************/
u8_t _touth_get_msg(void)
{
	static u8_t  touth_read_key_time;
	u8_t th_key = KEY_INVALID;
	u16_t touth_code;
	u8_t i;
	//if(touth_read_key_time-gp_10ms_timer>0)
	{
		touth_read_key_time = gp_10ms_timer;
		touth_code = _get_touth_code();
		for(i=0;i<sizeof(TOUCH_KEY_TAB)/2;i++)
		{
			if(touth_code == TOUCH_KEY_TAB[i][0])
			{
				th_key = TOUCH_KEY_TAB[i][1];		
				break;
			}
		}
	}
	return th_key;
}
#endif
#endif
#ifdef HAVE_SCAN_KEY
////////////////////io ��ɨ�谴���ܽ�����////////////////////////////
/***********************************************************************************
������  ��		_scan_init										 	
����������		ɨ�谴����ʼ��
���������		��
����ֵ  ��		��
***********************************************************************************/
void _scan_init(void)
{
	POWER_KEY_IN;
}
/***********************************************************************************
������  ��		_scan_get_msg										 	
����������		ɨ�谴������
���������		��
����ֵ  ��		��
***********************************************************************************/
u8_t _scan_get_msg(void)
{
	static u8_t read_scan_key_timer;
	static u8_t scan_key=KEY_INVALID;
	if(read_scan_key_timer-gp_10ms_timer>1)
	{
		read_scan_key_timer=gp_10ms_timer;
		////////////////////////����io ����////////////////////////////////////////
		if(POWER_KEY==0)
			scan_key = KEY_POWER;
		else	
			scan_key = KEY_INVALID;		
	    ////////////////////////io ��ɨ�谴��////////////////////////////////////////
	}
	return scan_key;
}
#endif
#endif
#endif
