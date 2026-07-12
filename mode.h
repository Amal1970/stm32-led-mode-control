#ifndef MODE_H_
#define MODE_H_

#include <stdint.h>

#define SLOW_TICK 500
#define FAST_TICK 100

typedef enum{
	OFF,
	ON,
	BLINK_SLOW,
	BLINK_FAST
}States;

typedef struct{
	States current_state;
	uint32_t state_start_tick;
	uint32_t green_tick_rate;
	uint8_t prev_button_state;
}Mode_t;

extern Mode_t modes;
extern volatile uint32_t g_tick_count;

// prototypes
void modes_init(void);
void modes_update(void);

#endif