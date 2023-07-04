#ifndef _KEY_H_
#define _KEY_H_



#include "projob.h"

#define KEY_PROT GPIOB
#define KEY_Pin (GPIO_PIN_7|GPIO_PIN_6|GPIO_PIN_3)
#define KEY1 GPIO_PIN_3
#define KEY2 GPIO_PIN_6
#define KEY3 GPIO_PIN_7
void Key_INT(void);
u8 Read_KEY(void);
#endif