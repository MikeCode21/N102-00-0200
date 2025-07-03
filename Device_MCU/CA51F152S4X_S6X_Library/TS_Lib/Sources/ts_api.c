#ifndef _TK_API_C_
#define _TK_API_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
#include "sys_include/sys_includes.h"
/*********************************************************************************************************************/

#ifdef CA_TOUCH_KEY	   
/*********************************************************************************************************************/
extern void TS_Debug_init(void);
void Debug_ParamLoad(void);

#if SUPPORT_KEY
code unsigned int TS_KEY_CH_INFO_SEQ[][2]=
{
	KEY_SEQ
};
#endif
#if SUPPORT_WHEEL_SLIDER
code unsigned char TS_WHEEL_SLIDER_CH_SEQ[]=
{
	WHEEL_SLIDER0_SEQ,
};
code unsigned char WHEEL_SLIDER0_MAX_MIN_TAB[]={WHEEL_SLIDER0_CH_MIN_RATE};
#else
code unsigned char WHEEL_SLIDER0_MAX_MIN_TAB[1]={0};
#endif	
#if SUPPORT_KEY	
code TYPE_SN MASK_TAB[]=
{
	0x0001,
#if (KEY_CH_COUNT > 1)
	0x0002,
#endif
#if (KEY_CH_COUNT > 2)
	0x0004,
#endif
#if (KEY_CH_COUNT > 3)
	0x0008,
#endif
#if (KEY_CH_COUNT > 4)
	0x0010,
#endif
#if (KEY_CH_COUNT > 5)
	0x0020,
#endif
#if (KEY_CH_COUNT > 6)
	0x0040,
#endif
#if (KEY_CH_COUNT > 7)
	0x0080,
#endif
#if (KEY_CH_COUNT > 8)
	0x0100,
#endif
#if (KEY_CH_COUNT > 9)
	0x0200,
#endif
#if (KEY_CH_COUNT > 10)
	0x0400,
#endif
#if (KEY_CH_COUNT > 11)
	0x0800,
#endif
#if (KEY_CH_COUNT > 12)
	0x1000,
#endif
#if (KEY_CH_COUNT > 13)
	0x2000,
#endif
#if (KEY_CH_COUNT > 14)
	0x4000,
#endif
#if (KEY_CH_COUNT > 15)
	0x8000,
#endif
#if (KEY_CH_COUNT > 16)
	0x10000,
#endif
#if (KEY_CH_COUNT > 17)
	0x20000,
#endif
#if (KEY_CH_COUNT > 18)
	0x40000,
#endif
#if (KEY_CH_COUNT > 19)
	0x80000,
#endif
#if (KEY_CH_COUNT > 20)
	0x100000,
#endif
#if (KEY_CH_COUNT > 21)
	0x200000,
#endif
#if (KEY_CH_COUNT > 22)
	0x400000,
#endif
#if (KEY_CH_COUNT > 23)
	0x800000,
#endif
#if (KEY_CH_COUNT > 24)
	0x1000000,
#endif
#if (KEY_CH_COUNT > 25)
	0x2000000,
#endif
#if (KEY_CH_COUNT > 26)
	0x4000000,
#endif
};
code unsigned char AREA_CONFIRM_TIME_TAB[]=
{
	FINGER_TOUCH_CONFIRM_TIME,
	AREA_PNOISE_PLUS_CONFIRM_TIME,
	AREA_PNOISE_CONFIRM_TIME,
	AREA_NNOISE_CONFIRM_TIME,
	AREA_OVERLOW_CONFIRM_TIME,
};
#else
code unsigned char AREA_CONFIRM_TIME_TAB[1]={0};
code unsigned int MASK_TAB[1]={0};
#endif
	  
void TS_IO_Pol_init(void)
{
	unsigned char i;
	for(i = 0; i < TS_Cnt; i++)
	{
		if(TS_CH[i] < 8)
		{
			P0 &= ~(1<<TS_CH[i]);
		}
		else if(TS_CH[i] < 16)
		{
			P1 &= ~(1<<(TS_CH[i]&0x07));
		}
		else if(TS_CH[i] < 24)
		{
			P2 &= ~(1<<(TS_CH[i]&0x07));
		}
		else 
		{
			P3 &= ~(1<<(TS_CH[i]&0x07));
		}
	}
}

