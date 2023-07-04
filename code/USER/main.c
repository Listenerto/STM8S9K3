            /*基于STM8S9k3芯片对HC757的驱动示例代码            */
            /*嘉立创开源作者：LMDLListen  作者B站：LStento     */
            /*             2023 .7. 4                          */
            /*            一起加油学习                         */
/* Includes ------------------------------------------------------------------*/
#include "projob.h"
/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void main(void)
{
  
  /* Clock divider to HSI/1 */
  CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);//16MHZ   
  LED_INIT();
  Key_INT();
  INIT_74HC595();
  delay_ms(2000);//延时500ms 
  TIME1_INIT(160,100);//16 MHz / 160 = 100000Hz  10us*100 =1ms
  //TIME5_INIT(1);有问题
  /* Infinite loop */
  while (1)
  {
    if(t1s_flag)
   {
   t1s_flag = 0; 
    led_test();  //点灯测试
   }
    if(key_flag)
    {
      key_flag =0;
      KEY_projob();
    }
  }
  
}
#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
