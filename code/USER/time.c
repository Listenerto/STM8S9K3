#include "time.h"
volatile u8 us_flag;
 u16 count=2 ;     //通过这个参数改变led刷新速度，最小1ms
 bool t1s_flag = 0,key_flag =0;

struct time_delay TIME1_delay = 
{
0,
0,	
0,
0,
0,	
0,
0,		
};
void TIME1_INIT(u16 psc,u16 arr)
{
  /* TIM1 configuration:
   - TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM1 counter
   clock used is 16 MHz / 160 = 100000Hz  10us*100 =1ms
 */

  /* Time base configuration */
  TIM1_TimeBaseInit(psc,TIM1_COUNTERMODE_UP,arr,0x00);
  /* Time ENABLE ARRPre */
  TIM1_ARRPreloadConfig(ENABLE);
  /* Clear TIM1 update flag */
  TIM1_ClearFlag(TIM1_FLAG_UPDATE);
  /* Enable update interrupt */
  TIM1_ITConfig(TIM1_IT_UPDATE, ENABLE);
  
  /* enable interrupts */
  enableInterrupts();

  /* Enable TIM4 */
  TIM1_Cmd(ENABLE);

}
void TIME5_INIT(u16 arr)
{
  /* TIM1 configuration:
   - TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM1 counter
   clock used is 16 MHz / 16 = 100000Hz  1us*1 =1us
 */

  /* Time base configuration */
  TIM5_TimeBaseInit(TIM5_PRESCALER_16,arr);
  /* Time ENABLE ARRPre */
  TIM5_ARRPreloadConfig(ENABLE);
  /* Clear TIM1 update flag */
  TIM5_ClearFlag(TIM5_FLAG_UPDATE);
  /* Enable update interrupt */
  TIM5_ITConfig(TIM5_IT_UPDATE, ENABLE);
  
  /* enable interrupts */
  enableInterrupts();

  /* Enable TIM4 */
  TIM5_Cmd(ENABLE);

}
/*void Delay_us(u16 ms)
{
  count = ms;	//设定计数器值
  us_flag = 1;	//启动倒计时   
    while(us_flag);//等待时间结束，标志位则变成0跳出while语句
}*/
#pragma vector=13
__interrupt void timer1_over(void)
{
  TIME1_delay.count_1ms++;
  
  if(TIME1_delay.count_1ms%20==0)
  {
  key_flag =1;
  }
  if(TIME1_delay.count_1ms%count==0)
  {
    t1s_flag =1;
    
   // GPIO_WriteReverse(LED_PROT, (GPIO_Pin_TypeDef)LED_Pin);
  }
  
  /* Cleat Interrupt Pending bit */
  TIM1_ClearITPendingBit(TIM1_IT_UPDATE);
}

