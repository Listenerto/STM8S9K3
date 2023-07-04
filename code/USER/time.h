#ifndef _TIME_H_
#define _TIME_H_
#include "projob.h"
struct time_delay
{
        uint32_t count_1ms;
	
	uint32_t count_5ms;	
	
	uint32_t count_10ms;	

	uint32_t count_50ms;	
	
	uint32_t count_100ms;	

	uint32_t count_200ms;
        
	uint32_t count_400ms;
};

extern struct time_delay TIME1_delay;
extern  bool t1s_flag,key_flag;
extern u16 count ;
void TIME1_INIT(u16 psc,u16 arr);
void TIME5_INIT(u16 arr);
//void Delay_us(u16 ms);
#endif

