#include "led.h"
#include "gpio.h"
#include <xc.h>

gpio_t led1 = {
	.port = &PORTD,
	.tris = &TRISD,
	.lat = &LATD,
	.pin = 0
};

gpio_t led2 = {
	.port = &PORTD,
	.tris = &TRISD,
	.lat = &LATD,
	.pin = 1
};

void led_int(void){
	//config and set as low both led's
	gpio_init(&led1,GPIO_OUTPUT);
	gpio_write(&led1,GPIO_LOW);
	gpio_init(&led2,GPIO_OUTPUT);
	gpio_write(&led2,GPIO_LOW);
}

void led_on(uint8_t led_id){
	switch(led_id)
	{
		case 0:
			gpio_write(&led1,GPIO_HIGH);
			break;
		case 1:
			gpio_write(&led2,GPIO_HIGH);
			break;
		default:
			break;
	}
}

void led_off(uint8_t led_id){
	switch(led_id)
	{
		case 0:
			gpio_write(&led1,GPIO_LOW);
			break;
		case 1:
			gpio_write(&led2,GPIO_LOW);
			break;
		default:
			break;
	}
}

void led_toggle(uint8_t led_id){
	switch(led_id)
	{
		case 0:
			gpio_toggle(&led1);
			break;
		case 1:
			gpio_toggle(&led2);
			break;
		default:
			break;
	}
}

