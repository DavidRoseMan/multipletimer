#ifndef _multipletimer_H_
#define _multipletimer_H_


#include <stdio.h>
#include <stddef.h>

typedef xdata struct multipletimer{
	volatile unsigned int status;
	volatile unsigned int value;
	struct multipletimer* next;
	void(*func_cb)(void);
//	volatile unsigned char control;
}multipletimer_type;


void multipletimer_init(multipletimer_type* p_timer,unsigned int value,void(*func_cb)(void));
void multipletimer_add(multipletimer_type* p_timer);
void multipletimer_run(void);
void multipletimer_tick(void);


#endif
