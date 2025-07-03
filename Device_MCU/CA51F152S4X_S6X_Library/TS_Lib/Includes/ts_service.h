#ifndef _TS_SERVICE_H_
#define _TS_SERVICE_H_

//void TS_IO_Pol_init(void);
void TS_SuccesiveScanStart(unsigned char ch_idx);
void TS_SingleAcqStart(unsigned char ch_idx,unsigned int pull);
void TS_SetChPin(unsigned char ch_idx);
void TS_SleepSetTKChPin(unsigned char mode);
unsigned char CheckDataExceedRange(unsigned int d_in,unsigned int d_tag,unsigned char percent);
unsigned int TS_PullTrace(unsigned char ch_idx,unsigned int ts_dataTag);
void TSKey_DataDeal(void);
void TS_AreaConfirmTimerSet(unsigned char ts_ch, unsigned char area);
unsigned char TS_GetDataArea(unsigned char ts_ch,unsigned int ts_data,int noise_thd,bit key_pressed_flag);
unsigned char TS_AreaDeviateDetection(unsigned int cmp_data,unsigned int real_data,int range);
void TS_BaseLineForceUpdate(void);
void SetWheelSliderRefCh(unsigned char SliderNum);
int WheelTouchJudge(unsigned char WHEEL_SLIDER0_CH_COUNT_V,unsigned int WHEEL_SLIDER0_TOUCH_THD_V);
int SliderTouchJudge(unsigned char WHEEL_SLIDER0_CH_COUNT_V,unsigned int WHEEL_SLIDER0_TOUCH_THD_V);
#endif
