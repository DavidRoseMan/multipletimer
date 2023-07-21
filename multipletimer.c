#include "multipletimer.h"

multipletimer_type* xdata timer_head=NULL;

void multipletimer_init(multipletimer_type* p_timer,unsigned int value,void(*func_cb)(void))
{
	p_timer->status=0;
	p_timer->value=value;
	p_timer->func_cb=func_cb;
	p_timer->next=NULL;
}

void multipletimer_add(multipletimer_type* p_timer)
{
	multipletimer_type* xdata p_temp;
	p_temp = timer_head;
	if(p_temp)
	{
		while(p_temp->next)
		{
			p_temp=p_temp->next;
		}
		p_temp->next=p_timer;
	}
	else
	{
		timer_head=p_timer;
	}
}

void multipletimer_run(void)
{
	multipletimer_type* p_temp = timer_head;
	
	while(p_temp)
	{
		if(p_temp->status>=p_temp->value)
		{
			p_temp->func_cb();
			p_temp->status=0;
		}
		p_temp=p_temp->next;
	}

}

void multipletimer_tick(void)
{
	multipletimer_type* xdata p_temp = timer_head;
	
	while(p_temp)
	{
		if(p_temp->status<p_temp->value)
		{
			p_temp->status++;
		}
		else
		{
			p_temp->status=p_temp->value;
		} 
		p_temp=p_temp->next;
	}
}
