#include "led.h"


void led_init(void){
	RCC_AH1BENR |=(1<<3);

	// set mode output
	GPIOD_MODER &=~((3<<24)|(3<<26)|(3<<28)|(3<<30));
	GPIOD_MODER |= (1<<24)|(1<<26)|(1<<28)|(1<<30);
}

void led_on(uint8_t pin){
	GPIOD_ODR |=(1<<pin);
}

void led_off(uint8_t pin){
	GPIOD_ODR &= ~(1<<pin);
}

void led_toggle(uint8_t pin){
	GPIOD_ODR ^= (1<<pin);
}