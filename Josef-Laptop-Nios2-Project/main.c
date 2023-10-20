/*
 * PACEMAKER TIMING FOR FPGA DE2-115
 *
 * If nothing is happening, press KEY3 to re-initialise
 *
 */
// Remember to build the project if includes aren't working
#include <system.h> // Used for referencing symbolic names
#include <altera_avalon_pio_regs.h> // Used for PIO functions
#include <altera_avalon_uart_regs.h> // Used for UART functions
#include <stdio.h> // Used for NULL
#include <sys/alt_irq.h> // Used to register interrupts
#include <alt_types.h> // for
#include <stdbool.h> // Used to get bools for code readability
#include <sys/alt_alarm.h> // timers
#include "sccharts.h" // Sccharts implementation
#include "defines.h" // Includes quality-of-life variable changes
#include "timing.h" // Timeout values expected in MILLISECONDS
#include "led_control.h" // User-Defined LED Control functions

bool pulse_mode = UART_MODE;
bool implementation_mode = C_MODE;

bool atrial_event = false;
bool a_is_paced = false;
bool ventricular_event = false;
bool v_is_paced = false;

bool atrial_sense = false;
bool ventricular_sense = false;
bool atrial_sense_paced = false;
bool ventricular_sense_paced = false;

bool led_pace_atrial_event = false;
bool led_pace_ventricular_event = false;

bool led_sense_atrial_event = false;
bool led_sense_ventricular_event = false;

bool a_pace_led_timer_already_started = false;
bool v_pace_led_timer_already_started = false;

bool a_sense_led_timer_already_started = false;
bool v_sense_led_timer_already_started = false;

bool print_flag = false;
bool pulse_switched_flag = false;
bool implementation_switched_flag = true;

int current_event = ATRIAL_EVENT;

int a_timer_count = 0;
int v_timer_count = 0;

void buttons_interrupts_function(void* context, alt_u32 id)
{

	int* temp_button_value = (int*) context; // Cast the context before using it
	(*temp_button_value) = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);

	// clear the edge capture register
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);

	// If we are NOT in button mode, we exit early.
	if (pulse_mode == UART_MODE) {
		return;
	}

	if ((*temp_button_value & (1 << KEY1))) {
		send_atrial_event(false);
		//printf("Atrium Manually Sent!\n"); -- DEBUGGING PURPOSES
	}

	if ((*temp_button_value & (1 << KEY0))) {
		send_ventricular_event(false);
		//printf("Ventricular Manually Sent!\n"); -- DEBUGGING PURPOSES
	}

	/* -- DEBUGGING PURPOSES
	if ((*temp_button_value & (1 << 2))) {
		// reset leds -- DEBUGGING / CLEAR EVENTS
		atrial_event = false;
		ventricular_event = false;
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	}
	*/
}

alt_u32 a_pace_led_timer_isr_function(void* context) {
	led_pace_atrial_event = false;
	return LED_ON_MILLISECONDS;
}

alt_u32 v_pace_led_timer_isr_function(void* context) {
	led_pace_ventricular_event = false;
	return LED_ON_MILLISECONDS;
}

alt_u32 a_sense_led_timer_isr_function(void* context) {
	led_sense_atrial_event = false;
	return LED_ON_MILLISECONDS;
}

alt_u32 v_sense_led_timer_isr_function(void* context) {
	led_sense_ventricular_event = false;
	return LED_ON_MILLISECONDS;
}

void uart_read_isr_function(void* context, alt_u32 id)
{
	char temp;
	temp = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);

	// if we are NOT in UART MODE then exit early;
	if (pulse_mode == BUTTON_MODE) {
		if (atrial_event) {
			//printf("Atrial Transmitted to UART!\n"); -- DEBUGGING PURPOSES
		}

		if (ventricular_event) {
			//printf("Ventricular Transmitted to UART!\n"); -- DEBUGGING PURPOSES
		}
		return;
	}

	if (temp == 'A') {
		send_atrial_event(false);
	}
	if (temp == 'V') {
		send_ventricular_event(false);
	}
}

alt_u32 a_events_timer_isr_function(void* context) {
	int *a_timer_count =(int*) context;
	(*a_timer_count)++;
	return 1; // return 1 millisecond
}

alt_u32 v_events_timer_isr_function(void* context) {
	int *v_timer_count =(int*) context;
	(*v_timer_count)++;
	return 1; // return 1 millisecond
}

alt_u32 system_timer_isr_function(void* context) {
	int *system_timer_count = (int* ) context;
	(*system_timer_count)++;
	return 1; // return 1 millisecond
}

