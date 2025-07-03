#ifndef _I2C_H_
#define _I2C_H_
//I2CCON定义
#define I2CE(N)		(N<<7)
#define I2CIE(N)	(N<<6)
#define STA(N)		(N<<5)
#define STP(N)		(N<<4)
#define CKHD(N)		(N<<3)
#define AAK(N)		(N<<2)
#define CBSE(N)		(N<<1)
#define STFE(N)		(N<<0)

//I2CADR定义
#define   GCE(N)		(N<<7) //N = 0~1

//I2CADM定义
#define   SPFE(N)		(N<<7) //N = 0~1

//I2CFLG定义
#define I2CF		(1<<0)
//#define I2CSTP		(1<<1)
//SCLSEL
#define I2CKS(N)		(N<<7) //N = 0~1
enum
{
	I2CS_P00_INDEX = 0,
	I2CS_P01_INDEX = 1,
	I2CS_P02_INDEX = 2,
	I2CS_P03_INDEX = 3,
	I2CS_P04_INDEX = 4,
	I2CS_P05_INDEX = 5,
	I2CS_P06_INDEX = 6,
	I2CS_P07_INDEX = 7,

	I2CS_P10_INDEX = 8,
	I2CS_P11_INDEX = 9,
	I2CS_P12_INDEX = 10,
	I2CS_P13_INDEX = 11,
	I2CS_P14_INDEX = 12,
	I2CS_P15_INDEX = 13,
	I2CS_P16_INDEX = 14,
	I2CS_P17_INDEX = 15,
	
	I2CS_P20_INDEX = 16,
	I2CS_P21_INDEX = 17,
	I2CS_P22_INDEX = 18,
	I2CS_P23_INDEX = 19,
	I2CS_P24_INDEX = 20,
	I2CS_P25_INDEX = 21,
	I2CS_P26_INDEX = 22,
	I2CS_P27_INDEX = 23,

	I2CS_P30_INDEX = 24,
	I2CS_P31_INDEX = 25,
};
typedef enum {
  I2CE_disable  	= 0,
  I2CE_enable  	= 1,
} I2CE_TypeDef;

typedef enum {
  I2CIE_disable  	= 0,
  I2CIE_enable  	= 1,
} I2CIE_TypeDef;

typedef enum {
  STFE_disable  	= 0,
  STFE_enable  	= 1,
} STFE_TypeDef;

void I2C_SelectComPin(void);
void I2C_Init(void);
void I2C_ISR(void);
#ifdef HAVE_MASTER_IIC
void I2C_Master_Config(unsigned char i2cadr,unsigned char i2c_frq);
unsigned char I2C_Write(unsigned char DevAdr,unsigned char addr,unsigned char *dat,unsigned char len);
unsigned char I2C_Read(unsigned char DevAdr,unsigned char addr,unsigned char *dat,unsigned char len);
#endif
#ifdef HAVE_SLAVE_IIC
void I2C_Slave_Config(unsigned char i2cadr);
#endif
/***********************************************************************************/
#endif
