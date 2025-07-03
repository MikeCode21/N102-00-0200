#ifndef _FLASH_C_
#define _FLASH_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
#ifdef  FLASH_ENABLE
/*********************************************************************************************************************/

/***********************************************************************************
�� �� ����Data_Area_Erase_Page										 	
���������������������ռ��һ��ҳ					
����˵����								
��    �룺unsigned char PageNumber	ҳ�ţ���Χ 0-255										
��    �أ���																	
***********************************************************************************/
void Data_Area_Erase_Page(unsigned char PageNumber)
{
	unsigned int Address;
	FSCMD =	0;
	Address = 0x40*PageNumber;
	LOCK = CMD_DATA_AREA_UNLOCK;					//����������
	FSCMD = CLRPL;   								//���ò���latch
	PTSH = (unsigned char)(Address>>8);				//��дҳ��ַ
	PTSL = (unsigned char)(Address);				//��дҳ��ַ	
	FSCMD = CMD_DATA_AREA_ERASE_PAGE;				//ִ�в���ҳ����
	LOCK = CMD_FLASH_LOCK;						    //��FLASH����
} 

/***********************************************************************************
�� �� ����Data_Area_Write_Page										 	
������������FLASH����������д��һ��ҳ													
��    �룺			unsigned char PageNumber	ҳ�ţ���Χ 0-255											
					unsigned char *pData		����ָ�룬ָ��д�����ݻ�������
��    �أ���		
д������ҳΪ��λ���У�����һ����д��64�ֽڣ���֧�ֵ��ֽ�д��
***********************************************************************************/
void Data_Area_Write_Page(unsigned char PageNumber,unsigned char *pData)
{
	unsigned int i;
	unsigned int Address;
	FSCMD = 0;
	Address = 0x40*PageNumber;
	LOCK = CMD_DATA_AREA_UNLOCK;					//����������
	PTSH = 0;
	PTSL = 0;
	FSCMD = CLRPL;
	for(i = 0; i < 64; i++)
	{
		FSDAT = *pData++;							//װ������	
	}
	PTSH = (unsigned char)(Address>>8);				//��д��λ��ַ
	PTSL = (unsigned char)Address;        			//��д��λ��ַ
	FSCMD = CMD_DATA_AREA_WIRTE_PAGE;				//ִ��д����
	LOCK = CMD_FLASH_LOCK;						    //��FLASH����
} 

/***********************************************************************************
�� �� ����Data_Area_Mass_Read										 	
������������FLASH������������������																	
��    �룺unsigned int Address	  �������ռ����ʼ��ַ											
					unsigned char *pData		����ָ�룬ָ��������ݻ�������
					unsigned char Length		�����ݳ���												
��    �أ���																	
***********************************************************************************/
void Data_Area_Mass_Read(unsigned int Address,unsigned char *pData,unsigned int Length)
{
	unsigned int i;
	FSCMD 	= 	0;
//	LOCK  = CMD_DATA_AREA_UNLOCK;							//����������
	PTSH = (unsigned char)(Address>>8);				//��д��λ��ַ
	PTSL = (unsigned char)Address;        		//��д��λ��ַ
	FSCMD = CMD_DATA_AREA_READ;								//ִ�ж�����
	for(i = 0; i < Length; i++)
	{												
		*pData++ = FSDAT;
	}
	FSCMD = 0;
	LOCK  = CMD_FLASH_LOCK;						    		//��FLASH����
} 
/***********************************************************************************
�� �� ����	GetChipID										 	
����������	��оƬ����оƬʶ���루ʶ��������¼����¼ʱд�룬ͬһ��¼����¼��ÿ��оƬ����Ψһ��ʶ���룩															
��    �룺	��									
��    �أ�	32λ����																
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
�� �� ����	FlashRom_init										 	
����������	��ʼ��FLASHROM	���ݿռ� Ĭ�ϻ���128 byte ���ݿռ�	 �ܵ�����(128)
						һ������512BYTE									
��    �룺	��									
��    �أ�															
***********************************************************************************/
void FlashRom_init(void)
{
	PADRD = 0x7F; //����128 �ֽ�Ϊ���ݴ洢����
}

/***********************************************************************************
�� �� ����	WriteFlashRom										 	
����������	��ָ����ַ��д������														
��    �룺	 bdat��Ҫд�������
			addr����ʼ��ַ
			bytes�����ݳ���									
��    �أ�															
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
	Data_Area_Erase_Page(0);						//��������ҳ(0);
	Data_Area_Erase_Page(1);						//��������ҳ(1);
	Data_Area_Write_Page(0,&flash_buf[0]);//д������ҳΪ��λ���У�����һ����д��64�ֽڣ���֧�ֵ��ֽ�д��
	Data_Area_Write_Page(1,&flash_buf[64]);//д������ҳΪ��λ���У�����һ����д��64�ֽڣ���֧�ֵ��ֽ�д��	
}
/***********************************************************************************
�� �� ����	ReadFlashRom										 	
����������	��ָ����ַ�϶�ȡn������														
��    �룺	 bdat����ȡ���ݴ��������
			addr����ʼ��ַ
			bytes����ȡ�����ݳ���									
��    �أ�															
***********************************************************************************/
void ReadFlashRom(u8_t *bdat,u16_t addr,u16_t bytes)
{  	 
	Data_Area_Mass_Read(addr,bdat,bytes);
}
#endif 
#endif 
