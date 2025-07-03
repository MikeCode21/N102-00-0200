#ifndef _I2C_C_
#define _I2C_C_
/*********************************************************************************************************************/
#include "includes\headfile.h"
/*********************************************************************************************************************/
#ifdef I2C_ENABLE

#define I2C_ADDR    		    0XCA  // I2C �ӻ���ַ+дλ
#define IIC_MAX_BUF_NUM	    20
unsigned char iic_TxRXBuf[IIC_MAX_BUF_NUM]={0};
///////////////////////////////////////////////////////////////////
#ifdef HAVE_MASTER_IIC
unsigned char iic_txIndex;
unsigned char I2C_CurrDeviceAddr;
unsigned char iic_regAddr;
unsigned char iic_txLength;  //�������ݵĳ���
	
bit iicEnd;
bit iicWriteRead; // 0��write  1��read
bit iic_rdSession; 
unsigned char iicWriteNoAck;
unsigned char I2CSTA_STAUST;	
unsigned char iic_rxIndex;
unsigned char iic_rxLength;
#endif
///////////////////////////////////////////////////////////////////
#ifdef HAVE_SLAVE_IIC
unsigned char I2CDataIndex;
unsigned char regAddr;
bit iicReadMode;
#endif
/*********************************************************************************************************************/
//  I2C�����ӻ�ͨ�ŵ���������������ȡ20�ֽ����ݡ�  
//   ____________            _____________ 
//  |            |   SDA    |             |
//  |            |<-------->|             |
//  |            |          |             |
//  |  CA51F2(M) |          | CA51F2(S)   |
//  |(I2C_Master)|          | (I2C_Slave) |
//  |            |   SCL    |             |
//  |            |--------->|             |
//  |____________|          |_____________|
//
/*********************************************************************************************************************/
/******************************************************************************
��������  I2C_SelectComPin
����������I2C ѡ��˿�
�������: ��
����ֵ�� ��					

******************************************************************************/
void I2C_SelectComPin(void)
{
	/**********ѡ��I2C�˿�******************************************************************/
  //I2C����SCL/SDA���ܿ���ӳ�䵽����GPIO���ţ��ɼĴ���SCLSEL/SDASEL���ò�ͬ��ֵ��ѡ��
	P31_CFG_I2C_SDA;//P3.1����ΪI2C_SDA����
	P24_CFG_I2C_SCL;//P2.4����ΪI2C_SCL����
	SCLSEL =(SCLSEL&0x80)| I2CS_P01_INDEX;			//I2C����ʱ��ѡ��ϵͳʱ�ӣ�I2C_SCL����ѡ��P2.4
	SDASEL = I2CS_P31_INDEX;								//I2C_SDA����ѡ��P3.1
	
}
////////////////////////////////////////////////////////////////////////////////////////////