int main(void)
{
	printf("Starting.\n");

	unsigned int switch_value = 0;
	int button_value = 1;
	void* button_context = (void*) &button_value; // Cast before passing context to isr

	unsigned int system_time = 0;
	unsigned int previous_system_time = 0;
	TickData data;
	reset(&data);

	// LCD
	FILE *lcd;
	lcd = fopen(LCD_NAME, "w");

	//========= 	  INTERRUPTS  	   =========

	// Clear edge capture register
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);

	// Enable interrupts
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0x7);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(UART_BASE, 0x0080);

	// Register the isr
	alt_irq_register(KEYS_IRQ, button_context, buttons_interrupts_function);
	alt_irq_register(UART_IRQ, NULL, uart_read_isr_function);

	printf("Interrupts Initialised.\n");
	//========= 	  INTERRUPTS  	   =========
	//========= 	    TIMERS  	   =========
	// Lets LEDs stay on for 500 seconds.
	alt_alarm a_pace_led_timer;
	alt_alarm_start(&a_pace_led_timer, LED_ON_MILLISECONDS, a_pace_led_timer_isr_function, NULL);

	alt_alarm v_pace_led_timer;
	alt_alarm_start(&v_pace_led_timer, LED_ON_MILLISECONDS, v_pace_led_timer_isr_function, NULL);

	alt_alarm a_sense_led_timer;
	alt_alarm_start(&a_sense_led_timer, LED_ON_MILLISECONDS, a_sense_led_timer_isr_function, NULL);

	alt_alarm v_sense_led_timer;
	alt_alarm_start(&v_sense_led_timer, LED_ON_MILLISECONDS, v_sense_led_timer_isr_function, NULL);

	alt_alarm system_timer;
	int system_timer_count = 0;
	void *system_timer_context = (void*) &system_timer_count;
	alt_alarm_start(&system_timer, 1, system_timer_isr_function, system_timer_context);

	alt_alarm a_events_timer;
	// a_timer_count = 0;
	void *a_events_timer_context = (void*) &a_timer_count;
	alt_alarm_start(&a_events_timer, 1, a_events_timer_isr_function, a_events_timer_context);

	alt_alarm v_events_timer;
	//int v_timer_count = 0;
	void *v_events_timer_context = (void*) &v_timer_count;
	alt_alarm_start(&v_events_timer, 1, v_events_timer_isr_function, v_events_timer_context);


	//========= 	    TIMERS  	   =========
	printf("Timers Initialised.\n");

	printf("Entering Loop.\n");
	while(1) {
		previous_system_time = system_time;
		system_time = system_timer_count;
		data.AS = 0;
		data.VS = 0;
		data.deltaT = system_time - previous_system_time;
		//tick(&data);

		// Get switch state from switch peripheral (returns a binary)
		switch_value = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);

		// CHECK FOR PULSE MODE == CHECK FOR PULSE MODE == CHECK FOR PULSE MODE ==
		// CHECK FOR PULSE MODE == CHECK FOR PULSE MODE == CHECK FOR PULSE MODE ==
		set_pulse_mode_on_switch(switch_value);
		// CHECK FOR PULSE MODE == CHECK FOR PULSE MODE == CHECK FOR PULSE MODE ==
		// CHECK FOR PULSE MODE == CHECK FOR PULSE MODE == CHECK FOR PULSE MODE ==

		// CHECK FOR IMPLEMENTATION MODE == CHECK FOR IMPLEMENTATION MODE ==
		// CHECK FOR IMPLEMENTATION MODE == CHECK FOR IMPLEMENTATION MODE ==
		set_implementation_mode_on_switch(switch_value);
		// CHECK FOR IMPLEMENTATION MODE == CHECK FOR IMPLEMENTATION MODE ==
		// CHECK FOR IMPLEMENTATION MODE == CHECK FOR IMPLEMENTATION MODE ==

		// CHECK FOR ATRIAL AND VENTRICULAR EVENTS == CHECK FOR ATRIAL AND VENTRICULAR EVENTS ==
		// CHECK FOR ATRIAL AND VENTRICULAR EVENTS == CHECK FOR ATRIAL AND VENTRICULAR EVENTS ==
		if (atrial_event) {
			atrial_event = false; // COULD BE A PROBLEM?
			// Reset timer if atrial event is sensed after PVARP
			// Atrial sense is when a valid atrial event happens
			// (happening after PVARP and last event as an ventricular event)
			if (implementation_mode == C_MODE) {
				if (v_timer_count >= PVARP_VALUE && current_event == VENTRICULAR_EVENT) {
					current_event = ATRIAL_EVENT;
					atrial_sense = true;
					ventricular_sense = false;
					a_timer_count = 0;
				}
			} else if (implementation_mode == SCCHARTS_MODE) {
				if (!a_is_paced) {
					data.AS = 1;
				} else {
					data.AS = 0;
				}
			}
			if (a_is_paced) {
				led_pace_atrial_event = true;
				atrial_sense_paced = true;
				//printf("Atrial Sensed! - Paced!\n"); -- DEBUGGING
			} else {
				led_sense_atrial_event = true;
				atrial_sense_paced = false;
				//printf("Atrial Sensed! - Not Paced\n"); -- DEBUGGING
			}
			a_is_paced = false;
		}
		if (ventricular_event) {
			ventricular_event = false;
			if (implementation_mode == C_MODE) {
				// Reset timer if ventricular event is sensed after VRP
				// Ventricular sense is when a valid ventricular event happens
				// (happening after VRP and last event as an atrial event)
				if (v_timer_count >= VRP_VALUE && current_event == ATRIAL_EVENT) {
					//printf("Valid Ventricle Sense!\n"); - DEBUGGING
					current_event = VENTRICULAR_EVENT;
					ventricular_sense = true;
					atrial_sense = false;
					v_timer_count = 0;
				}

			} else if (implementation_mode == SCCHARTS_MODE) {
				if (!v_is_paced) {
					data.VS = 1;
				}
				else {
					data.VS = 0;
				}
			}
			if (v_is_paced) {
				led_pace_ventricular_event = true;
				ventricular_sense_paced = true;
				//printf("Ventricle Sensed! -- Paced\n"); -- DEBUGGING PURPOSES
			} else {
				led_sense_ventricular_event = true;
				ventricular_sense_paced = false;
				//printf("Ventricle Sensed! -- Not Paced\n"); -- DEBUGGING PURPOSES
			}
			if (!ventricular_sense) {
				led_pace_ventricular_event = false;
				led_sense_ventricular_event = false;
			}
			v_is_paced = false;
		}
		// CHECK FOR ATRIAL AND VENTRICULAR EVENTS == CHECK FOR ATRIAL AND VENTRICULAR EVENTS ==
		// CHECK FOR ATRIAL AND VENTRICULAR EVENTS == CHECK FOR ATRIAL AND VENTRICULAR EVENTS ==

		// IMPLEMENTATION MODE == IMPLEMENTATION MODE == IMPLEMENTATION MODE ==
		// IMPLEMENTATION MODE == IMPLEMENTATION MODE == IMPLEMENTATION MODE ==
		// Execute respective pacemaker timing depending on current implementation mode
		if (implementation_mode == C_MODE) {
			c_mode_pacemaker(a_timer_count, v_timer_count);
		} else if (implementation_mode == SCCHARTS_MODE) {
			tick(&data);

			int a_test = data.AP;
			int v_test = data.VP;

			// Send respective pace events if AP or VP are true
			if (a_test) {
				send_atrial_event(true);
			}
			if (v_test) {
				send_ventricular_event(true);
			}
		}
		// IMPLEMENTATION MODE == IMPLEMENTATION MODE == IMPLEMENTATION MODE ==
		// IMPLEMENTATION MODE == IMPLEMENTATION MODE == IMPLEMENTATION MODE ==

		// PACE LEDS == PACE LEDS == PACE LEDS == PACE LEDS ==
		// PACE LEDS == PACE LEDS == PACE LEDS == PACE LEDS ==
		// Set left side of GREEN LEDs on atrial pace event
		if (led_pace_atrial_event) {
			// LEDs active delay logic
			if (!a_pace_led_timer_already_started) {
				alt_alarm_stop(&a_pace_led_timer);
				alt_alarm_start(&a_pace_led_timer, LED_ON_MILLISECONDS, a_pace_led_timer_isr_function, NULL);
				a_pace_led_timer_already_started = true;
			}
			// Sets GREEN PACE LEDs depending on implementation mode
			if (implementation_mode == C_MODE) {
				set_green_leds_x_to_x(LEDG4, LEDG7);
			} else if (implementation_mode == SCCHARTS_MODE) {
				set_half_green_leds_x_to_x(LEDG4, LEDG7);
			}
		}
		// Set right side of GREEN LEDs on ventricular pace event
		if (led_pace_ventricular_event) {
			if (!v_pace_led_timer_already_started) {
				// LEDs active delay logic
				alt_alarm_stop(&v_pace_led_timer);
				alt_alarm_start(&v_pace_led_timer, LED_ON_MILLISECONDS, v_pace_led_timer_isr_function, NULL);
				v_pace_led_timer_already_started = true;
			}
			// Sets GREEN PACE LEDs depending on implementation mode
			if (implementation_mode == C_MODE) {
				set_green_leds_x_to_x(LEDG0, LEDG3);
			} else if (implementation_mode == SCCHARTS_MODE) {
				set_half_green_leds_x_to_x(LEDG0, LEDG3);
			}

		}
		// PACE GREEN LEDS == PACE GREEN LEDS == PACE GREEN LEDS == PACE GREEN LEDS == PACE GREEN LEDS ==
		// PACE GREEN LEDS == PACE GREEN LEDS == PACE GREEN LEDS == PACE GREEN LEDS == PACE GREEN LEDS ==

		// SENSE RED LED IMPLENENTATION == SENSE RED LED IMPLENENTATION ==SENSE RED LED IMPLENENTATION ==
		// SENSE RED LED IMPLENENTATION == SENSE RED LED IMPLENENTATION ==SENSE RED LED IMPLENENTATION ==
		// Set left side of RED LEDs when atrial event is sensed
		if (led_sense_atrial_event) {
			// LEDs active delay logic
			if (!a_sense_led_timer_already_started) {
				alt_alarm_stop(&a_sense_led_timer);
				alt_alarm_start(&a_sense_led_timer, LED_ON_MILLISECONDS, a_sense_led_timer_isr_function, NULL);
				a_sense_led_timer_already_started = true;
			}
			// Sets RED SENSE LEDs depending on implementation mode
			if (implementation_mode == C_MODE) {
				set_red_leds_x_to_x(LEDR9, LEDR17);
			} else if (implementation_mode == SCCHARTS_MODE) {
				set_half_red_leds_x_to_x(LEDR9, LEDR17);
			}
		}
		// Set right side of RED LEDs when ventricular event is sensed
		if (led_sense_ventricular_event) {
			// LEDs active delay logic
			if (!v_sense_led_timer_already_started) {
				alt_alarm_stop(&v_sense_led_timer);
				alt_alarm_start(&v_sense_led_timer, LED_ON_MILLISECONDS, v_sense_led_timer_isr_function, NULL);
				v_sense_led_timer_already_started = true;
			}
			// Sets RED SENSE LEDs depending on implementation mode
			if (implementation_mode == C_MODE) {
				set_red_leds_x_to_x(LEDR0, LEDR8);
			} else if (implementation_mode == SCCHARTS_MODE) {
				set_half_red_leds_x_to_x(LEDR0, LEDR8);
			}
		}
		// SENSE RED LED IMPLENENTATION == SENSE RED LED IMPLENENTATION ==SENSE RED LED IMPLENENTATION ==
		// SENSE RED LED IMPLENENTATION == SENSE RED LED IMPLENENTATION ==SENSE RED LED IMPLENENTATION ==

		// LCD IMPLEMENTATION == LCD IMPLEMENTATION == LCD IMPLEMENTATION == LCD IMPLEMENTATION ==
		// LCD IMPLEMENTATION == LCD IMPLEMENTATION == LCD IMPLEMENTATION == LCD IMPLEMENTATION ==
		if (lcd != NULL) {
			// Print flag used to print once every time either mode changes
			// instead of every while iteration
			if (print_flag) {
				print_flag = false;
				// Call print to LCD function from lcd_control.c
				print_modes_to_lcd(lcd, implementation_mode, pulse_mode);
			}
		}
		// LCD IMPLEMENTATION == LCD IMPLEMENTATION == LCD IMPLEMENTATION == LCD IMPLEMENTATION ==
		// LCD IMPLEMENTATION == LCD IMPLEMENTATION == LCD IMPLEMENTATION == LCD IMPLEMENTATION ==

		// CALL CLEAR LED FUNCTIONS
		// -- Only clears when the relevant flags are set.
		clear_pace_led_events();
		clear_sense_led_events();
	}
	printf("Exiting Loop.\n");
	return 0;
}

