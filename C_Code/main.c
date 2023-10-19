/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */
// Remember to build the project if includes aren't working
#include <system.h> // Used for referencing symbolic names
#include <altera_avalon_pio_regs.h> // Used for PIO functions
#include <altera_avalon_uart_regs.h> // Used for UART functions
#include <stdio.h>
#include <sys/alt_irq.h> // Used to register interrupts
#include <alt_types.h> // for
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <sys/alt_alarm.h> // timers

// Timeout values expected in MILLISECONDS
#define AVI_VALUE 300
#define AEI_VALUE 800
#define PVARP_VALUE 50
#define VRP_VALUE 150
#define LRI_VALUE 950
#define URI_VALUE 900

#define PULSE_MODE_SWITCH 0
#define IMPLEMENTAITON_MODE_SWITCH 1

#define UART_MODE 0
#define BUTTON_MODE 1

#define C_MODE 0
#define SCCHARTS_MODE 1

#define KEY0 0
#define KEY1 1

#define LEDG0 0
#define LEDG1 1
#define LEDG2 2
#define LEDG3 3
#define LEDG4 4
#define LEDG5 5
#define LEDG6 6
#define LEDG7 7

#define LED_ON_MILLISECONDS 100

bool pulse_mode = UART_MODE;
bool implementation_mode = C_MODE;

bool atrial_event = false;
bool ventricular_event = false;
bool is_paced = false;

bool led_pace_atrial_event = false;
bool led_pace_ventricular_event = false;

bool led_sense_atrial_event = false;
bool led_sense_ventricular_event = false;

bool a_pace_led_timer_already_started = false;
bool v_pace_led_timer_already_started = false;

bool a_sense_led_timer_already_started = false;
bool v_sense_led_timer_already_started = false;

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


	if ((*temp_button_value & (1 << KEY0))) {
		//printf("KEY0 : ATRIAL EVENT!\n");
		send_atrial_event(true);
		printf("Atrium Paced!\n");
	}

	if ((*temp_button_value & (1 << KEY1))) {
		//printf("KEY1 : VENTRICULAR EVENT!\n");
		send_ventricular_event(true);
		printf("Ventricular Paced!\n");
	}

	if ((*temp_button_value & (1 << 2))) {
		// reset leds -- DEBUGGING / CLEAR EVENTS
		atrial_event = false;
		ventricular_event = false;
		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	}

	//printf("button pressed: %i\n", *temp_button_value); DEBUGGING PURPOSES
}

alt_u32 a_pace_led_timer_isr_function(void* context) {

	//IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	//int *led_time_count = (int*) context;
	led_pace_atrial_event = false;
	return LED_ON_MILLISECONDS;
}

alt_u32 v_pace_led_timer_isr_function(void* context) {

	//IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	//int *(led_time_count) = (int*) context;
	led_pace_ventricular_event = false;
	return LED_ON_MILLISECONDS;
}

alt_u32 a_sense_led_timer_isr_function(void* contxet) {
	led_sense_atrial_event = false;
	return LED_ON_MILLISECONDS;
}

alt_u32 v_sense_led_timer_isr_function(void* contxet) {
	led_sense_ventricular_event = false;
	return LED_ON_MILLISECONDS;
}

void uart_read_isr_function(void* context, alt_u32 id)
{
	// if we are NOT in UART MODE then exit early;

	char temp;
	temp = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);

	if (pulse_mode == BUTTON_MODE) {

		if (atrial_event) {
			printf("Atrial Sent!\n");
		}

		if (ventricular_event) {
			printf("Ventricular Sent!\n");
		}
		return;
	}

	if (temp == 'A') {
		send_atrial_event(false);
	}
	if (temp == 'V') {
		send_ventricular_event(false);
	}
	//printf("UART read: %c\n", temp);
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

