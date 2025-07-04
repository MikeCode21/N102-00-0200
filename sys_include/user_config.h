// <<< Use Configuration Wizard in Context Menu >>>
#ifndef USER_CONFIG_H
#define USER_CONFIG_H
/****************************************************************************
						软件版本号
****************************************************************************/
//<h> 软件版本号
//<i>  设置软件库版本和应用软件版本
//		<e0> 软件库版本
//  		<o1> SW_LIB_VERSION [版] <1-65535:1>
//			<o2> SW_USER_VERSION[版] <1-65535:1>
//  		<i> 缺省值: 1  (版)
//		</e>
//</h>
/////////////////////////////////////////////////////////////////////////////
#define VERSION_SETUP				1	
#define SW_LIB_VERSION			1			
#define SW_USER_VERSION			1		
#if VERSION_SETUP
#define HAVE_SHOW_VERSION
////////////////////////软件版本号///////////////////////////////////////////////////////////////
#define	SOFTWARE_VERSION   	"  SW-Ver:01.01  "//	"  SW-VER:01.00  "
#endif
/**************************************************************************************************************/
//内置高速 RC 振荡器：16MHz
//电压 2.7V ~ 5.5V 支持系统时钟 16MHz
//电压 2.3V ~ 5.5V 支持系统时钟 8MHz
#define IRCH_16M		  0     //16.0MHz
#define IRCL		  		1     //128KHz
#define IRCH_8M				2     //8.0MHz
//======================System Timer配置=================================================== 
//<e0> System 时钟配置
//  <o1> System 时钟源选择
//  <i> 缺省值: SYSCLK_SRC = IRCH_8M
//                    <0=> IRCH16M (16MHz)
//                    <1=> IRCL (128KHz)
//                    <2=> IRCH_8M (8MHz) 
//</e>
#define SYSCLK_SETUP				1			
/**************************************************************************************************************/
#define SYSCLK_SRC					2									//芯片系统时钟选择,一般情况设置为IRCH或PLL   
/**************************************************************************************************************/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//<e0> TMC 中断时间配置
//		<o1> TMC 中断时间配置寄存器 [个] <0-255:1>
//  		<i> TMC 的中断时间为（TMSNU+1）*512×Tircl.
//  		<i> Tircl 为 IRCL 时钟一个周期时间。
//  		<i> 缺省值: 0  (个)
//   <o2> TMC时钟源选择
//       <i> 缺省值: TMC_CLK_SRC = IRCL
//                    <0=> IRCL 
//                    <1=> XOSCL (32.768khz) 接外部晶振32.768khz
//</e>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TMC_REG_SETUP			 0	
#define TMSNU_VALUE			   24			//TMC 中断时间配置寄存器,设置 TMSNU_VALUE 个最小单位时间（即 512 个 IRCL 时钟周期）
#define TMC_CLK_SRC			   0	      //最小单位为128个时钟周期，可配置中断时间为1~256个最小单位时间。
#if TMC_REG_SETUP
#define HAVE_TMC_TIME_EN					//TMC 定时器 
#endif
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if  (!(SYSCLK_SETUP))
	#error "请选择系统时钟！！！"  
#endif
/************系统时钟频率定义，主要用于配置UART波特率**********************************************************/
#if (SYSCLK_SRC == IRCH_16M)
	#define FOSC		(16000000)
#elif (SYSCLK_SRC == IRCH_8M)
	#define FOSC		(8000000)	
#elif (SYSCLK_SRC == IRCL)
	#define FOSC		(128000)
#else
	#define FOSC		(8000000)
#endif
/***************************************************************************************************************/
//////////////低速时钟//////////////////////////////////////////
#define IRCL_FOSC		(128)   //Khz   需要用获取实际值来使用
/****************************************************************************
1、芯片功能选择配置
****************************************************************************/
//<h> 芯片功能选择配置
//<i>  选择芯片的底层驱动
//		<c> 低电压检测复位功能 (默认必须打开)
		#define LVD_ENABLE    							//低电压检测或复位功能 此项 CA51F7XX必须打开
//		</c>
//		<c> 设置系统时钟 (默认必须打开)
		#define HAVE_CHANGE_SYS_CLK      		//设置系统时钟
//		</c>
//		<c> ADC 功能
		//#define ADC_ENABLE              		//ADC 功能
//		</c>
//		<c> ADC 中断功能
		//#define ADC_ISR_ENABLE              //ADC 中断功能
//		</c>
//		<c> FLASH 存储功能
		//#define FLASH_ENABLE			     		//FLASH 功能
//		</c>
//		<c> pwm 功能
		//#define PWM_ENABLE								//pwm 功能
//		</c>		
//		<c> pwm 中断功能
		//#define PWM_ISR_ENABLE            //pwm 中断功能
