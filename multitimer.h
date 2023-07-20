#ifndef _MULTITIMER_H_
#define _MULTITIMER_H_


#include <stdio.h>
#include <stddef.h>

typedef xdata struct timer_parameters{
	volatile unsigned int status;
	volatile unsigned int value;
	struct timer_parameters* next;
	void(*func_cb)(void);
//	volatile unsigned char control;
}timer_para;


void multitimer_init(timer_para* p_timer,unsigned int value,void(*func_cb)(void));
void multitimer_add(timer_para* p_timer);
void multitimer_run(void);
void multitimer_tick(void);


#endif