#ifdef HAVE_MASTER_IIC
/******************************************************************************
��������  I2C_Master_Config
����������I2C����ģʽ���ܳ�ʼ��
�������: 
					i2cadr	 //���豸��ַ
					i2ccr		//ʱ��Ƶ�� 50~100KHZ
					I2C SCL���ʱ��Ƶ�����ã�SCL���ʱ��Ƶ��Ϊ����Ƶ�ʵ�(I2CCKD +1)��Ƶ������
							Fscl= Fsample /(I2CCKD +1))==��Fsample= FOSC 2��smpdiv���ݷ�Ƶ
					1. ��SMPDIV= 0ʱ���������I2CCKDС��9�����Զ���9���㡣
					2. �� SMPDIV>0 ʱ��������� I2CCKD С�� 7�����Զ��� 7 ���㡣 
					Fscl= Fsample /(I2CCKD +1))==>>Fscl= (FOSC 2��smpdiv���ݷ�Ƶ) /(I2CCKD +1)��Ƶ)==��i2ccr=FOSC/i2c_frq-1
����ֵ�� ��					

******************************************************************************/
void I2C_Master_Config(unsigned char i2cadr,unsigned char i2c_frq)
{	
	I2CCON = I2CE(1) | I2CIE(1) | STA(0) | STP(0)| CKHD(1) | AAK(1)| CBSE(0) | STFE(1); 
	//ʹ�� I2C������I2C �жϣ����� I2CF �� 1 ������ SCL������ START �źŲ����ж�	
	I2CADR = GCE(0)|(i2cadr>>1);//���豸��ַ
	//I2CCCR = i2ccr;//���� I2C ʱ��
//////////////////////////////////////////////////////////////////////
	I2CCCR=(0x80)|(((((unsigned long int)FOSC/16/(i2c_frq))/1000) -1)&0x1f);
	SCLSEL = I2CKS(0); //I2C ����ʱ��ѡ��λ 0��ϵͳʱ�� 1���ڲ�����ʱ��
	INT4EN = 1; //ʹ�� INT4 �ж�
}
/***********************************************************************************
�� �� ����	I2C_Write										 	
����������	I2C д����													
��    �룺	 DevAdr�����豸��ַ
			addr�� ��ʼ��ַ
			dat������
			len: ���ݳ���
��    �أ�	 д���Ƿ�ɹ�														
***********************************************************************************/
unsigned char I2C_Write(unsigned char DevAdr,unsigned char addr,unsigned char *dat,unsigned char len)
{
	unsigned  char i;
	iicWriteRead=0;
	iic_txIndex=0;
	I2C_CurrDeviceAddr=DevAdr;
	iic_regAddr = addr; 			//��λ���ݵ�ַ
	iicEnd = 0; 			//������־�� 0
	iic_txLength = len; 	//���÷������ݳ���
	iicWriteNoAck=0;
	for(i=0;i<len;i++)
	{
		iic_TxRXBuf[i]=*dat++;
	}
	I2CCON |= STA(1); //���� START �źţ��������ݷ���
	while(!iicEnd&&!iicWriteNoAck)//; 	//�ȴ����ݷ�����  
	{
		I2CSTA_STAUST=0;
		iicWriteNoAck=0;
		Delay_ms(10);
	}		
	return iicWriteNoAck; 
}
/***********************************************************************************
�� �� ����	I2C_Read										 	
����������	I2C ������													
��    �룺	 DevAdr�����豸��ַ
			addr�� ��ʼ��ַ
			dat������
			len: ���ݳ���							
��    �أ�	 ��ȡ�Ƿ�ɹ�														
***********************************************************************************/
unsigned char I2C_Read(unsigned char DevAdr,unsigned char addr,unsigned char *dat,unsigned char len)
{
	  unsigned  char i;
		iicWriteRead=1;
	  I2C_CurrDeviceAddr=DevAdr;
	  iic_regAddr = addr; 			//��λ���ݵ�ַ
		iicEnd = 0; //������־�� 0
		iic_rxLength= len; //���÷������ݳ���
	  iicWriteNoAck=0;
		I2CCON |= STA(1); //���� START �źţ����� I2C ͨ��
		while(!iicEnd&&!iicWriteNoAck); 	//�ȴ����ݷ�����
		//�ڴ˴��ɶ�ȡ I2C ���ջ��� rxBuf
		 for(i=0;i<len;i++)
		{
			 *dat++=iic_TxRXBuf[i];
		}
	  return iicWriteNoAck;
}
#endif
///////////////////////////////////////////////////////////////////////////////////
#ifdef HAVE_SLAVE_IIC
/******************************************************************************
��������  I2C_Slave_Config
����������I2C����ģʽ���ܳ�ʼ��
�������: 
					i2cadr	 //���豸��ַ

����ֵ�� ��					

******************************************************************************/
void I2C_Slave_Config(unsigned char i2cadr)
{	
	I2CCON = I2CE(1) | I2CIE(1) | STA(0) | STP(0)| CKHD(1) | AAK(1)| CBSE(0) | STFE(0); 
	//ʹ�� I2C������I2C �жϣ����� I2CF �� 1 ������ SCL������ START �źŲ����ж�	
	I2CADR = GCE(0)|(i2cadr>>1);//���豸��ַ
//////////////////////////////////////////////////////////////////////

	I2CCCR = 0x20;
	INT4EN = 1; //ʹ�� INT4 �ж�
}
#endif
/***********************************************************************************
�� �� ����	I2C_ISR										 	
����������	I2C �жϴ�����													
��    �룺	 ��								
��    �أ�	 ��														
***********************************************************************************/
void I2C_ISR(void)
{
	unsigned char Sta_Temp;
	///////////////////////��ģʽ�жϴ���////////////////////////////////////////////
	#ifdef HAVE_MASTER_IIC	
	if(I2CFLG & I2CF) //I2C �ж�
	{
			Sta_Temp = I2CSTA; //��ȡ I2C ״̬
			I2CSTA_STAUST=Sta_Temp;
			if(Sta_Temp == 0x08) //START �ź��Ѳ���
			{
					if(iicWriteRead && iic_rdSession)
					{
					I2CDAT = I2C_CurrDeviceAddr|1; //�����ݽ׶Σ����ʹӻ���ַ+��λ
					}
					else
					{
					I2CDAT = I2C_ADDR; //д���ݽ׶Σ����ʹӻ���ַ+дλ
					}
			}
			else if(Sta_Temp == 0x18) //��ַ+дλ�ѷ��ͣ��յ��ӻ�Ӧ��
			{
					I2CDAT = iic_regAddr; //���������׵�ַ
					iic_txIndex = 0;
					iicWriteNoAck=0;
			}
			else if(Sta_Temp == 0x20) //��ַ+дλ�ѷ��ͣ�û���յ�Ӧ���ź�
			{
					iicWriteNoAck=1;				
			}		
			else if(Sta_Temp == 0x28) //�ѷ��ͻ���յ�һ�ֽ����ݣ��յ��ӻ�Ӧ��
			{
				  if(iicWriteRead)
					{
							if(iic_rdSession) //�ж���д���ݽ׶λ��Ƕ����ݽ׶�
							{
								if(iic_rxIndex >= iic_rxLength) //����Ƕ����ݽ׶Σ��ж��Ƿ��Ѷ�ȡ������
								{
									I2CCON |= STP(1); //����Ѷ�ȡ�꣬���� STOP �ź�
									iicEnd = 1; //��λ������־
								}
								else
								{
									iic_TxRXBuf[iic_rxIndex+iic_regAddr] = I2CDAT; //��ȡһ�ֽ�����
									iic_rxIndex++;
									if(iic_rxIndex <= (iic_rxLength-1))
									{
									I2CCON |= AAK(1); //����������һ�ֽ����ݣ�����Ӧ���ź�
									}
									else
									{
									I2CCON &= ~AAK(1);//���һ�ֽ����ݷ��Ͳ�Ӧ���ź�
									} 
								} 
							}						
							else
							{
								I2CCON |= STA(1); //�����д���ݽ׶Σ����·��� START �ź�
								iic_rdSession = 1;
							}
					}
					else
					{
						/////////////////////��������//////////////////////////////////
						if(iic_txIndex >= iic_txLength) //�ж��Ƿ����������ѷ�����
						{
								iicWriteNoAck=0XFF;
								I2CCON |= STP(1); //����ѷ����������������� STOP �ź�
								iicEnd = 1; //��λ������־
						}
						else
						{
								I2CDAT = iic_TxRXBuf[iic_txIndex+iic_regAddr]; //��δ����������һ�ֽ�����
								iic_txIndex++;
								iicWriteNoAck=iic_txIndex;
						} 
						//iicWriteNoAck=0;
						/////////////////////////////////////////////////////
					} 
			
			}
			else if(Sta_Temp == 0x30) //��������/����һ�ֽ����ݣ�û���յ�Ӧ���ź�
			{
				  if(iicWriteRead)
					{
						if(iic_rdSession)
						{
								if(iic_rxIndex >= iic_rxLength) //�ж���������һ�ֽ����ݣ����� STOP �ź�
								{
									I2CCON |= STP(1);
								} 
								iicWriteNoAck=1;
						} 
					}		
					else
					{
								iicWriteNoAck=1;
					}
			}
			else if(Sta_Temp == 0x40) //�ӻ���ַ+��λ�ѷ��ͣ����յ�Ӧ���ź�
			{
				   I2CCON |= AAK(1); //�����ú�Ӧ��λ
				   iic_rxIndex=0;
					 iicWriteNoAck=0;
			}
			else if(Sta_Temp == 0x48) //�ӻ���ַ+��λ�ѷ��ͣ�û���յ�Ӧ���ź�
			{
						iicWriteNoAck=1;
			}			
			I2CFLG |= I2CF; //��� I2C �жϱ�־
	}
	#else
	///////////////////////��ģʽ�жϴ���////////////////////////////////////////////
	if(I2CFLG & I2CF)					 		//IIC  interrupt
	{						
		Sta_Temp = I2CSTA;			
		if(Sta_Temp == 0x60)			    	//���յ��ӻ���ַ+дλ
		{			
			I2CDataIndex = 0xFF;				//����Ϊ0xFF��ʾ������յ��ĵ�һ���ֽ�Ϊ��ַ
			iicReadMode = 0;					//����Ϊ�ӻ�����״̬
			I2CCON |= AAK(1);			
		}
		else if(Sta_Temp == 0x80)				//���ͻ����һ�ֽ����ݣ��Ѽ�⵽Ӧ���ź�
		{					
			if(iicReadMode)	 					//����һ�ֽ�����
			{
				I2CDataIndex++;
				I2CDAT = iic_TxRXBuf[I2CDataIndex + regAddr];		//������װ�ص����ͼĴ������ȴ�������ȡ
			}
			else												//���յ�һ�ֽ�����
			{				
				if(I2CDataIndex == 0xFF) 	//��ַ
				{
					regAddr = I2CDAT;	 						//���յ��ĵ�һ���ֽ���Ϊ�ǵ�ַ
			   	I2CDataIndex = 0;								//��������ֵΪ0
					I2CCON |= AAK(1);
				}
				else				   		//����
				{
					iic_TxRXBuf[I2CDataIndex + regAddr] = I2CDAT;		//���յ�������װ�ص����ݼĴ���	
					I2CDataIndex++;									//����ֵ�ۼ�
					I2CCON |= AAK(1);		
				}
			}	
		}
		else if(Sta_Temp==0xA8)				//���յ��ӻ���ַ+��λ������ACK�ź�
		{								
			I2CDAT = iic_TxRXBuf[I2CDataIndex + regAddr];	//������װ�ص����ͼĴ������ȴ�������ȡ
			iicReadMode = 1;							//����Ϊ�ӻ�����״̬
		}
		else if(Sta_Temp == 0x88)						//���ͻ����һ�ֽ����ݣ��Ѽ�⵽Ӧ���ź�
		{
		}
		I2CFLG  |= I2CF;					//����жϱ�־
	}		
	#endif
}
/***********************************************************************************
�� �� ����	I2C_Init										 	
����������	I2C ��ʼ��													
��    �룺	 ��								
��    �أ�	 ��														
***********************************************************************************/
void I2C_Init(void)
{
	#ifdef HAVE_MASTER_IIC
	I2C_Master_Config(I2C_ADDR,50);//50~100KHZ ͨѶƵ�� 
	#endif
	#ifdef HAVE_SLAVE_IIC
	I2C_Slave_Config(I2C_ADDR);//50~100KHZ ͨѶƵ�� 
	#endif	
	
	I2C_SelectComPin();//����������i2c�Ĵ����������ùܽ�
}
/***********************************************************************************/
#endif
#endif