/**
 * Sets the atrial event flag to true when ANY atrial event is sensed
 *
 * bool isThisEventPaced - Sets the a_is_paced flag to true if this event is paced
 */
void send_atrial_event(bool isThisEventPaced) {
	// Ventricular event == true when ANY sort of event happens
	if (isThisEventPaced) {
		a_is_paced = true;
		char atrial_char = 'A';
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, atrial_char);
	} else {
		a_is_paced = false;
	}
	atrial_event = true;
	//printf("Atrial Event Flagged!\n"); -- DEBUGGINGS PURPOSES
}

/**
 * Sets the ventricular event flag to true when ANY ventricular event is sensed
 *
 * bool isThisEventPaced - Sets the v_is_paced flag to true if this event is paced
 */
void send_ventricular_event(bool isThisEventPaced) {
	if (isThisEventPaced) {
		v_is_paced = true;
		char ventricular_char = 'V';
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, ventricular_char);
	} else {
		v_is_paced = false;
	}
	ventricular_event = true;
	//printf("Ventricular Event Flagged!\n"); -- DEBUGGINGS PURPOSES
}

/**
 * Clears the atrium/ventricle pace green LEDs
 */
void clear_pace_led_events() {
	// If LED flag for atrial pace is no longer on, clear LEDs
	if (!led_pace_atrial_event) {
		a_pace_led_timer_already_started = false;
		// Call clear relevant green LEDs function from led_control.c
		clear_green_leds_x_to_x(LEDG4, LEDG7);
	}
	// If LED flag for atrial pace is no longer on, clear LEDs
	if (!led_pace_ventricular_event) {
		v_pace_led_timer_already_started = false;
		// Call clear relevant green LEDs function from led_control.c
		clear_green_leds_x_to_x(LEDG0, LEDG3);
	}
}

