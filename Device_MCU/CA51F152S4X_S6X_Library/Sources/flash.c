#ifndef _FLASH_C_
#define _FLASH_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
#ifdef  FLASH_ENABLE
/*********************************************************************************************************************/

/***********************************************************************************
函 数 名：Data_Area_Erase_Page										 	
功能描述：擦除数据区空间的一个页					
函数说明：								
输    入：unsigned char PageNumber	页号，范围 0-255										
返    回：无																	
***********************************************************************************/
void Data_Area_Erase_Page(unsigned char PageNumber)
{
	unsigned int Address;
	FSCMD =	0;
	Address = 0x40*PageNumber;
	LOCK = CMD_DATA_AREA_UNLOCK;					//数据区解锁
	FSCMD = CLRPL;   								//设置擦除latch
	PTSH = (unsigned char)(Address>>8);				//填写页地址
	PTSL = (unsigned char)(Address);				//填写页地址	
	FSCMD = CMD_DATA_AREA_ERASE_PAGE;				//执行擦除页操作
	LOCK = CMD_FLASH_LOCK;						    //对FLASH加锁
} 

/***********************************************************************************
函 数 名：Data_Area_Write_Page										 	
功能描述：向FLASH数据区批量写入一个页													
输    入：			unsigned char PageNumber	页号，范围 0-255											
					unsigned char *pData		数据指针，指向写入数据缓存数组
返    回：无		
写操作以页为单位进行，必须一次性写入64字节，不支持单字节写入
***********************************************************************************/
void Data_Area_Write_Page(unsigned char PageNumber,unsigned char *pData)
{
	unsigned int i;
	unsigned int Address;
	FSCMD = 0;
	Address = 0x40*PageNumber;
	LOCK = CMD_DATA_AREA_UNLOCK;					//数据区解锁
	PTSH = 0;
	PTSL = 0;
	FSCMD = CLRPL;
	for(i = 0; i < 64; i++)
	{
		FSDAT = *pData++;							//装载数据	
	}
	PTSH = (unsigned char)(Address>>8);				//填写高位地址
	PTSL = (unsigned char)Address;        			//填写低位地址
	FSCMD = CMD_DATA_AREA_WIRTE_PAGE;				//执行写操作
	LOCK = CMD_FLASH_LOCK;						    //对FLASH加锁
} 

/***********************************************************************************
函 数 名：Data_Area_Mass_Read										 	
功能描述：从FLASH数据区批量读出数据																	
输    入：unsigned int Address	  数据区空间读起始地址											
					unsigned char *pData		数据指针，指向读出数据缓存数组
					unsigned char Length		读数据长度												
返    回：无																	
***********************************************************************************/
void Data_Area_Mass_Read(unsigned int Address,unsigned char *pData,unsigned int Length)
{
	unsigned int i;
	FSCMD 	= 	0;
//	LOCK  = CMD_DATA_AREA_UNLOCK;							//数据区解锁
	PTSH = (unsigned char)(Address>>8);				//填写高位地址
	PTSL = (unsigned char)Address;        		//填写低位地址
	FSCMD = CMD_DATA_AREA_READ;								//执行读操作
	for(i = 0; i < Length; i++)
	{												
		*pData++ = FSDAT;
	}
	FSCMD = 0;
	LOCK  = CMD_FLASH_LOCK;						    		//对FLASH加锁
} 
/***********************************************************************************
函 数 名：	GetChipID										 	
功能描述：	从芯片读出芯片识别码（识别码是烧录器烧录时写入，同一烧录器烧录的每个芯片都有唯一的识别码）															
输    入：	无									
返    回：	32位滚码																
***********************************************************************************/
unsigned long int GetChipID(void)				
{
	unsigned long int ID;
	FSCMD = 0x80;	
	PTSH = 0x00;				
	PTSL = 0x00;        			
	FSCMD = 0x81;						
	ID = FSDAT;
	ID *= 256;
	ID |= FSDAT;
	ID *= 256;
	ID |= FSDAT;
	ID *= 256;
	ID |= FSDAT;
	FSCMD = 0;
	return ID;
}
/***********************************************************************************
函 数 名：	FlashRom_init										 	
功能描述：	初始化FLASHROM	数据空间 默认划分128 byte 数据空间	 总的扇区(128)
						一个扇区512BYTE									
输    入：	无									
返    回：															
***********************************************************************************/
void FlashRom_init(void)
{
	PADRD = 0x7F; //划分128 字节为数据存储区域
}

/***********************************************************************************
函 数 名：	WriteFlashRom										 	
功能描述：	在指定地址上写入数据														
输    入：	 bdat：要写入的数组
			addr：起始地址
			bytes：数据长度									
返    回：															
***********************************************************************************/
void WriteFlashRom(u8_t *bdat,u16_t addr,u16_t bytes)
{
	u16_t i;
	u8_t xdata flash_buf[128];	  
	Data_Area_Mass_Read(0,flash_buf,128);
	for(i=0;i<bytes;i++)
	{
		flash_buf[addr] = *bdat;
		addr++;
		bdat++;
		if(addr==0)
			break;			
	}
	Data_Area_Erase_Page(0);						//擦除数据页(0);
	Data_Area_Erase_Page(1);						//擦除数据页(1);
	Data_Area_Write_Page(0,&flash_buf[0]);//写操作以页为单位进行，必须一次性写入64字节，不支持单字节写入
	Data_Area_Write_Page(1,&flash_buf[64]);//写操作以页为单位进行，必须一次性写入64字节，不支持单字节写入	
}
/***********************************************************************************
函 数 名：	ReadFlashRom										 	
功能描述：	在指定地址上读取n个数据														
输    入：	 bdat：读取数据存入的数组
			addr：起始地址
			bytes：读取的数据长度									
返    回：															
***********************************************************************************/
void ReadFlashRom(u8_t *bdat,u16_t addr,u16_t bytes)
{  	 
	Data_Area_Mass_Read(addr,bdat,bytes);
}
#endif 
#endif 
