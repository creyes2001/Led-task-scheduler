#include "scheduler.h"
#include "timer.h"
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

int main(void)
{
	while(1)
	{

	}
return 0;
}
