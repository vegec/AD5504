#include "ad5504.h"
/**************��C��COPYRIGHT 2021 ��Ƶ�뼯�ɵ�·��ϵͳ�о�����*******************
* ������   : AD5504_Set
* ����˵�� : ��AD5504д������
* ����˵�� : 
*			 reg:
*						DAC_A     DAC A �Ĵ���
*						DAC_B     DAC B �Ĵ���
*						DAC_C     DAC C �Ĵ���
*						DAC_D     DAC D �Ĵ���
*						DAC_ALL   ����DAC�Ĵ���
*						DAC_CON   ���ƼĴ���
*			 data:
						д�����ݵľ�����ֵ��12λ
* �������� : ��
* ��ע     : 
* ����     : 
* �޸�ʱ�� : 2021.07.19
*******************************************************************************/
void AD5504_Set(unsigned char reg,unsigned short data){
/*
	*		uint8_t  SPI_TxBuff[2];
	*   SPI_TxBuff[0] = ((reg<<4)|data>>8)&0x7f;
	*		SPI_TxBuff[1] = data&0x00ff;
	*		HAL_SPI_Transmit(&hspi1, (uint8_t*)SPI_TxBuff,2,10);
	*
	*/
			uint16_t  SPI_TxBuff[1];
			SPI_TxBuff[0] = ((reg<<12)|data)&0x7fff;
			HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_RESET);
			HAL_SPI_Transmit(&hspi1, (uint8_t*)SPI_TxBuff,1,10);
			HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_SET);

}
/**************��C��COPYRIGHT 2021 ��Ƶ�뼯�ɵ�·��ϵͳ�о�����*******************
* ������   : AD5504_Get
* ����˵�� : ��AD5504д������
* ����˵�� : 
*			 reg:
*						0x01   DAC A �Ĵ���
*						0x02   DAC B �Ĵ���
*						0x03   DAC C �Ĵ���
*						0x04   DAC D �Ĵ���
*						0x05   ����DAC�Ĵ���
*						0x07   ���ƼĴ���
* �������� : ��
* ��ע     : 
* ����     : 
* �޸�ʱ�� : 2021.07.19
*******************************************************************************/
void AD5504_Get(unsigned char reg){
			uint16_t  SPI_TxBuff[1],SPI_RxBuff[1];
			SPI_TxBuff[0] = ((reg<<12))|0x8000;
			HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_RESET);		
			HAL_SPI_TransmitReceive(&hspi1,(uint8_t*)SPI_TxBuff,(uint8_t*)SPI_RxBuff,1,10);
			HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_RESET);

}
