# 无限扩展的定时器

## functions

```c
multipletimer_type exmaple;//定义一个定时器对象。

void function_exmaple(void)//定时器回调函数。
{
    ...
}

multipletimer_tick();//此函数每100us执行一次。

int main(void)
{
    multipletimer_init(&example,10000,function_exmaple);//初始化一个定时器对象，10000:10000*100us=1s→此定时器一秒执行一次function_exmaple函数。
    multipletimer_add(&exmaple);//将此结构体添加到链表中。
    while(1){
        multipletimer_run();
    }
}









```
