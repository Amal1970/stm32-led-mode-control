#ifndef BUTTON_H_
#define BUTTON_H_


#include <stdint.h>


#define RCC_AH1BENR (*(volatile uint32_t *)0x40023830U)
#define GPIOA_MODER (*(volatile uint32_t *)0x40020000U)
#define GPIOA_IDR   (*(volatile uint32_t *)0x40020010U)

void button_init(void);
uint8_t button_pressed(void);


#endif