//		</c>
//		<c> 低功耗模式功能
		//#define POWER_SAVE_ENABLE					   //stop IDLE 低速模式功能
//		</c>
//		<c> 看门狗功能
		#define WATCHDOG_ENABLE         		//看门狗功能
//		</c>
//		<e0> 外部中断功能
//			<c> 外部中断0	
				//#define HAVE_EXINT0_EN     				//外部中断0使能
//			</c>
//			<c> 外部中断1	
				//#define HAVE_EXINT1_EN     				//外部中断1使能
//			</c>
//			<c> 外部中断2	
				//#define HAVE_EXINT2_EN     				//外部中断2使能
//			</c>
//			<c> 外部中断3	
				//#define HAVE_EXINT3_EN     				//外部中断3使能
//			</c>
//			<c> 外部中断4	
				//#define HAVE_EXINT4_EN     				//外部中断4使能
//			</c>
//		</e>
//		<e1> 硬件i2c功能
//  		<o2> 主模式/从模式选择
//  		<i> 缺省值: 主模式
//                    <0=> 主模式（Master）
//                    <1=> 从模式（Slave）
//		</e>
//		<e3> 硬件spi功能
//  		<o4> 主模式/从模式选择
//  		<i> 缺省值: 主模式
//                    <0=> 主模式（Master）
//                    <1=> 从模式（Slave）
//		</e>
//</h>
//////////////////////////////////////////////////////////////////////////////////////////
#define  EXINT_EN_SETUP       0
///////////////////////I2C主模式/从模式选择///////////////////////////////////////////////
#define  CA_I2C_SETUP       0
#define  CA_I2C_INDEX       1    //主模式/从模式选择
///////////////////////SPI主模式/从模式选择///////////////////////////////////////////////
#define  CA_SPI_SETUP       0
#define  CA_SPI_INDEX       0    //主模式/从模式选择
//////////////////////////////////////////////////////////////////////////////////////////
#if (CA_I2C_SETUP)
  #define   I2C_ENABLE				//打开芯片i2c内部驱动
	#if (CA_I2C_INDEX==0)
		#define  HAVE_MASTER_IIC  //主模式
	#elif (CA_I2C_INDEX==1)
			#define HAVE_SLAVE_IIC  //从模式
	#endif
#endif
/////////////////////////////////////////////////////////////////////////////////////////
#if (CA_SPI_SETUP)
  #define   SPI_ENABLE				//打开芯片i2c内部驱动
	#if (CA_SPI_INDEX==0)
		#define  HAVE_MASTER_SPI  //主模式
	#elif (CA_SPI_INDEX==1)
			#define HAVE_SLAVE_SPI  //从模式
	#endif
#endif
///////////////////////////////////////////////////////////////////////////////
#if (!EXINT_EN_SETUP)
    #undef HAVE_EXINT0_EN	
		#undef HAVE_EXINT1_EN	
		#undef HAVE_EXINT2_EN	
		#undef HAVE_EXINT3_EN	
		#undef HAVE_EXINT4_EN	
#endif

/****************************************************************************
				 低电压检测功能选择配置
****************************************************************************/
#ifdef  LVD_ENABLE
#define LVD_RST_ENABLE								//系统低电复位
//#define LVD_LOW_POWER_DET_ENABLE		//系统低电检测
#endif

/****************************************************************************
2、				 定时器功能选择配置
****************************************************************************/
//<h> 定时器0/1/2配置
//<i>  开关定时器及设定定时器时间
//		<e0> 定时器0配置
//  		<o1> 定时器0 定时 [us] <1-65535:1>
//  		<i> 缺省值: 1000  (us)
//		</e>
//		<e2> 定时器1配置
//  		<o3> 定时器1 定时 [us] <1-65535:1>
//  		<i> 缺省值: 1000  (us)
//		</e>
//		<e4> 定时器2配置
//  		<o5> 定时器2 定时 [us] <1-65535:1>
//  		<i> 缺省值: 1000  (us)
//		</e>
//</h>
/////////////////////////////////////////////////////////////////////////////
#define TIME0_SETUP				1	
#define INT_TIME0			    125//1000			//定时时间，单位为us
#define TIME1_SETUP				0	
#define INT_TIME1			    1000			//定时时间，单位为us
#define TIME2_SETUP				0
#define INT_TIME2			    500			//定时时间，单位为us
#define TMC_SETUP					0

#if TIME0_SETUP
	#define HAVE_TIME0_EN					//定时器0 打开
#endif
#if TIME1_SETUP
	#define HAVE_TIME1_EN					//定时器0 打开   此定时器一般用作UAART0串口波特率发生器。
