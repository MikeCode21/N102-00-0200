#ifndef SYSTEM_PROC_H
#define SYSTEM_PROC_H
//////////////////////////////////////////////////////////
void system_sleep_proc(void);
void System_powersave_proc(void);
unsigned char Get_system_powersave_exit_proc(void);
//////////////////////////////////////////////////////////////
unsigned char every_n_milliseconds(unsigned int millisecond);
unsigned char every_n_seconds(unsigned char second);
unsigned char get_pin_status(unsigned char pin_status,unsigned char *pPinSF,unsigned char filter);

//////////////////////////////////////////////////////////
#endif