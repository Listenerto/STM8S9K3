#ifndef _SHOW595_H_
#define _SHOW595_H_
#include "projob.h"
//定义74HC595控制管脚
#define PCout1(x)   GPIOC->ODR |= (uint8_t)x
#define PCout0(x)   GPIOC->ODR &= (uint8_t)(~x)


extern const u8 ghc595_buf[8];
extern const u8 text2[20];
extern const u8 smile[96],my_name[216],Six[36],Lightning[96],Love[96],Like[96];
extern  bool hapen_flag;
void delay_ms(u16 ms);
void delay_10us(u16 ten_us);
void INIT_74HC595(void);
void hc595_write_data(u8 dat);
void show_24high(u8 dat1,u8 dat2,u8 dat3);
void Show_bmp(const u8 *dat,u8 wigth);
void Show_bmp_L(const u8 *dat,u8 wigth);

void Flowing_LED(void);
#endif