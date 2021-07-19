#ifndef __AD5505_H
#define __AD5505_H
#include "main.h"
#define DAC_A 0X01
#define DAC_B 0X02
#define DAC_C 0X03
#define DAC_D 0X04
#define DAC_ALL 0X05
#define DAC_CON 0X07
void AD5504_Set(unsigned char reg,unsigned short data);
void AD5504_Get(unsigned char reg);
#endif
