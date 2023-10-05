#include <system.h>
#include <altera_avalon_pio_regs.h>
#include <stdio.h>
#include "sccharts.h"

int main() {
	// create the struct
	TickData data;

	// initialise
	reset(&data);

	while (1) {
		// fetch button inputs
		// A is key 2,	B is key1, R is key0
		// keys are active low


		// do a tick
		tick(&data);

		// output O to red LED
	}

	return 0;
}
