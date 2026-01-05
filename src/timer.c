#include <xc.h>
#include "timer.h"

void timer0_init(void)
{
	/*Timer 0 configuration for 1 ms tick
	 FOSC = 20 MHz
	 Instruction clock = Fosc / 4 = 5 MHz
	 Timer tick = 0.2 us
	 */
	T0CON = 0; //configure later explicitly
	T0CONbits.T08BIT = 0; //16-bit mode
	T0CONbits.T0CS = 0; //internal clock
	T0CONbits.PSA = 0; //prescaler assigned
	T0CONbits.T0PS = 0b010; //prescaler 1:8
	
	/* preload value for 1 ms */
	TMR0H = 0xF6;
	TMR0L = 0x3C;

	INTCONbits.TMR0IF = 0; //eneable TMR0 interrupt
	INTCONbits.TMR0IE = 1; //eneable TMR0 interrupt

	INTCONbits.GIE = 1; //enable global interrupts

	T0CONbits.TMR0ON = 1; //start timer

}
