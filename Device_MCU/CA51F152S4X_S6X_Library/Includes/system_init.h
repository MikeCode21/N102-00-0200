#ifndef _SYSTEM_INIT_H
#define _SYSTEM_INIT_H
typedef unsigned 	char 					u8_t;
typedef signed 		char 					s8_t;
typedef unsigned 	int 					u16_t;
typedef signed 		int 					s16_t;
typedef unsigned 	long int 		  u32_t;
typedef signed 		long int 		  s32_t;

void System_Init(void);
#ifdef HAVE_SYSTEM_SLEEP
void System_sleep_enter(void);
#endif	
#ifdef HAVE_EXINT0_EN
void INT0_IO_init(void);
#endif
#ifdef HAVE_EXINT1_EN
void INT1_IO_init(void);
#endif
#ifdef HAVE_EXINT2_EN
void INT2_IO_init(void);
#endif
#ifdef HAVE_EXINT3_EN
void INT3_IO_init(void);
#endif
#ifdef HAVE_EXINT4_EN
void INT4_IO_init(void);
#endif
#ifdef HAVE_EXINT5_EN
void INT5_IO_init(void);
#endif
#ifdef HAVE_EXINT6_EN
void INT6_IO_init(void);
#endif
#ifdef HAVE_EXINT7_EN
void INT7_IO_init(void);
#endif
#ifdef HAVE_EXINT8_EN
void INT8_IO_init(void);
#endif
#ifdef HAVE_EXINT9_EN
void INT9_IO_init(void);
#endif
//////////////////////////////////////
#endif