#endif
#if TIME2_SETUP
	#define HAVE_TIME2_EN					//定时器2 打开
#endif
/****************************************************************************
3、				 串口功能选择配置
****************************************************************************/
//<h> 串口功能配置
//<i>  设置串口0/1/2的波特率
//		<e0> 串口1配置
//  		<o1> 串口1 波特率 [bps] <1-115200:1>
//  		<i>  可选波特率：9600bps,19200bps,38400bps,57600,115200bps				
//		</e>
//		<e2> 串口2配置
//  		<o3> 串口2 波特率 [bps] <1-115200:1>
//  		<i> 可选波特率：9600bps,19200bps,38400bps,57600,115200bps
//		</e>
//		<e4> 串口调试
//  		<o5> 串口打印端口选择
//  		<i> 缺省值: UART_DEBUG = UART1_DEBUG
//                    <1=> UART1_DEBUG
//                    <2=> UART2_DEBUG
//		<c>  ASCII打印信息
			#define DEBUG_PRINTF_EN			       //uart_printf  ASCII打印信息
//		</c>
//		</e>
//</h>
/////////////////////////////////////////////////////////////////////////////
#define UART1_SETUP    0
#define UART1_BAUTRATE		19200
#define UART2_SETUP    			1
#define UART2_BAUTRATE		9600//19200
#define UART_DEBUG_SETUP    1
#define UART_DEBUG_SELECT		2
#if (!UART_DEBUG_SETUP)
    #undef DEBUG_PRINTF_EN	
#endif
////////////////////////////////////////////////////////////////////////////////
#if (UART1_SETUP|UART2_SETUP)
#define HAVE_UART
#if (UART1_SETUP)
	#define UART1_EN			//如果使用UART1，打开此宏定义
#endif
#if (UART2_SETUP)
	#define UART2_EN			//如果使用UART2，打开此宏定义
#endif
#endif
///////////////////////////////串口调试选择////////////////////////////////////////////////
#if (UART_DEBUG_SETUP)
#define USE_UART_DEBUGGING

#if (UART_DEBUG_SELECT==1)
#define USE_UART1_DEBUGGING   	 	 //串口1调试
#endif
#if (UART_DEBUG_SELECT==2)
#define USE_UART2_DEBUGGING   	 	 //串口2调试
#endif
//////////////////////////////////////////////////////////////////////////////////////////
#endif
/****************************************************************************/

/****************************************************************************
4、						系统功能设置
****************************************************************************/
//<h> 系统功能设置
//<i>  系统功能开关
//		<e0> 系统省电功能
//  		<o1> 进入系统省电功能时间 [100ms] <1-255:1>
//  		<i> 缺省值: 3  (3x100ms)
//		</e>
//////////////////////////////////////////////////	
		//<c> 系统时钟及adc adcl 校准功能配置		
		//#define HAVE_CLK_ADCAL_CALI//
		//	</c>
		//<i> 在电池产品或是VDD在3.3V供电时使用该功能
//////////////////////////////////////////////////	
//</h>
#ifdef HAVE_CLK_ADCAL_CALI
  #define ADC_ENABLE    //系统时钟及adc adcl 校准功能需要测试芯片VDD电压
#endif
//////////////////////////////////////////////////////////////////////////////
#define SYSTEM_SLEEP_SETUP    0   //使能睡眠设置

#define DEFAULT_SLEEP_TIMER		30 //3s

#if (SYSTEM_SLEEP_SETUP)
		#define HAVE_SYSTEM_SLEEP
#endif

/****************************************************************************/

/****************************************************************************
5、						用户模式功能设置
****************************************************************************/
//<h> 用户模式功能设置
//<i>  选择用户自定义功能开关
//		<c> 触摸按键配置	
		  //#define HAVE_TOUCH_KEY   //触摸按键功能
//		</c>
//		<c> 扫描按键配置	
		  //#define HAVE_SCAN_KEY  //扫描按键
//		</c>
//////////////////////////////////////////////////	
		//<c> xxx功能配置		
		//#define HAVE_XXXX  //xxx功能
   //	</c>
	 //<i> xxx功能描述。。。
//////////////////////////////////////////////////	
//</h>
///////////////////////////////////////////////////////////////////////////////
#if (defined HAVE_TOUCH_KEY )|(defined HAVE_SCAN_KEY )
#define  HAVE_MSG         //按键消息输入开关
#endif
#ifdef HAVE_MSG
#ifdef HAVE_TOUCH_KEY
	#define CA_TOUCH_KEY
	 #if (TMC_REG_SETUP==0)
		#define HAVE_TMC_TIME_EN					//触摸需要开启 TMC 定时器 
	#endif
#endif

#endif
/****************************************************************************/
#endif
// <<< end of configuration section >>>