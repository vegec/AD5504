#include "ad5504.h"
/**************（C）COPYRIGHT 2021 射频与集成电路与系统研究中心*******************
* 函数名   : AD5504_Set
* 功能说明 : 向AD5504写入数据
* 参数说明 : 
*			 reg:
*						DAC_A     DAC A 寄存器
*						DAC_B     DAC B 寄存器
*						DAC_C     DAC C 寄存器
*						DAC_D     DAC D 寄存器
*						DAC_ALL   所有DAC寄存器
*						DAC_CON   控制寄存器
*			 data:
						写入数据的具体数值，12位
* 函数返回 : 无
* 备注     : 
* 作者     : 
* 修改时间 : 2021.07.19
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
/**************（C）COPYRIGHT 2021 射频与集成电路与系统研究中心*******************
* 函数名   : AD5504_Get
* 功能说明 : 向AD5504写入数据
* 参数说明 : 
*			 reg:
*						0x01   DAC A 寄存器
*						0x02   DAC B 寄存器
*						0x03   DAC C 寄存器
*						0x04   DAC D 寄存器
*						0x05   所有DAC寄存器
*						0x07   控制寄存器
* 函数返回 : 无
* 备注     : 
* 作者     : 
* 修改时间 : 2021.07.19
*******************************************************************************/
void AD5504_Get(unsigned char reg){
			uint16_t  SPI_TxBuff[1],SPI_RxBuff[1];
			SPI_TxBuff[0] = ((reg<<12))|0x8000;
			HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_RESET);		
			HAL_SPI_TransmitReceive(&hspi1,(uint8_t*)SPI_TxBuff,(uint8_t*)SPI_RxBuff,1,10);
			HAL_GPIO_WritePin(SYNC1_GPIO_Port, SYNC1_Pin, GPIO_PIN_RESET);

}
