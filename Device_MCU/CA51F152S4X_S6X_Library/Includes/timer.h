#ifndef _TIMER_H
#define _TIMER_H
#ifdef HAVE_TIME0_EN

#define	TH0_VAL				(unsigned char)((0x10000 - (INT_TIME0*(FOSC/1000))/12000)>>8)
#define	TL0_VAL				(unsigned char)(0x10000 - (INT_TIME0*(FOSC/1000))/12000)
#endif
#ifdef HAVE_TIME1_EN	

#define	TH1_VAL				(unsigned char)((0x10000 - (INT_TIME1*(FOSC/1000))/12000)>>8)
#define	TL1_VAL				(unsigned char)(0x10000 - (INT_TIME1*(FOSC/1000))/12000)
#endif
#ifdef HAVE_TIME2_EN		

#define	TH2_VAL				(unsigned char)(((INT_TIME2*(FOSC/1000))/1000)>>8)
#define	TL2_VAL				(unsigned char)((INT_TIME2*(FOSC/1000))/1000)
#endif	



#ifdef  HAVE_TIME0_EN
void Timer0_init(void);
#endif
#ifdef  HAVE_TIME1_EN
void Timer1_init(void);
#endif
#ifdef  HAVE_TIME2_EN
//寄存器T2CON定义
#define TR2(n)			(n<<7)
#define IE2(n)			(n<<6)
#define TF2				(1<<5)
#define OF2				(1<<4)
#define CF2				(1<<3)
#define CPEDGESEL(n)	(n<<1)
#define T2M(n)			(n<<0)

void Timer2_init(void);
void Timer2_isr(void);
#endif
///////////////TMC 定时器/////////////////////////
//TMCON定义
#define TME(N)		(N<<7) 	//N=0-1
#define TMF			(1<<0) 
void TMC_timer_init(void);
/////////////////////////////////////////
#endif