void TMC_ISR(void)
{
	if(TMCON & TMF)			//毫秒中断
	{
		TMCON |= TMF;	
		TMC_flag = 1;
	}	
}
void TS_TIMER_ISR(void)	
{
	static unsigned char TmCnt = 0;

	TS_MS_ISR();
	if(TS_LongKeyTimer)
	{
		TS_LongKeyTimer--;		
	}	
	TmCnt++;
	if(TmCnt >= 125)
	{
		TmCnt = 0;
		TS_HS_ISR();
	}
}
void TS_MS_ISR (void)
{
	static unsigned char xdata ms_cnt = 0;
	unsigned char i;
 
	ms_cnt++;
	if(ms_cnt >= 4)
	{
		ms_cnt = 0;
		for(i = 0; i < TS_Cnt; i++)
		{
			if(TS_AreaConfirmTimer[i])
			{
				TS_AreaConfirmTimer[i]--;
			}
		}
#if SUPPORT_WHEEL_SLIDER	
		if(TSWheelSlider_TouchConfirmTimer)
		{
			TSWheelSlider_TouchConfirmTimer--;
		}
#endif
#if SUPPORT_KEY
#if SUPPORT_ANTI_WATER_FUNCTION
		if(PanalCoverJudgeTimer) PanalCoverJudgeTimer--;
#endif
#endif
	}	
}
void TS_HS_ISR (void)
{
#if SUPPORT_KEY
#if (FINGER_LONG_TOUCH_TIME_LIMIT > 0)
	unsigned char i;
#endif
#endif	
#if SUPPORT_KEY
#if (FINGER_LONG_TOUCH_TIME_LIMIT > 0)
	for(i = 0; i < KEY_CH_COUNT; i++)
	{
		if(TSKey_LongTouchLimitTimer[i])
		{
			TSKey_LongTouchLimitTimer[i]--;
		}
	}		
#endif
#endif
#if SUPPORT_WHEEL_SLIDER	
#if (WHEEL_SLIDER_LONG_TOUCH_TIME_LIMIT > 0)
	if(TSWheelSlider_LongTouchLimitTimer)
	{
		TSWheelSlider_LongTouchLimitTimer--;
	}
#endif
#endif
	if(EnterStopScanTimer)
	{
		EnterStopScanTimer--;
	}	
}
void TS_ISR (void)
{
	if(TKIE & TKIF(1))
	{
		TKIE |= TKIF(1);
		if(!TS_AcqMode)
		{
			TS_SingleCHRawD = (unsigned int)TKDH<<8 | (unsigned int)TKDL;
			TS_DataAcqDone = 1;
		}
		else 
		{
			TS_RawData[TS_Index] = 	(unsigned int)TKDH<<8 | (unsigned int)TKDL;
			TS_Index++;
			if(TS_Index >= TS_Cnt)
			{
				TS_DataAcqDone = 1;
			}
			else
			{
				TS_SuccesiveScanStart(TS_Index);
			}
		}
	}
}