/**
 * Clears the atrium/ventricle sense red LEDs
 */
void clear_sense_led_events() {
	// If LED flag for atrial sense is no longer on, clear LEDs
	if (!led_sense_atrial_event) {
		a_sense_led_timer_already_started = false;
		// Call clear relevant red LEDs function from led_control.c
		clear_red_leds_x_to_x(LEDR9, LEDR17);
	}
	// If LED flag for ventricular sense is no longer on, clear LEDs
	if (!led_sense_ventricular_event) {
		v_sense_led_timer_already_started = false;
		// Call clear relevant red LEDs function from led_control.c
		clear_red_leds_x_to_x(LEDR0, LEDR8);
	}
}

/**
 * This function is used for the C-based pacemaker, using atrium and ventricle timer counts presumably defined
 * within main.
 *
 * Using a_timer_count and v_timer_count, it sends an atrial event or ventricle event depending on the
 * conditions and current events of the pacemaker
 *
 * int a_timer_count - the count from an atrium alt_alarm
 * int v_timer_count - the count from a ventricle alt_alarm
 */
void c_mode_pacemaker(int a_timer_count, int v_timer_count) {
	// Pace atrium if ventricular timer count is above AEI value, atrial event hasn't been hit yet, and
	// the last event was a ventricular event.
	if (v_timer_count >= AEI_VALUE && !atrial_sense && current_event == VENTRICULAR_EVENT) {
		send_atrial_event(true);
	}
	// Do not pace ventricle until ventricular timer count is above URI
	if (v_timer_count >= URI_VALUE) {
		// Pace ventricle if timer count is above AVI, venetricular event hasn't happened and
		// the last event was an atrial event
		if (a_timer_count >= AVI_VALUE && !ventricular_sense && current_event == ATRIAL_EVENT) {
			send_ventricular_event(true);
		}
		// Pace ventricle if timer count is above LRI, ventricular event hasn't happened and
		// the last event was an atrial event
		if (v_timer_count >= LRI_VALUE && !ventricular_sense && current_event == ATRIAL_EVENT) {
			send_ventricular_event(true);
		}
	}
}

