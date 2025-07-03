#ifndef _TS_API_H
#define _TS_API_H

#ifdef _TK_API_C_
/***************************************************************************************************************/
/***************************************************************************************************************/											
TSState_T 	  idata TS_State;

TYPE_SN idata PreKeysFlagSN;	
TYPE_SN xdata KeysFlagSN;	

unsigned int  TS_Key;	
unsigned int 	TS_LongKeyTimer;
unsigned char TK_State;	
bit 					TS_DataAcqDone;
unsigned char idata 	TS_Cnt;			
unsigned int 	xdata 	TS_RawData[OPENED_TS_COUNT];
unsigned int 	xdata 	TS_BaseLineData[OPENED_TS_COUNT];
unsigned int 	xdata 	TS_FirstAreaData[OPENED_TS_COUNT];
unsigned char xdata 	TS_AreaConfirmTimer[OPENED_TS_COUNT];
unsigned int 	xdata 	TS_PostData[OPENED_TS_COUNT];

unsigned int 	xdata 	TK_PULL_Value[OPENED_TS_COUNT];
unsigned int 	xdata 	ParPullValue;
#if SUPPORT_KEY
unsigned int 	xdata 	TSKey_FingerThd[KEY_CH_COUNT];
unsigned char xdata 	TSKey_LongTouchLimitTimer[KEY_CH_COUNT];
#else
unsigned int 	xdata 	TSKey_FingerThd[1];
#endif
/***************************************************************************************************************/
/***************************************************************************************************************/
unsigned int  xdata TS_FilterBuf[OPENED_TS_COUNT][FILTER_COUNT];	
unsigned char xdata TS_FilterPosIdx[OPENED_TS_COUNT];	

unsigned char TS_Index;
unsigned char idata TS_CH[OPENED_TS_COUNT];	
unsigned char xdata EnterStopScanTimer;
bit TS_AcqMode;
unsigned int xdata TS_SingleCHRawD;
bit TS_StableFlag;

#if SUPPORT_TOUCH_SLEEP_MODE
bit TS_SleepEn;
#endif
bit TMC_flag;

#if SUPPORT_KEY
#if TS_I2C_DEBUG
unsigned char 			xdata 	Key_Cnt_Debug;	
TSState_T 	  			xdata 	TS_State_Debug;
unsigned char 			xdata 	TS_CH_Debug[OPENED_TS_COUNT];	
unsigned int  			xdata 	TS_RefChBaseLineData;
unsigned int 				xdata 	TS_RefPostData;
unsigned long int   xdata 	KeysFlagSN_Debug;
#endif

#if SUPPORT_ANTI_WATER_FUNCTION
unsigned char PanalCoverJudgeTimer;
bit PanalCoverJudgeFlag;
#endif
#endif
#if SUPPORT_WHEEL_SLIDER
unsigned char xdata TSWheelSlider_TouchConfirmTimer;
unsigned char xdata TSWheelSlider_LongTouchLimitTimer;
unsigned char xdata WheelSliderState;
unsigned char xdata WheelSliderTouchFlag;
int xdata WheelSliderPosition;
unsigned char xdata WheelSliderRefCh;
unsigned int xdata WheelSliderCapRateFilter;
unsigned char xdata WheelSliderMaxIdx;
bit W_S_RefChSet;
#else
unsigned char xdata WheelSliderRefCh;
unsigned int 	xdata WheelSliderCapRateFilter;
unsigned char xdata WheelSliderMaxIdx;
#endif
unsigned char TS_BaseCh;
unsigned char ActiveTouchType;
#else
/***************************************************************************************************************/
/***************************************************************************************************************/											
extern TSState_T 	  idata TS_State;
#ifndef TS_SERVICE_C
extern TYPE_SN idata PreKeysFlagSN;	
extern TYPE_SN xdata KeysFlagSN;	
#endif
extern unsigned int  TS_Key;	
extern unsigned int  TS_LongKeyTimer;
extern unsigned char TK_State;	

extern bit TS_DataAcqDone;
extern unsigned char 	idata 	TS_Cnt;			
extern unsigned int 	xdata 	TS_RawData[];

extern unsigned int 	xdata 	TS_BaseLineData[];
extern unsigned int 	xdata 	TS_FirstAreaData[];
extern unsigned char 	xdata 	TS_AreaConfirmTimer[];
extern unsigned int 	xdata 	TS_PostData[];

extern unsigned int 	xdata 	TSKey_FingerThd[];
extern unsigned char 	xdata 	TSKey_LongTouchLimitTimer[];

/***************************************************************************************************************/
/***************************************************************************************************************/
extern unsigned char TS_Index;

extern unsigned char idata TS_CH[];	
extern unsigned char  TS_AcqCnt;
extern unsigned char xdata EnterStopScanTimer;

extern code unsigned int TS_CH_INFO_SEQ[][2];
extern bit TS_StableFlag;
extern bit TS_SleepEn;

extern unsigned char xdata TSWheelSlider_TouchConfirmTimer;
extern unsigned char xdata TSWheelSlider_LongTouchLimitTimer;

extern unsigned char xdata WheelSliderState;
extern unsigned char xdata WheelSliderTouchFlag;
extern int xdata WheelSliderPosition;
extern unsigned int xdata WheelSliderCapRateFilter;
extern unsigned char TS_BaseCh;
extern unsigned char ActiveTouchType;
extern unsigned char xdata WheelSliderRefCh;
extern bit W_S_RefChSet;
extern unsigned char xdata WheelSliderMaxIdx;
extern code unsigned int 	TS_KEY_CH_INFO_SEQ[][2];

extern code unsigned char WHEEL_SLIDER0_MAX_MIN_TAB[];
extern code unsigned char AREA_CONFIRM_TIME_TAB[];
extern code unsigned long int MASK_TAB[];
extern unsigned int 	xdata 	TK_PULL_Value[];

extern bit TMC_flag;
extern bit TS_AcqMode;
extern unsigned int xdata TS_SingleCHRawD;

#endif
#if TS_I2C_DEBUG	  
void I2C_ISR(void);
#endif

void TS_init(void);
void TS_Action(void);
void TS_GetKey(void);
void TS_EnterSleepMode(void);		
void TS_ISR(void);
void TS_MS_ISR(void);
void TS_HS_ISR(void);
void TMC_ISR(void);
void TS_TIMER_ISR(void);

#endif