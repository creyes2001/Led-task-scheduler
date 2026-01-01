#include "scheduler.h"
#include "gpio.h"
#include "timer.h"
#include "led.h"
#include <xc.h>

void __interrupt() isr(void)
{
	if(INTCONbits.TMR0IF)
	{
		INTCONbits.TMR0IF = 0;

		/*reload for 1 ms*/
		TMR0H = 0xF6;
		TMR0L = 0x3C;

		scheduler_tick();
	}
}

void led_task(void)
{
	led_toggle(0);
}

int main(void)
{
	led_init();
	scheduler_init();
	timer0_init();

	scheduler_add_task(led_task, 500);

	while(1)
	{
		scheduler_run();
	}
return 0;
}
