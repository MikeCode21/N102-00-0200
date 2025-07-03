#ifndef HEADFILE_H
#define HEADFILE_H
#include "sys_include\user_config.h"

#include "includes\ca51f152SXsfr.h"
#include "includes\ca51f152SXxsfr.h"
#include "includes\gpiodef_f152SX.h"
#include "includes\pindef_f152SX.h"
#include "includes\system.h"
#include "includes\system_init.h"
#include "includes\timer.h"
#include "includes\exint.h"
#include "sys_include\interrupt_proc.h"
#include "sys_include\system_proc.h"
#ifdef HAVE_CHANGE_SYS_CLK
	#include "includes\system_clock.h"
#endif
#ifdef LVD_ENABLE
	#include "includes\lvd.h"
#endif
#ifdef HAVE_UART
	#include "includes\uart.h"
#endif
#include "includes\delay.h"
#ifdef ADC_ENABLE
	#include "Includes\adc.h"
#endif
#ifdef I2C_ENABLE
#include "includes\i2c.h"
#endif
#ifdef SPI_ENABLE
#include "includes\spi.h"
#endif
#ifdef CA_LCD_LED_ENABLE
	#include "includes\lcd.h"
#endif
#ifdef PWM_ENABLE
	#include "includes\pwm.h"
#endif
#ifdef  FLASH_ENABLE
#include "includes\flash.h"
#endif
#ifdef HAVE_RTC
#include "includes\rtc.h"
#endif
#ifdef POWER_SAVE_ENABLE
#include "includes\stop_idle.h"
#endif
#ifdef  WATCHDOG_ENABLE
#include "includes\wdt.h"
#endif 
#ifdef BUZZER_ENABLE
	#include "includes\buzz.h"
#endif
#ifdef CA_TOUCH_KEY
/*********************************************************************************************************************/
#include "TS_Lib\Includes\ts_configuration.h"
#include "TS_Lib\Includes\ts_def.h"
#include "TS_Lib\Includes\ts_api.h"
#include "TS_Lib\Includes\ts_service.h"
/*********************************************************************************************************************/	
#endif

#include <intrins.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <absacc.h>
#endif