void TS_DataFiltering(void)
{
	unsigned char i;
#if (FILTER_COUNT > 1)
	unsigned char j;
	unsigned int DataSum,DataMax,DataMin;
#endif
	for(i = 0; i < TS_Cnt; i++)
	{
#if (FILTER_COUNT == 1)
		TS_PostData[i] = TS_RawData[i];
#else
		TS_FilterPosIdx[i]++;
		if(TS_FilterPosIdx[i] >= FILTER_COUNT) 
		{
			TS_FilterPosIdx[i] = 0;
		}
		TS_FilterBuf[i][TS_FilterPosIdx[i]] = TS_RawData[i];
		
		DataSum = 0;
		DataMax = 0;
		DataMin = 0xFFFF;
	 	for(j = 0; j < FILTER_COUNT; j++)
		{
			DataSum += TS_FilterBuf[i][j];
#if (FILTER_COUNT > 2)
			if(TS_FilterBuf[i][j] > DataMax)
			{
				DataMax = TS_FilterBuf[i][j];
			}
			if(TS_FilterBuf[i][j] < DataMin)
			{
				DataMin = TS_FilterBuf[i][j];
			}
#endif
		}
#if (FILTER_COUNT == 2)
		TS_PostData[i] = (DataSum)/(FILTER_COUNT);	
#else
		TS_PostData[i] = (DataSum - DataMax - DataMin)/(FILTER_COUNT-2);	
#endif
#endif		
 	}		
}
void TS_PullCheck(unsigned int ts_dataTag)
{
	unsigned char i,j;
	for(i = 0; i < TS_Cnt; i++)	
	{
		if(CheckDataExceedRange(TS_BaseLineData[i],ts_dataTag,10))
		{
			TK_PULL_Value[i] = TS_PullTrace(i,ts_dataTag);
			TS_BaseLineData[i] = TS_SingleCHRawD;
			TS_FirstAreaData[i] = TS_SingleCHRawD;
			TS_AreaConfirmTimerSet(i,AREA_PNOISE);		
			for(j = 0; j < FILTER_COUNT; j++)
			{
				TS_FilterBuf[i][j] = TS_SingleCHRawD;
			}
			TS_FilterPosIdx[i] = 0;			
		}
	}
}
#if SUPPORT_KEY
void TSKey_DataDeal(void)
{
	unsigned char i;
	unsigned char  TouchArea,NowArea;		

#if SUPPORT_ANTI_WATER_FUNCTION
	unsigned char PanalToggleCount = 0;
#endif
	for(i = 0; i < KEY_CH_COUNT; i++)
	{	
		TouchArea = TS_GetDataArea(i,TS_FirstAreaData[i],NOISE_THRESHOLD,(bit)(PreKeysFlagSN & MASK_TAB[i]));
		NowArea   = TS_GetDataArea(i,TS_PostData[i],NOISE_THRESHOLD,(bit)(PreKeysFlagSN & MASK_TAB[i]));
		if((NowArea != AREA_PNOISE)&&(NowArea != AREA_NNOISE))
		{
			TS_StableFlag = 0;		
		}
#if SUPPORT_ANTI_WATER_FUNCTION
		if((NowArea == AREA_PNOISE_PLUS) || (NowArea == AREA_FINGER_TOUCH))
		{
			PanalToggleCount++;
		}
#endif
		if(TouchArea == AREA_FINGER_TOUCH)
		{
			if(NowArea == AREA_FINGER_TOUCH)
			{
				if(!(PreKeysFlagSN & MASK_TAB[i]))
				{
					if(!TS_AreaConfirmTimer[i])
					{		
						PreKeysFlagSN |= MASK_TAB[i];		
#if (FINGER_LONG_TOUCH_TIME_LIMIT > 0)
						TSKey_LongTouchLimitTimer[i] = FINGER_LONG_TOUCH_TIME_LIMIT;
#endif
						TS_AreaConfirmTimer[i] = FINGER_TOUCH_RELEASE_CONFIRM_TIME;	
					}
				}
				else
				{						
					TS_AreaConfirmTimer[i] = FINGER_TOUCH_RELEASE_CONFIRM_TIME;
#if (FINGER_LONG_TOUCH_TIME_LIMIT > 0)
					if(!TSKey_LongTouchLimitTimer[i])
					{
						PreKeysFlagSN &= ~MASK_TAB[i];
						TS_FirstAreaData[i] = TS_PostData[i];
						TS_BaseLineData[i] 	= TS_PostData[i];
						TS_AreaConfirmTimerSet(i,AREA_PNOISE);				
					}							
#endif					
				}				
			}
			else
			{
				if(PreKeysFlagSN & MASK_TAB[i]) 
				{
					if(!TS_AreaConfirmTimer[i])
					{
						PreKeysFlagSN &= ~MASK_TAB[i];
						TS_FirstAreaData[i] = TS_BaseLineData[i];
						TS_AreaConfirmTimerSet(i,AREA_PNOISE);
					}					
				}			
				else
				{
					TS_FirstAreaData[i] = TS_PostData[i];
					TS_AreaConfirmTimerSet(i,NowArea);
				}	
			}	
			continue;						
		}	
		else
		{
			if(NowArea == AREA_FINGER_TOUCH)
			{
				TS_FirstAreaData[i] = TS_PostData[i];
				TS_AreaConfirmTimerSet(i,AREA_FINGER_TOUCH);
				continue;		
			}	
			else			
			{
				if(PreKeysFlagSN & MASK_TAB[i]) 
				{
					PreKeysFlagSN &= ~MASK_TAB[i];
					TS_FirstAreaData[i] = TS_BaseLineData[i];
					TS_AreaConfirmTimerSet(i,AREA_PNOISE);				
				}
			}
		}
		if(PreKeysFlagSN != 0) 
		{
			TS_FirstAreaData[i] = TS_BaseLineData[i];
			TS_AreaConfirmTimerSet(i,AREA_PNOISE);		
			continue;			
		}
		if(TS_AreaDeviateDetection(TS_FirstAreaData[i],TS_PostData[i],NOISE_THRESHOLD))	   //判断偏差是否在允许范围内
		{	
			if(!TS_AreaConfirmTimer[i])
			{
				TS_FirstAreaData[i] = TS_PostData[i];
				TS_BaseLineData[i] 	= TS_PostData[i];		
				TS_AreaConfirmTimerSet(i,AREA_PNOISE);	
			}	
		}
		else
		{
			TS_FirstAreaData[i] = TS_PostData[i];	
			TS_AreaConfirmTimerSet(i,NowArea);		
		}
	}
	KeysFlagSN  = PreKeysFlagSN;	
#if SUPPORT_ANTI_WATER_FUNCTION
	if(!PanalCoverJudgeFlag)
	{
		if(PreKeysFlagSN != 0)
		{
			if(KeysFlagSN == 0)
			{
				PanalCoverJudgeFlag = 1;
				PanalCoverJudgeTimer = PANAL_COVER_JUDGE_TIME; 		
			}
			else
			{
				if(PanalToggleCount >= JUDGE_TK_NUM)
				{
					PreKeysFlagSN = 0;
					PanalCoverJudgeFlag = 0;
					TS_BaseLineForceUpdate();
				}
				KeysFlagSN  = PreKeysFlagSN;
			}
		}
		else
		{
			KeysFlagSN  = PreKeysFlagSN;
		}
	}
	else
	{
		if(!PanalCoverJudgeTimer)
		{
			PanalCoverJudgeFlag = 0;
			KeysFlagSN = PreKeysFlagSN;
		}
		else
		{
			if(PanalToggleCount >= JUDGE_TK_NUM)
			{
				PreKeysFlagSN = 0;
				PanalCoverJudgeFlag = 0;
				TS_BaseLineForceUpdate();
			}			
		}
	}
#endif
	if(KeysFlagSN != 0) 
	{
		ActiveTouchType = 1;
	}
	else
	{
		ActiveTouchType = 0;
	}
}
#endif
#if SUPPORT_WHEEL_SLIDER
void TS_WheelSliderDeal(void)
{
	unsigned char i;
	unsigned int   Delta,Position;
	bit WheelSliderTogFlag = 0;
	TS_BaseCh = KEY_CH_COUNT; 
	if(!W_S_RefChSet)
	{
		W_S_RefChSet = 1;		
		SetWheelSliderRefCh(WHEEL_SLIDER0_CH_COUNT);
	}
	
#if PRINT_WHEEL_SLIDER_DATA_EN
	for(i = TS_BaseCh; i < TS_BaseCh + WHEEL_SLIDER0_CH_COUNT; i++)
	{						
		if(TS_BaseLineData[i] > TS_PostData[i])
		{
			Delta = (int)TS_BaseLineData[i] - (int)TS_PostData[i];	
		}
		else
		{
			Delta = 0;
		}
		uart_printf("ch%d= %d,",(int)i,TS_PostData[i]);
		uart_printf("%d ,%d  ",TS_BaseLineData[i],Delta);						
	}				
	uart_printf("\n");
#endif
#if (WHEEL_OR_SLIDER_DEF0	== SLIDER)
	Position = SliderTouchJudge(WHEEL_SLIDER0_CH_COUNT,WHEEL_SLIDER0_TOUCH_THD);
#elif (WHEEL_OR_SLIDER_DEF0	== WHEEL)
	Position = WheelTouchJudge(WHEEL_SLIDER0_CH_COUNT,WHEEL_SLIDER0_TOUCH_THD);
#endif
	if(Position != -1)
	{
		TS_StableFlag = 0;
	}
	if(WheelSliderState == WHEEL_SLIDER_NO_TOUCH)
	{
		if(!WheelSliderTouchFlag)
		{
			if(Position != -1)
			{
				WheelSliderTouchFlag = 1;	
				TSWheelSlider_TouchConfirmTimer = WHEEL_SLIDER_TOUCH_CONFIRM_TIME;				
			}
			else
			{
				for(i = TS_BaseCh; i < TS_BaseCh + WHEEL_SLIDER0_CH_COUNT; i++)
				{						
					if(TS_FirstAreaData[i] > TS_PostData[i]) 
					{
						Delta 	= TS_FirstAreaData[i] - TS_PostData[i];
					}
					else
					{
						Delta 	= TS_PostData[i] - TS_FirstAreaData[i];
					}					
					if(Delta <= WHEEL_SLIDER0_NOISE_THD) 
					{
						if(!TS_AreaConfirmTimer[i])
						{
							TS_FirstAreaData[i] = TS_PostData[i];
							TS_BaseLineData[i] 	= TS_PostData[i];
							TS_AreaConfirmTimer[i] = WHEEL_SLIDER_BASELINE_UPDATE_TIME;
						}							
					}
					else
					{
						TS_FirstAreaData[i] = TS_PostData[i];
						TS_AreaConfirmTimer[i] = WHEEL_SLIDER_BASELINE_UPDATE_TIME;
					}
				}
			}			
		}	
		else
		{	
			if(Position != -1)
			{
				if(!TSWheelSlider_TouchConfirmTimer)
				{
						WheelSliderState = WHEEL_SLIDER_TOUCH;	
#if (WHEEL_SLIDER_LONG_TOUCH_TIME_LIMIT > 0)
						TSWheelSlider_LongTouchLimitTimer = WHEEL_SLIDER_LONG_TOUCH_TIME_LIMIT;
#endif
				}	
			}
			else
			{
				WheelSliderTouchFlag = 0;
				for(i = TS_BaseCh; i < TS_BaseCh + WHEEL_SLIDER0_CH_COUNT; i++)
				{
					TS_AreaConfirmTimer[i] = WHEEL_SLIDER_BASELINE_UPDATE_TIME;
				}
			}
		}				
	}
	else if(WheelSliderState == WHEEL_SLIDER_TOUCH)
	{		
#if (WHEEL_SLIDER_LONG_TOUCH_TIME_LIMIT > 0)
		if(!TSWheelSlider_LongTouchLimitTimer)
		{
			for(i = TS_BaseCh; i < TS_BaseCh + WHEEL_SLIDER0_CH_COUNT; i++)
			{
				TS_FirstAreaData[i] = TS_PostData[i];
				TS_BaseLineData[i] 	= TS_PostData[i];
			}
			WheelSliderTouchFlag = 0;
			goto WHEEL_SLIDER_RELEASE;
		}
#endif
		if(WheelSliderTouchFlag)
		{
			if(Position == -1)	
			{
				WheelSliderTouchFlag = 0;
				TSWheelSlider_TouchConfirmTimer = WHEEL_SLIDER_TOUCH_RELEASE_CONFIRM_TIME;		
			}
		}
		else						 
		{
			if(Position == -1)	
			{
				if(!TSWheelSlider_TouchConfirmTimer)
				{
WHEEL_SLIDER_RELEASE:
					WheelSliderState = WHEEL_SLIDER_NO_TOUCH;	
					WheelSliderCapRateFilter = 0;
					WheelSliderPosition = -1;
					for(i = TS_BaseCh; i < TS_BaseCh + WHEEL_SLIDER0_CH_COUNT; i++)
					{
						TS_AreaConfirmTimer[i] = WHEEL_SLIDER_BASELINE_UPDATE_TIME;
					}
				}
			}
			else
			{
				WheelSliderTouchFlag = 1;				
			}
		}		
	}		
	if(WheelSliderState == WHEEL_SLIDER_TOUCH)
	{
		if(Position != -1)
		{
			WheelSliderPosition = Position;
		}	
#if PRINT_WHEEL_SLIDER_POSITION_EN
		uart_printf("pos = %d \n",WheelSliderPosition);
#endif
#if PRINT_WHEEL_SLIDER_RATE_EN
		{
			unsigned char DeltaRate;
			DeltaRate = WheelSliderCapRateFilter/4;
			uart_printf("ch%d rate = %d \n",(int)WheelSliderMaxIdx,(int)DeltaRate);				
		}
#endif
	}
	else
	{
		WheelSliderPosition = -1;	
	}

	if(WheelSliderPosition != -1)
	{
		ActiveTouchType = 2;
	}
	else
	{
		ActiveTouchType = 0;
	}
}
#endif	
 

