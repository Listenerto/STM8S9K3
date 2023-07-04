#include "key.h"



void Key_INT(void)
{
  
  GPIO_Init(KEY_PROT, (GPIO_Pin_TypeDef)KEY_Pin, GPIO_MODE_IN_PU_NO_IT);//…œ¿≠ ‰»Î
  
}
u8 Read_KEY(void)
{
  if(!GPIO_ReadInputPin(KEY_PROT,KEY1))
    return 1;
  else if (!GPIO_ReadInputPin(KEY_PROT,KEY2))
    return 2;
  else if (!GPIO_ReadInputPin(KEY_PROT,KEY3))
    return 3;
  return 0;
}



