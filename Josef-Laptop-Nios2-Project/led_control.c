/*
 * led_control.c
 *
 *  Created on: 20/10/2023
 *      Author: Jobsa
 */

#include <system.h>
#include <altera_avalon_pio_regs.h> // Used for PIO functions
#include "led_control.h"
#include <stdio.h>
#include "defines.h"

/**
 * Clears the RED LEDs from LEDRX1 to LEDRX2
 */
void clear_red_leds_x_to_x(int LEDRX1, int LEDRX2) {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);
	// CLEAR ALL BITS UP FROM LEDR0 TO LEDR8
	for (int i = LEDRX1; i < LEDRX2 + 1; i++) {
		led_value = led_value &= ~(1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);
}

/**
 * Clears the GREEN LEDs from LEDGX1 to LEDGX2
 */
void clear_green_leds_x_to_x(int LEDGX1, int LEDGX2) {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);
	// CLEAR ALL BITS UP FROM LEDR0 TO LEDR8
	for (int i = LEDGX1; i < LEDGX2 + 1; i++) {
		led_value = led_value &= ~(1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);
}


/**
 * Sets the RED LEDs from LEDR0 to LEDR8 to HIGH
 */
void set_red_leds_x_to_x(int LEDRX1, int LEDRX2) {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);
	// SET ALL BITS UP FROM LEDR0 TO LEDR8
	for (int i = LEDRX1; i < LEDRX2 + 1; i++) {
		led_value = led_value |= (1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);
}

/**
 * Sets every second RED LEDs from LEDR0 to LEDR8 to HIGH
 */
void set_half_red_leds_x_to_x(int LEDRX1, int LEDRX2) {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);
	// SET EVERY SECOND BIT UP FROM LEDR0 TO LEDR8
	for (int i = LEDRX1; i < LEDRX2; i += 2) {
		led_value = led_value |= (1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);
}

/**
 * Sets the GREEN LEDs from LEDR0 to LEDR8 to HIGH
 */
void set_green_leds_x_to_x(int LEDGX1, int LEDGX2) {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);
	// SET ALL BITS UP FROM LEDR0 TO LEDR8
	for (int i = LEDGX1; i < LEDGX2 + 1; i++) {
		led_value = led_value |= (1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);
}

/**
 * Sets every second RED LEDs from LEDR0 to LEDR8 to HIGH
 */
void set_half_green_leds_x_to_x(int LEDGX1, int LEDGX2) {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);
	// SET EVERY SECOND BIT UP FROM LEDR0 TO LEDR8
	for (int i = LEDGX1; i < LEDGX2; i += 2) {
		led_value = led_value |= (1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);
}

