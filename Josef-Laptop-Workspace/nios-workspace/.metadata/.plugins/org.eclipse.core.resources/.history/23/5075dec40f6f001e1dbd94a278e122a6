/*
 * buttons_test.c
 *
 *  Created on: 17/10/2023
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

/*
#include <system.h> // Used for referencing symbolic names
#include <altera_avalon_pio_regs.h> // Used to PIO functions
#include <stdio.h>
#include <sys/alt_irq.h> // Used to register interrupts
#include <alt_types.h> // for

void buttons_interrupts_function(void* context, alt_u32 id)
{
	int* temp = (int*) context; // Cast the context before using it
	(*temp) = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);

	// clear the edge capture register
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	printf("button pressed: %i\n", *temp);

}


int main(void)
{
	printf("INITIALISING CODE");
	int buttonValue = 1;
	void* context_to_be_passed = (void*) &buttonValue; // Cast before passing context to isr

	// Clear edge capture register
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);

	// Enable interrupts for all buttons
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0x7);

	// Register the isr
	alt_irq_register(KEYS_IRQ, context_to_be_passed, buttons_interrupts_function);

	while(1); // keep this program alive

	return 0;
}
*/
