#ifdef _MAIN_C_
	#define EXTERN 	
#else
	#define EXTERN 	extern 
#endif
/*****************************系统变量**************************************************/
EXTERN unsigned char func_mode;			//系统工作模式
EXTERN unsigned char sub_state; 		//系统当前的状态
EXTERN unsigned char setting_state; //当前设置状态
EXTERN unsigned char setting_timer; //当前设置时间变量
EXTERN unsigned char IRCL_fosc;//内部低速时钟时钟频率(KHZ)
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

/*****************************输入消息变量**************************************************/
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
	
	