int main(void)
{
	printf("Starting.\n");

	unsigned int switch_value = 0;
	int button_value = 1;
	void* button_context = (void*) &button_value; // Cast before passing context to isr
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

	alt_alarm a_events_timer;
	int a_timer_count = 0;
	void *a_events_timer_context = (void*) &a_timer_count;
	//alt_alarm_start(&a_events_timer, 1, a_events_timer_isr_function, a_events_timer_context);

	alt_alarm v_events_timer;
	int v_timer_count = 0;
	void *v_events_timer_context = (void*) &v_timer_count;
	//alt_alarm_start(&v_events_timer, 1, v_events_timer_isr_function, v_events_timer_context);


	//========= 	    TIMERS  	   =========
	printf("Timers Initialised.\n");

	printf("Entering Loop.\n");
	while(1) {
		// Get switch state from switch peripheral (returns a binary)
		switch_value = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);


		// ========= 	  PULSE MODES 	  =========
		if (switch_value & (1 << PULSE_MODE_SWITCH)) {
			// SW0 is ON
			pulse_mode = BUTTON_MODE;
		} else if (!(switch_value & (1 << PULSE_MODE_SWITCH))) {
			// SW0 is OFF
			pulse_mode = UART_MODE;
		}
		// ========= 	  PULSE MODES 	  =========

		// ========= IMPLEMENTATION MODES =========
		if (switch_value & (1 << IMPLEMENTAITON_MODE_SWITCH)) {
			// SW1 is ON
			implementation_mode = SCCHARTS_MODE;
		} else if (!(switch_value & (1 << IMPLEMENTAITON_MODE_SWITCH))) {
			// SW1 is OFF
			implementation_mode = C_MODE;
		}
		// ========= IMPLEMENTATION MODES =========

		// CHECK FOR ATRIAL AND VENTRICULAR EVENTS -- SENSING
		// CHECK FOR ATRIAL AND VENTRICULAR EVENTS -- SENSING
		if (atrial_event) {
			if (is_paced) {
				led_pace_atrial_event = true;
			} else {
				led_sense_atrial_event = true;
			}

			// If we are in C_Mode, restart timer
			if (implementation_mode == C_MODE) {
				a_timer_count = 0;
				alt_alarm_stop(&a_events_timer);
				alt_alarm_start(&a_events_timer, 1, a_events_timer_isr_function, a_events_timer_context);
			} else if (implementation_mode == SCCHARTS_MODE) {
				SCCHARTS_Mode_Pacemaker();
			}



			atrial_event = false;
			is_paced = false;
		}

		if (ventricular_event) {
			if (is_paced) {
				led_pace_ventricular_event = true;
			} else {
				led_sense_ventricular_event = true;
			}

			// do stuff
			ventricular_event = false;
			is_paced = false;
		}
		// CHECK FOR ATRIAL AND VENTRICULAR EVENTS -- SENSING
		// CHECK FOR ATRIAL AND VENTRICULAR EVENTS -- SENSING

		// IMPLEMENTATION
		// IMPLEMENTATION

		if (implementation_mode == C_MODE) {
			C_Mode_Pacemaker(a_timer_count, v_timer_count);
		} else if (implementation_mode == SCCHARTS_MODE) {
			SCCHARTS_Mode_Pacemaker();
		}
		// IMPLEMENTATION
		// IMPLEMENTATION


		// PACE LEDS == PACE LEDS == PACE LEDS == PACE LEDS ==
		// PACE LEDS == PACE LEDS == PACE LEDS == PACE LEDS ==
		if (led_pace_atrial_event) {
			if (!a_pace_led_timer_already_started) {
				alt_alarm_stop(&a_pace_led_timer);
				alt_alarm_start(&a_pace_led_timer, LED_ON_MILLISECONDS, a_pace_led_timer_isr_function, NULL);
				a_pace_led_timer_already_started = true;
			}
			int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);

			// SET ALL BITS UP FROM LEDG0 TO LEDG3
			for (int i = LEDG0; i < LEDG3 + 1; i++) {
				led_value = led_value |= (1<<i);
			}

			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);

		}

		if (led_pace_ventricular_event) {
			if (!v_pace_led_timer_already_started) {
				alt_alarm_stop(&v_pace_led_timer);
				alt_alarm_start(&v_pace_led_timer, LED_ON_MILLISECONDS, v_pace_led_timer_isr_function, NULL);
				v_pace_led_timer_already_started = true;
			}
			int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);

			// SET ALL BITS UP FROM LEDG0 TO LEDG3
			for (int i = LEDG4; i < LEDG7 + 1; i++) {
				led_value = led_value |= (1<<i);
			}

			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);

		}
		// PACE LEDS == PACE LEDS == PACE LEDS == PACE LEDS ==
		// PACE LEDS == PACE LEDS == PACE LEDS == PACE LEDS ==

		// SENSE LEDS == SENSE LEDS == SENSE LEDS == SENSE LEDS ==
		if (led_sense_atrial_event) {
			if (!a_sense_led_timer_already_started) {
				alt_alarm_stop(&a_sense_led_timer);
				alt_alarm_start(&a_sense_led_timer, LED_ON_MILLISECONDS, a_sense_led_timer_isr_function, NULL);
				a_sense_led_timer_already_started = true;
			}
			int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);

			// SET ALL BITS UP FROM LEDG0 TO LEDG3
			for (int i = 0; i < 9; i++) {
				led_value = led_value |= (1<<i);
			}

			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);

		}

		if (led_sense_ventricular_event) {
			if (!v_sense_led_timer_already_started) {
				alt_alarm_stop(&v_sense_led_timer);
				alt_alarm_start(&v_sense_led_timer, LED_ON_MILLISECONDS, v_sense_led_timer_isr_function, NULL);
				v_sense_led_timer_already_started = true;
			}
			int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);

			// SET ALL BITS UP FROM LEDG0 TO LEDG3
			for (int i = 9; i < 18; i++) {
				led_value = led_value |= (1<<i);
			}

			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);

		}

		clear_pace_led_events();
		clear_sense_led_events();
		//clear_heart_flags();
	}
	printf("Exiting Loop.\n");
	return 0;
}