void TS_init(void)
{
	unsigned char i,ch_idx;
#if (TS_I2C_DEBUG)
	TS_Debug_init();
#endif
	TS_Cnt 		= OPENED_TS_COUNT;
	ch_idx = 0;
	for(i = 0;i < OPENED_TS_COUNT; i++)
	{
#if (SUPPORT_KEY && SUPPORT_WHEEL_SLIDER)
		if(i < KEY_CH_COUNT)
		{
			TS_CH[ch_idx++] = TS_KEY_CH_INFO_SEQ[i][0];
			
		}
		else
		{
			TS_CH[ch_idx++] = TS_WHEEL_SLIDER_CH_SEQ[i-KEY_CH_COUNT];
		}
#elif SUPPORT_KEY
		TS_CH[ch_idx++] = TS_KEY_CH_INFO_SEQ[i][0];
#elif SUPPORT_WHEEL_SLIDER
		TS_CH[ch_idx++] = TS_WHEEL_SLIDER_CH_SEQ[i];
#endif
	}
	TS_IO_Pol_init();
//	Timer1_init();
	TS_DataAcqDone = 0;
#if SUPPORT_KEY
	KeysFlagSN = 0;
	PreKeysFlagSN = 0;
#endif	
	ActiveTouchType = 0;
#if SUPPORT_KEY
#if SUPPORT_ANTI_WATER_FUNCTION
	PanalCoverJudgeFlag = 0;
#endif
#endif

#if SUPPORT_TOUCH_SLEEP_MODE
	EnterStopScanTimer = ENTER_STOP_MODE_TIME;
  TS_SleepEn = 1;
#endif
#if SUPPORT_WHEEL_SLIDER
	W_S_RefChSet = 0;

	WheelSliderState = WHEEL_SLIDER_NO_TOUCH;
	WheelSliderTouchFlag = 0;
	WheelSliderPosition = -1;		
	WheelSliderCapRateFilter = 0;
#endif
	TS_State = TS_INIT;
	
#if SUPPORT_KEY	
#if GENERATE_TS_KEY_EN
	TK_State = TK_STATE_RELEASE;
	TS_Key = 0;
#endif
#endif
}

