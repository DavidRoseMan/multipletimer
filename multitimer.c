#include "multitimer.h"

timer_para* timer_head=NULL;

void multitimer_init(timer_para* p_timer,unsigned int value,void(*func_cb)(void))
{
	p_timer->status=0;
	p_timer->value=value;
	p_timer->func_cb=func_cb;
	p_timer->next=NULL;
}

void multitimer_add(timer_para* p_timer)
{
	timer_para* p_temp;
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

void multitimer_run(void)
{
	timer_para* p_temp = timer_head;
	
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

void multitimer_tick(void)
{
	timer_para* p_temp = timer_head;
	
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
