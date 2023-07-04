#include "led.h"
void LED_INIT(void)
{
GPIO_Init(LED_PROT, (GPIO_Pin_TypeDef)LED_Pin, GPIO_MODE_OUT_PP_LOW_FAST);
GPIO_WriteLow(LED_PROT,(GPIO_Pin_TypeDef)LED_Pin);
}