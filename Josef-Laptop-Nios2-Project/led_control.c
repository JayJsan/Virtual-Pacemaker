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
 * Clears the RED LEDs from LEDR0 to LEDR8
 */
void clear_red_leds_0_to_8() {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);
	// CLEAR ALL BITS UP FROM LEDR0 TO LEDR8
	for (int i = 0; i < 9; i++) {
		led_value = led_value &= ~(1<<i);
	}

	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);
}

/**
 *  Clears the RED LEDs from LEDR9 to LEDR17
 */
void clear_red_leds_9_to_17() {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);
	// CLEAR ALL BITS UP FROM LEDR9 TO LEDR17
	for (int i = 9; i < 18; i++) {
		led_value = led_value &= ~(1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, led_value);
}

/**
 * Clears the GREEN LEDs from LEDG0 to LEDG3
 */
void clear_green_leds_0_to_3() {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);
	// CLEAR ALL BITS UP FROM LEDG0 TO LEDG3
	for (int i = LEDG0; i < LEDG3 + 1; i++) {
		led_value = led_value &= ~(1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);
}

/**
 * Clears the GREEN LEDs from LEDG0 to LEDG3
 */
void clear_green_leds_4_to_7() {
	int led_value = IORD_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE);
	// CLEAR ALL BITS UP FROM LEDG0 TO LEDG3
	for (int i = LEDG4; i < LEDG7 + 1; i++) {
		led_value = led_value &= ~(1<<i);
	}
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, led_value);
}

/**
 * Sets the GREEN LEDs from LEDG0 to LEDG3 to HIGH
 */
void set_green_leds_0_to_3() {

}
