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

void uart_interrupts_function(void* context, alt_u32 id)
{
	//char* temp = (char*)context;
	char temp;
	//(*temp) = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
	temp = IORD_ALTERA_AVALON_UART_RXDATA(UART_BASE);
	printf("UART read: %c\n", temp);

}


int main(void)
{
	printf("Initialised.\n");
	char testChar = '0';
	void* context_to_be_passed = (void*) &testChar; // Cast before passing context to isr

	// Initialise interrupt capability for uart_RX
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(UART_BASE, 0x0080);

	//
	alt_irq_register(UART_IRQ, NULL, uart_interrupts_function);

	//
	while(1);
	return 0;
}
