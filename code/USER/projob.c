#include "projob.h"
bool mode=0;
 u8 i=0,show_pacg =0;
u8  key_down,key_val=0;
//u16 a=50000;
void led_test(void)
{
  if(!mode)  
  {
    switch(show_pacg)
  {  
  case 0:
    Show_bmp(smile,32);break;
  case 1:
    Show_bmp(Like,32);
    break;
    case 2:
     Show_bmp(Love,32); 
    break;
    case 3:
     Show_bmp_L(Love,32);break;
    case 4:
     Show_bmp(Lightning,32); 
    break;     
    case 5:
    Show_bmp(Six,12);break;
    case 6:
    Show_bmp(my_name,72);break;
  default : break;
  }
 
  }
   else 
  {
   Flowing_LED();
  }
}
void KEY_projob(void)
{
    static uint8_t key_old;

    key_val = Read_KEY();
    key_down=key_val&(key_val^key_old);
    key_old = key_val;
    switch(key_down)
    {
    case 1:
      {
      if(!mode)
       {  
      if(show_pacg++>=6)show_pacg =0;
       }
      else
      {
      if(show_pacg++>=2)show_pacg =0;
      }
      }break;
    case 2:
      {
       if(!mode)
       {
       if((count+=2) >=10)count =2;
       }
       else 
       {
       if((count+=100) >=1000)count =100;
       }
       GPIO_WriteHigh(LED_PROT,(GPIO_Pin_TypeDef)LED_Pin); 
      }break;
    case 3:
      {
       mode=!mode;  
       hapen_flag = 0;
       show_24high(0,0,0);
       if(!mode)count =2;
       else count =100;
      GPIO_WriteReverse(LED_PROT,(GPIO_Pin_TypeDef)LED_Pin);
      }break;
    default : break;
    }



}