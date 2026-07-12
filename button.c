#include "button.h"

void button_init(void){
	RCC_AH1BENR |=(1<<0);

	// input mode
	GPIOA_MODER &= ~(3<<0);
}

uint8_t button_pressed(void){
	return (GPIOA_IDR&1);
}