void set_pulse_mode_on_switch(int switch_value) {
	if (switch_value & (1 << PULSE_MODE_SWITCH)) {
		// Set print flag when swtiched
		if (!pulse_switched_flag) {
			pulse_switched_flag = true;
			print_flag = true;
		}
		// SW0 is ON
		pulse_mode = BUTTON_MODE;
	} else if (!(switch_value & (1 << PULSE_MODE_SWITCH))) {
		// Set print flag when switched
		if (pulse_switched_flag) {
			pulse_switched_flag = false;
			print_flag = true;
		}
		// SW0 is OFF
		pulse_mode = UART_MODE;
	}
}

void set_implementation_mode_on_switch(int switch_value) {
	if (switch_value & (1 << IMPLEMENTAITON_MODE_SWITCH)) {
		// Set switched flag for printing to LCD
		if (!implementation_switched_flag) {
			implementation_switched_flag = true;
			print_flag = true;
		}
		// SW1 is ON
		implementation_mode = SCCHARTS_MODE;
	} else if (!(switch_value & (1 << IMPLEMENTAITON_MODE_SWITCH))) {
		// Set switched flag for printing to LCD
		if (implementation_switched_flag) {
			implementation_switched_flag = false;
			print_flag = true;
		}
		// SW1 is OFF
		implementation_mode = C_MODE;
	}
}

