#ifndef _SPI_H_
#define _SPI_H_
//SPCONλ����
#define SPEN(N)		(N<<7)
#define LSBF(N)		(N<<6)
#define SSIG(N)		(N<<5)
#define MSTR(N)		(N<<4)
#define CPOL(N)		(N<<3)
#define CPHA(N)		(N<<2)
#define CKOS(N)		(N)	    //3:ϵͳʱ��ѡ��Ϊ��ʱ��2���
													//2:ϵͳʱ��ѡ��Ϊ��ʱ��1���
													//1:ϵͳʱ��ѡ��Ϊ1/8ϵͳʱ��	
													//0:ϵͳʱ��ѡ��Ϊ1/4ϵͳʱ��	

//SPSTAλ����
#define SPIE		(1<<7)   //SPI�ж�ʹ��
#define WCOL		(1<<2)   //д���ͻ��־
#define MODF		(1<<1)   //����ģʽ
#define SPIF		(1<<0)   //�������


extern unsigned char spi_int_flag;
void SPI_ISR_proc (void);
void SPI_Master_Init(void);
void SPI_Master_Write(unsigned char idx);
bit SPI_SlaveRead(u8_t *pdat);
unsigned 	char SPI_Master_WriteRead(unsigned char idx);
void SPI_init(void);
#endif