void send_atrial_event(bool isThisEventPaced) {
	if (isThisEventPaced) {
		is_paced = true;
		char atrial_char = 'A';
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, atrial_char);
	} else {
		is_paced = false;
	}
	atrial_event = true;
	printf("Atrial Event Flagged!\n");
}

void send_ventricular_event(bool isThisEventPaced) {
	if (isThisEventPaced) {
		is_paced = true;
		char ventricular_char = 'V';
		IOWR_ALTERA_AVALON_UART_TXDATA(UART_BASE, ventricular_char);
	} else {
		is_paced = false;
	}
	ventricular_event = true;
	printf("Ventricular Event Flagged!\n");
}

void clear_heart_flags() {
	atrial_event = false;
	ventricular_event = false;
	is_paced = false;
}

void clear_pace_led_events() {
	if (!led_pace_atrial_event) {
		a_pace_led_timer_already_started = false;
		int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);

		// CLEAR ALL BITS UP FROM LEDG0 TO LEDG3
		for (int i = LEDG0; i < LEDG3 + 1; i++) {
			led_value = led_value &= ~(1<<i);
		}

		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);
	}

	if (!led_pace_ventricular_event) {
		v_pace_led_timer_already_started = false;
		int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);

		// CLEAR ALL BITS UP FROM LEDG0 TO LEDG3
		for (int i = LEDG4; i < LEDG7 + 1; i++) {
			led_value = led_value &= ~(1<<i);
		}

		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);
	}
}

void clear_sense_led_events() {
	if (!led_sense_atrial_event) {
		a_sense_led_timer_already_started = false;
		int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);

		// CLEAR ALL BITS UP FROM LEDG0 TO LEDG3
		for (int i = 0; i < 9; i++) {
			led_value = led_value &= ~(1<<i);
		}

		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);
	}

	if (!led_sense_ventricular_event) {
		v_sense_led_timer_already_started = false;
		int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);

		// CLEAR ALL BITS UP FROM LEDG0 TO LEDG3
		for (int i = 9; i < 18; i++) {
			led_value = led_value &= ~(1<<i);
		}

		IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);
	}
}

void C_Mode_Pacemaker(int a_timer_count, int v_timer_count) {
	// AEvents Logic
	//int a_count = (int)a_timer_count;
	if (a_timer_count >= AVI_VALUE) {
		//printf("bruh moment\n");
		//printf("TIMER HIT!\n");
		//send_ventricular_event(true);
		//a_timer_count = 0; // hey future me, this shit works, just implement the whole timing diagram shit
		// - past you 3:27am
	}
}

void SCCHARTS_Mode_Pacemaker() {

}