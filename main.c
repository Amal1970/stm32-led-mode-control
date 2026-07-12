#include <stdint.h>
#include "led.h"
#include "button.h"
#include "main.h"
#include "mode.h"

volatile uint32_t g_tick_count = 0;

int main(void)
{
	led_init();
	button_init();

	SysTick_init(TICK_HZ);

	modes_init();

	while(1);


}


void SysTick_init(uint32_t ticks){
	uint32_t count = ((SYS_TICK_HZ/ticks)-1);

	SYST_RVR = (count&0x00FFFFFFU);
	SYST_CVR = 0;

	// enable exception
	SYST_CSR |=(1<<1);
	// clock source
	SYST_CSR |=(1<<2);
	// enable counter
	SYST_CSR |=(1<<0);

}

void SysTick_Handler(void){
	g_tick_count++;
	modes_update();
}
