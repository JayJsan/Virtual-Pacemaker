/*
 * switches.c
 *
 *  Created on: 18/10/2023
 *      Author: Jobsa
 */

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

/*
#include <system.h> // Used for referencing symbolic names
#include <altera_avalon_pio_regs.h> // Used for PIO functions
#include <altera_avalon_uart_regs.h> // Used for UART functions
#include <stdio.h>
#include <sys/alt_irq.h> // Used to register interrupts
#include <alt_types.h> // for
#include <string.h>
#include <time.h>

int main(void)
{
	printf("Initialised.\n");

	unsigned int uiSwitchValue = 0;

	printf("Entering Loop.\n");
	while(1) {
		uiSwitchValue = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);

		printf("Switch Value: %d\n", uiSwitchValue);

		if (uiSwitchValue & 1) {
			// SW0 is Active
			printf("SW0 On.\n");
		}

		if (uiSwitchValue & 2) {
			// SW1 is Active
			printf("SW1 On\n");
		}

		usleep(1000000);
	}
	printf("Exiting Loop.\n");
	return 0;
}

*/