void TS_Action(void)
{
	unsigned char i,j;
	switch(TS_State)
	{
		case TS_INIT:
			TKPULLTRIM = 0x3f;
			CKCON |= ILCKE|TKCKE;
			TKIE = TKIE_(1) | TKIF(1);
			INT3EN = 1; 
#if SUPPORT_TOUCH_SLEEP_MODE
			TKCFG1 =  TKEN(1) | TKDIV(TS_SLP_DIV);
			TKCFG2 = TKPULL8(0) | PAREN(1) | TKCADDR(0);
			TKCFG3 = RESO(TS_SLP_RESO) | TKCKSEL(TS_SLP_DS) | CHGSEL(1) | DCHGSEL(1);
			TKCFG4 = RBSEL(TS_SLP_RB) | VRSEL(TS_SLP_VRSEL);		
			ParPullValue = TS_PullTrace(0xff,SLP_TRACE_LINE_TAG);
#ifdef PRINT_EN
			uart_printf("parpu=%d\n",ParPullValue);
#endif
#endif
			TKCFG1 =  TKEN(1) | TKDIV(TS_DIV);
			TKCFG2 = TKPULL8(0) | PAREN(0) | TKCADDR(0);
			TKCFG3 = RESO(TS_RESO) | TKCKSEL(TS_DS) | CHGSEL(1) | DCHGSEL(1);
			TKCFG4 = RBSEL(TS_RB) | VRSEL(TS_VRSEL);		
			for(i = 0; i < TS_Cnt; i++)
			{
				TK_PULL_Value[i] = TS_PullTrace(i,TRACE_LINE_TAG);
				TS_BaseLineData[i] = TS_SingleCHRawD;
				TS_FirstAreaData[i] = TS_SingleCHRawD;				
#if (SUPPORT_KEY && SUPPORT_WHEEL_SLIDER)
				if(i < KEY_CH_COUNT)
				{
					TS_AreaConfirmTimerSet(i,AREA_PNOISE);	
					TSKey_FingerThd[i] = TS_KEY_CH_INFO_SEQ[i][1];						
				}
				else
				{
					TS_AreaConfirmTimer[i] = WHEEL_SLIDER_BASELINE_UPDATE_TIME;
				}
#elif SUPPORT_KEY
				TSKey_FingerThd[i] = TS_KEY_CH_INFO_SEQ[i][1];
				TS_AreaConfirmTimerSet(i,AREA_PNOISE);				
#elif SUPPORT_WHEEL_SLIDER
				TS_AreaConfirmTimer[i] = WHEEL_SLIDER_BASELINE_UPDATE_TIME;
#endif			
				for(j = 0; j < FILTER_COUNT; j++)
				{
					TS_FilterBuf[i][j] = TS_SingleCHRawD;
				}
				TS_FilterPosIdx[i] = 0;				
			}
			TS_Index = 0;
			TS_SuccesiveScanStart(TS_Index);
			TS_DataAcqDone = 0;
			TS_State = TS_DEAL;
			break;
		case TS_DEAL:		
			if(TS_DataAcqDone)
			{			
				TS_DataAcqDone = 0;
				TS_StableFlag = 1;
				TS_DataFiltering();
#if SUPPORT_KEY	
				if(ActiveTouchType != 2)
				{
					TSKey_DataDeal();	
				}
#endif
				TS_PullCheck(TRACE_LINE_TAG);
#if (TS_I2C_DEBUG)
				Debug_ParamLoad();
#endif	
#if SUPPORT_WHEEL_SLIDER
				if(ActiveTouchType != 1)
				{
					TS_WheelSliderDeal();
				}
#endif		
#if SUPPORT_TOUCH_SLEEP_MODE
				if(!TS_StableFlag || !TS_SleepEn || (PCON & 0x04))	// 在仿真模式不进入STOP模式
				{
					EnterStopScanTimer = ENTER_STOP_MODE_TIME;
				}			
				if(!EnterStopScanTimer&&TS_SleepEn)
				{
					TS_EnterSleepMode();		
				}
#endif	
				TS_Index = 0;
				TS_SuccesiveScanStart(TS_Index);				
			}
			break;
		default:
			break;
	}
#if SUPPORT_KEY	
#if GENERATE_TS_KEY_EN
	TS_GetKey();
#endif
#endif
}
unsigned char CheckDataExceedRange(unsigned int d_in,unsigned int d_tag,unsigned char percent)
{
	unsigned int tmp;
	tmp = ((unsigned long)d_tag*(unsigned long)percent)/100;
	
	if((d_in > (d_tag + tmp)) || (d_in < (d_tag - tmp)))
	{
		return 1;
	}
	return 0;
}
#if SUPPORT_TOUCH_SLEEP_MODE
void TS_SleepEnterUserCode(void)
{

}
void TS_SleepExitUserCode(void)
{

}
void TS_EnterSleepMode(void)
{
	unsigned char 	i;
	unsigned int 	prevRawD1,prevRawD2,RawDSum,RawAver;
	unsigned char 	acq_cnt;
	TS_SleepEnterUserCode();
	
	TKCFG1 =  TKEN(1) | TKDIV(TS_SLP_DIV);
	TKCFG2 = TKPULL8(0) | PAREN(1) | TKCADDR(0);
	TKCFG3 = RESO(TS_SLP_RESO) | TKCKSEL(TS_SLP_DS) | CHGSEL(1) | DCHGSEL(1);

	TKPULL = 0;	
	TKCFG4 = RBSEL(TS_SLP_RB) | VRSEL(TS_SLP_VRSEL);
	TKIE = TKIE_(1) | TKIF(1);
	
	LVDCON = 0;		
	I2CCON = 0;		
	MECON |= (1<<6);
	
	TMCON = TME(1);
	TMCON |= TMF;	
	TMSNU = 0;
	INT3EN = 1; 
	CKCON |= ILCKE;						//IRCL时钟使能
#if (!SLEEP_MODE_DEBUG)
	CKCON = (CKCON&0xFE) | CKSEL_IRCL;	//系统时钟切换到IRCH	
#endif
	TMC_flag = 0;
	acq_cnt = 0;
	while(1)
	{
		WDFLG = 0xA5;		
		_nop_();
		_nop_();
		_nop_();
		PCON = 0x02;
		_nop_();
		_nop_();
		_nop_();
		if(TMC_flag)			
		{
			TMC_flag = 0;
			CKCON = ILCKE|TKCKE;
			TKCFG1 |= TKEN(1);
			TS_SingleAcqStart(0xff,ParPullValue);	
			while(!TS_DataAcqDone);
			TS_DataAcqDone = 0;
			TS_SleepSetTKChPin(0);
			CKCON = ILCKE;
			TKCFG1 &=  ~TKEN(1);
						
			if(acq_cnt < 10)
			{
				acq_cnt++;	
			}
			if(acq_cnt == 3)
			{
				prevRawD1 = TS_SingleCHRawD;
				prevRawD2 = TS_SingleCHRawD;
				RawDSum = TS_SingleCHRawD*4;
				TMSNU = SLEEP_MODE_SCAN_INTERVAL_TIME/4;	
			}
			else if(acq_cnt > 3)
			{
				int delta;
				RawDSum -=  RawDSum/4;
				RawDSum += prevRawD2;
				RawAver = RawDSum/4;
				delta = (int)(RawAver) - (int)TS_SingleCHRawD;		
#if SLEEP_MODE_DEBUG
				uart_printf("par ch=%d  ",TS_SingleCHRawD);
				uart_printf("base=%d  ",RawAver);
				uart_printf("dif=%d\n",delta);
				Delay_ms(5);
#endif
				if(delta > SLEEP_TOUTH_THD)
				{
					for(i = 0 ; i < 3; i++)
					{
						CKCON = ILCKE|TKCKE;
						TKCFG1 |= TKEN(1);
						TS_SingleAcqStart(0xff,ParPullValue);	
						while(!TS_DataAcqDone);
						TS_DataAcqDone = 0;
						TS_SleepSetTKChPin(0);
						CKCON = ILCKE;
						TKCFG1 &=  ~TKEN(1);
						
						delta = (int)prevRawD2 - (int)TS_SingleCHRawD;
					
						if(delta < SLEEP_TOUTH_THD)
						{
							break;
						}
					}
					if(i == 3)
					{
						goto SLEEP_EXIT;
					}
				}
				else
				{
					prevRawD2 = prevRawD1;
					prevRawD1 = TS_SingleCHRawD;
					
					if(CheckDataExceedRange(TS_SingleCHRawD,SLP_TRACE_LINE_TAG,10))						
					{
						CKCON = ILCKE|TKCKE;
						TKCFG1 |= TKEN(1);
						ParPullValue = TS_PullTrace(0xff,SLP_TRACE_LINE_TAG);
						TS_SleepSetTKChPin(0);
						CKCON = ILCKE;
						TKCFG1 &=  ~TKEN(1);
						acq_cnt = 0;
						TMSNU = 0;	
					}
				}
			}
		}
	}
SLEEP_EXIT:
	LVDCON = 0xE2;
	Sys_Clk_Set_IRCH();

	TMCON &= ~TME(1);
	TMCON |= TMF;

	TKCFG1 =  TKEN(1) | TKDIV(TS_DIV);
	TKCFG2 = TKPULL8(0) | PAREN(0) | TKCADDR(0);
	TKCFG3 = RESO(TS_RESO) | TKCKSEL(TS_DS) | CHGSEL(1) | DCHGSEL(1);
	TKPULL = 0;	
	TKCFG4 = RBSEL(TS_RB) | VRSEL(TS_VRSEL);
	TKIE = TKIE_(1) | TKIF(1);
	CKCON |= TKCKE;	
	EnterStopScanTimer = ENTER_STOP_MODE_TIME;
	TS_SleepExitUserCode();
}
#endif
/*********************************************************************************************************************/
#if SUPPORT_KEY	
#if GENERATE_TS_KEY_EN
#if GENERATE_DOUBLE_KEY_EN
typedef struct 
{	
	unsigned char 	TogKeyNum;
	unsigned char 	TogKeyList[2];
}
T_TogKeyInfo;
#endif
code unsigned char TS_KEY_TAB[]=
{
	K1,K2,K3,K4,K5,K6,K7,K8,K9,K10,K11,K12,K13,K14,K15,K16,K17,K18,K19,K20,K21,K22,K23,K24,K25,K26
};
#if GENERATE_DOUBLE_KEY_EN
void TS_GetTogKeyInfor(T_TogKeyInfo *pKeyInfo)
{
	unsigned char i,index;
	pKeyInfo->TogKeyNum = 0;
	index = 0;
	for(i = 0; i < KEY_CH_COUNT; i++)
	{
		if(KeysFlagSN & MASK_TAB[i])
		{
			pKeyInfo->TogKeyNum++;
			
			if(pKeyInfo->TogKeyNum <= 2)
			{
				pKeyInfo->TogKeyList[index++] = TS_KEY_TAB[i];
			}
		}
	}
}
#endif
void TS_GetKey(void)
{
	static unsigned int KeyBak;	
	static bit LongFlag;
#if GENERATE_DOUBLE_KEY_EN
	T_TogKeyInfo KeyInfo;
	TS_GetTogKeyInfor(&KeyInfo);
#else
	static unsigned char KeyidxBak;
	unsigned char i;
#endif
	TS_Key = 0;	
	if(TK_State == TK_STATE_RELEASE)
	{
#if GENERATE_DOUBLE_KEY_EN
		if(KeyInfo.TogKeyNum != 0)
		{			
			if(KeyInfo.TogKeyNum == 1)
			{
				KeyBak = (unsigned int)KeyInfo.TogKeyList[0];
				TK_State = TK_STATE_SINGLE_KEY_PRESS;				
			}
			else if(KeyInfo.TogKeyNum == 2)
			{
				KeyBak = ((unsigned int)KeyInfo.TogKeyList[0]<<5)|(unsigned int)KeyInfo.TogKeyList[1];
				TK_State = TK_STATE_DOUBLE_KEY_PRESS;
			}
			TS_Key = KeyBak;
			LongFlag = 0;
			TS_LongKeyTimer = TS_LONG_START_TIME;
		}
#else
		if(KeysFlagSN != 0)
		{
			for(i = 0; i < KEY_CH_COUNT; i++)
			{
				if(KeysFlagSN & MASK_TAB[i])
				{
					KeyidxBak = i;
					KeyBak = TS_KEY_TAB[i];
					break;
				}		
			}				
			TS_Key = KeyBak;
			LongFlag = 0;
			TS_LongKeyTimer = TS_LONG_START_TIME;
			TK_State = TK_STATE_SINGLE_KEY_PRESS;		
		}
#endif
	}
	else if(TK_State == TK_STATE_SINGLE_KEY_PRESS)
	{
#if GENERATE_DOUBLE_KEY_EN	
		if(KeyInfo.TogKeyNum == 1)
		{
			if(KeyBak == (unsigned int)KeyInfo.TogKeyList[0])
			{
				if(!TS_LongKeyTimer)
				{
					if(!LongFlag)
					{
						LongFlag = 1;
						TS_Key = KeyBak | KEY_LONG_START;
					}
					else
					{
						TS_Key = KeyBak | KEY_LONG;
					}
					TS_LongKeyTimer = TS_LONG_TIME;
				}				
			}
			else 
			{
				if(!LongFlag)
				{
					TS_Key = KeyBak | KEY_BREAK;
				}
				else
				{
					TS_Key = KeyBak | KEY_LONG_BREAK;
				}
				TK_State = TK_STATE_RELEASE;
			}
		}
		else if(KeyInfo.TogKeyNum == 2)
		{
			KeyBak = ((unsigned int)KeyInfo.TogKeyList[0]<<5) | (unsigned int)KeyInfo.TogKeyList[1];
			TK_State = TK_STATE_DOUBLE_KEY_PRESS;
			TS_Key = KeyBak;
			LongFlag = 0;
			TS_LongKeyTimer = TS_LONG_START_TIME;
		}
		else if(KeyInfo.TogKeyNum == 0)
		{
			if(!LongFlag)
			{
				TS_Key = KeyBak | KEY_BREAK;
			}
			else
			{
				TS_Key = KeyBak | KEY_LONG_BREAK;
			}
			TK_State = TK_STATE_RELEASE;
		}
#else
		if(KeysFlagSN & MASK_TAB[KeyidxBak])
		{
				if(!TS_LongKeyTimer)
				{
					if(!LongFlag)
					{
						LongFlag = 1;
						TS_Key = KeyBak | KEY_LONG_START;
					}
					else
					{
						TS_Key = KeyBak | KEY_LONG;
					}
					TS_LongKeyTimer = TS_LONG_TIME;
				}					
		}
		else
		{
			if(!LongFlag)
			{
				TS_Key = KeyBak | KEY_BREAK;
			}
			else
			{
				TS_Key = KeyBak | KEY_LONG_BREAK;
			}
			TK_State = TK_STATE_RELEASE;			
		}
#endif
	}
#if GENERATE_DOUBLE_KEY_EN	
	else if(TK_State == TK_STATE_DOUBLE_KEY_PRESS)
	{
		if(KeyInfo.TogKeyNum == 2)
		{
			if(KeyBak == ((unsigned int)KeyInfo.TogKeyList[0]<<5)|(unsigned int)KeyInfo.TogKeyList[1])
			{
				if(!TS_LongKeyTimer)
				{
					if(!LongFlag)
					{
						LongFlag = 1;
						TS_Key = KeyBak | KEY_LONG_START;
					}
					else
					{
						TS_Key = KeyBak | KEY_LONG;
					}
					TS_LongKeyTimer = TS_LONG_TIME;
				}					
			}
		}
		else if(KeyInfo.TogKeyNum == 0)
		{
			if(!LongFlag)
			{
				TS_Key = KeyBak | KEY_BREAK;
			}
			else
			{
				TS_Key = KeyBak | KEY_LONG_BREAK;
			}
			TK_State = TK_STATE_RELEASE;		
		}
	}
#endif
#if PRINT_TS_KEY_EN
	if(TS_Key != 0)
	{
		if((TS_Key & 0xFF00) == 0)
		{
#if GENERATE_DOUBLE_KEY_EN	
			if(TS_Key > 0x1F)
			{	
				uart_printf("double key = %d   ",(int)TS_Key);
			}
			else
#endif				
			{
				uart_printf("single key = %d   ",(int)TS_Key);	
			}
		}
		else if(TS_Key & KEY_BREAK)
		{
			uart_printf("key up!\n");	
		}
		else if(TS_Key & KEY_LONG_START)
		{
			uart_printf("long start  ");				
		}
		else if(TS_Key & KEY_LONG)
		{
			uart_printf("long  ");		
		}
	}
#endif
}
#endif
#endif
/*********************************************************************************************************************/
#endif
/*********************************************************************************************************************/
#endif