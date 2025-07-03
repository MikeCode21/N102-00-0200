#ifndef INTERRUPT_H
#define INTERRUPT_H
///////////////////////////////////////////
#ifdef HAVE_EXINT0_EN
void EXINT0_isr_proc (void); 
#endif
#ifdef HAVE_EXINT1_EN
void EXINT1_isr_proc (void);
#endif
#ifdef HAVE_EXINT2_EN
void EXINT2_isr_proc (void);
#endif
#ifdef HAVE_EXINT3_EN
void EXINT3_isr_proc (void);
#endif
#ifdef HAVE_EXINT4_EN
void EXINT4_isr_proc (void);
#endif

#ifdef HAVE_TIME0_EN
void Timer0_isr_proc(void);
#endif
#ifdef HAVE_TIME1_EN
void Timer1_isr_proc(void);
#endif
#ifdef HAVE_TIME2_EN
void Timer2_isr_proc(void);
#endif
#ifdef HAVE_TMC_TIME_EN
void TMC_timer_isr_proc(void);
#endif
#ifdef PWM_ISR_ENABLE	
void pwm_isr_proc(void);
#endif

////////////////////////////////////////////////////////
#endif
