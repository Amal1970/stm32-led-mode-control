#ifndef LED_H_
#define LED_H_

#include <stdint.h>

#define LED_GREEN 12U
#define LED_ORANGE 13U
#define LED_RED 14U
#define LED_BLUE 15U



#define RCC_AH1BENR (*(volatile uint32_t *)0x40023830U)
#define GPIOD_MODER (*(volatile uint32_t *)0x40020C00U)
#define GPIOD_ODR (*(volatile uint32_t *)0x40020C14U)

// PROTOTYPES
void led_init(void);
void led_on(uint8_t pin);
void led_off(uint8_t pin);
void led_toggle(uint8_t pin);


#endif