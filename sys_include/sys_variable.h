#ifdef _MAIN_C_
	#define EXTERN 	
#else
	#define EXTERN 	extern 
#endif
/*****************************ϵͳ����**************************************************/
EXTERN unsigned char func_mode;			//ϵͳ����ģʽ
EXTERN unsigned char sub_state; 		//ϵͳ��ǰ��״̬
EXTERN unsigned char setting_state; //��ǰ����״̬
EXTERN unsigned char setting_timer; //��ǰ����ʱ�����
EXTERN unsigned char IRCL_fosc;//�ڲ�����ʱ��ʱ��Ƶ��(KHZ)
#ifdef HAVE_TIME0_EN	
EXTERN unsigned int   gp_1ms_timer;
EXTERN unsigned char  gp_100ms_timer;
EXTERN unsigned char  gp_10ms_timer;
EXTERN unsigned char  gp_1second_timer;
EXTERN unsigned char  flash_timer;	
#endif
#ifdef HAVE_SYSTEM_SLEEP
EXTERN unsigned int  xdata	enter_sleep_timer;
EXTERN unsigned char xdata enter_sleep_enable;
#endif

/*******************************************************************************************/

/*****************************������Ϣ����**************************************************/
#ifdef  HAVE_MSG	
EXTERN unsigned int xdata msg;
EXTERN bit f_key_invalid;
EXTERN unsigned char   msg_channel;
	
EXTERN unsigned char  msg_scan_timer;
EXTERN unsigned char  long_key_timer;
EXTERN unsigned char  key_long;
EXTERN unsigned char  key_pressed;
EXTERN unsigned char  key_long_cnt;	
#endif //end HAVE_MSG
/*******************************************************************************************/
/*******************************************************************************************/

/*******************************************************************************************/

/////////////////////////////////////////////end///////////////////////////////////////////////////////////
	
	