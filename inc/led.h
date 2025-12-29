#ifndef LED_H
#define LED_H

#include <stdint.h>

typedef enum {
	LED_OFF,
	LED_ON
}led_state_t;


void led_int(void);
void led_on(uint8_t led_id);
void led_off(uint8_t led_id);
void led_toggle(uint8_t led_id);

#endif
