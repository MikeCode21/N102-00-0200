//TKST定义
#define TKST_(N)		(N<<0)	 //N=0-1	

//TKCFG1定义
#define TKEN(N)			(N<<6)	 //N=0-1
#define TKDIV(N)		(N<<0)	 //N=0-63 充放电时钟选择

//TKCFG2定义
#define TKPULL8(N)		(N<<6)	 //N=0-1
#define PAREN(N)		(N<<5)	 //N=0-1
#define TKCADDR(N)		(N<<0)	

//TKCFG3定义
#define RESO(N)			(N<<4)	 //N=0-1
#define TKCKSEL(N)		(N<<2)	 //N=0-1
#define CHGSEL(N)		(N<<1)	
#define DCHGSEL(N)		(N<<0)	

//TKIE
#define TKIE_(N)    	(N<<7)
#define TKIF(N)    		(N<<0)

//TKCFG4
#define RBSEL(N)    	(N<<3)	 //电阻设置
#define VRSEL(N)    	(N<<0)		


#define TME(N)			(N<<7) 	 //N=0-1
#define TMF				(1<<0) 

typedef union 
{	
	unsigned long int 	dwVal;
	unsigned int 		wVal[2];
	unsigned char 		bVal[4];
}
DWORD_UNION;

typedef union 
{	
	unsigned int 		wVal;
	unsigned char 		bVal[2];
}
WORD_UNION;

typedef enum
{
	 TS_INIT,
	 TS_DEAL
} TSState_T;

enum 
{
	AREA_FINGER_TOUCH,
	AREA_PNOISE_PLUS,
	AREA_PNOISE,
	AREA_NNOISE,
	AREA_OVER_LOW		
};
enum 
{
	WHEEL_SLIDER_NO_TOUCH,
	WHEEL_SLIDER_TOUCH,	
};

#define WHEEL 		0
#define SLIDER  	1
enum
{
	TS_CH0,
	TS_CH1,
	TS_CH2,
	TS_CH3,
	TS_CH4,
	TS_CH5,
	TS_CH6,
	TS_CH7,
	TS_CH8,
	TS_CH9,
	TS_CH10,
	TS_CH11,
	TS_CH12,
	TS_CH13,
	TS_CH14,
	TS_CH15,
	TS_CH16,
	TS_CH17,
	TS_CH18,
	TS_CH19,
	TS_CH20,
	TS_CH21,
	TS_CH22,
	TS_CH23,
	TS_CH24,
	TS_CH25,
};

#ifndef TS_SERVICE_C
#if (KEY_CH_COUNT <= 8)
	#define TYPE_SN		unsigned char 
#elif (KEY_CH_COUNT <= 16)
	#define TYPE_SN		unsigned int
#else
	#define TYPE_SN		unsigned long int
#endif
#endif



enum 
{
	TK_STATE_RELEASE,
	TK_STATE_SINGLE_KEY_PRESS,	
	TK_STATE_DOUBLE_KEY_PRESS,
};

#define TS_LONG_START_TIME			250
#define TS_LONG_TIME				70




