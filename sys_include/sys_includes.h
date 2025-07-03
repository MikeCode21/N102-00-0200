
#include "sys_include\user_config.h"
#include "includes\headfile.h"
#include "sys_include\uart_debug.h"
#include "sys_include\interrupt_proc.h"
#include "sys_include\typedef.h"
#include "sys_include\define.h"
#include "sys_include\sys_variable.h"
#include "sys_include\sys_function.h"
#include "sys_include\hardware.h"
#include "sys_include\system_proc.h"

///////////////////////////////////////////////////////////////////
//////////////////按键消息头文件//////////////////////////////////
#ifdef  HAVE_MSG
#include "sys_include\msg.h"
#endif
///////////////////////////////////////////////////////////////////

//////////////////////c51 系统头文件////////////////////////////////////////////////////////////
#include <intrins.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <absacc.h>