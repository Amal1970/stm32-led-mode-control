#include "mode.h"
#include "led.h"
#include "button.h"


Mode_t modes;
// functions
void modes_init(void){
	modes.current_state = OFF;
	modes.state_start_tick = g_tick_count;
	modes.green_tick_rate = g_tick_count;
	modes.prev_button_state = 0;
	// will add things if needed

}


static void update_green_led(uint32_t rate){
	if((g_tick_count)-(modes.green_tick_rate)>=rate){
		led_toggle(LED_GREEN);
		modes.green_tick_rate = g_tick_count;
	}
}

static void change_mode(States state){
	modes.current_state = state;
	modes.state_start_tick = g_tick_count;

	if(state == BLINK_SLOW || state == BLINK_FAST){
		modes.green_tick_rate = g_tick_count;
	}
}


void modes_update(void){

	uint8_t curr_button_state = button_pressed();
	uint8_t button_event = 0;

	if(curr_button_state && !modes.prev_button_state){
		button_event = 1;
	}
	modes.prev_button_state = curr_button_state;

	switch(modes.current_state){
		case OFF :
			// led green off
			if(button_event){
				change_mode(ON);
			}
			break;
		case ON :
			led_on(LED_GREEN);
			if(button_event){
				change_mode(BLINK_SLOW);
			}
			break;
		case BLINK_SLOW :
			//uint32_t elapsed_time = g_tick_count - modes.state_start_tick;
			update_green_led(SLOW_TICK);
			if(button_event){
				change_mode(BLINK_FAST);
			}
			break;
		case BLINK_FAST :
			update_green_led(FAST_TICK);
			if(button_event){
				change_mode(OFF);
				led_off(LED_GREEN);
			}
			break;
		default :
			break;
	}
}