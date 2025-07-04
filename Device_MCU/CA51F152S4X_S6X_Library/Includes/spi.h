#ifndef _SPI_H_
#define _SPI_H_
//SPCON位定义
#define SPEN(N)		(N<<7)
#define LSBF(N)		(N<<6)
#define SSIG(N)		(N<<5)
#define MSTR(N)		(N<<4)
#define CPOL(N)		(N<<3)
#define CPHA(N)		(N<<2)
#define CKOS(N)		(N)	    //3:系统时钟选择为定时器2溢出
													//2:系统时钟选择为定时器1溢出
													//1:系统时钟选择为1/8系统时钟	
													//0:系统时钟选择为1/4系统时钟	

//SPSTA位定义
#define SPIE		(1<<7)   //SPI中断使能
#define WCOL		(1<<2)   //写入冲突标志
#define MODF		(1<<1)   //故障模式
#define SPIF		(1<<0)   //传输完成


extern unsigned char spi_int_flag;
void SPI_ISR_proc (void);
void SPI_Master_Init(void);
void SPI_Master_Write(unsigned char idx);
bit SPI_SlaveRead(u8_t *pdat);
unsigned 	char SPI_Master_WriteRead(unsigned char idx);
void SPI_init(void);
#endif