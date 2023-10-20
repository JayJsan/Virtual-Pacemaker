/*
 * lcd_control.c
 *
 *  Created on: 20/10/2023
 *      Author: Jobsa
 */

#include "lcd_control.h"
#include "defines.h" // Custom-defined defines
#include <system.h>
#include <stdio.h> // for NULL
#include <stdbool.h> // for BOOL
#include <altera_avalon_pio_regs.h> // Used for PIO functions

/**
 * Prints the current implementation mode and pulse mode to the LCD
 */
void print_modes_to_lcd(FILE* lcd, bool impl_mode, bool pulse_mode) {
	#define ESC 27
	#define CLEAR_LCD_STRING "[2J"
	// Clear previous LCD prints before setting it again.

	fprintf(lcd, "%c%s", ESC, CLEAR_LCD_STRING);
	if (impl_mode == C_MODE) {
		fprintf(lcd, "IMPL MODE: C\n");
	}
	else if (impl_mode == SCCHARTS_MODE) {
		fprintf(lcd, "IMPL MODE: SCCHARTS\n");
	}

	if (pulse_mode == UART_MODE) {
		fprintf(lcd, "PULSE MODE: UART\n");
	}
	else if (pulse_mode == BUTTON_MODE) {
		fprintf(lcd, "PULSE MODE: BUTTON\n");
	}
}
