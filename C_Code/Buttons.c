/*
 * "Buttons IRQ" example.
 *
 */

#include <system.h> // to use the symbolic names
#include <altera_avalon_pio_regs.h> // to use PIO functions
#include <alt_types.h> // alt_u32 is a kind of alt_types
#include <sys/alt_irq.h> // to register interrupts
//#include <stdio.h>
#include <priv/alt_legacy_irq.h>
//float data[5]={0, 200.5, 300.5, 0, 500.5};
//int buttonValue = 0;
// first we write our interrupt function

 void button_interrupts_function(void* context, alt_u32 id)
{
	 //printf("Button interrupt happened \n");
	 volatile int* temp = (volatile int*) context; // need to cast the context first before using it
	 (*temp) = IORD_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE);
	 // clear the edge capture register
	 IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	 //printf("button: %i\n", *temp);
	 if(*temp==1 || *temp==2 || *temp==4){
	 	  	 IOWR(LEDS_BASE, 0, *temp);

	 }
}

//delay for 20 seconds

  void set_up_interrupt(unsigned int *val){
	  	  void *context_going_to_be_passed = (void*) val;
	  	  // clears the edge capture register
	  	  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(KEYS_BASE, 0);
	  	  // enable interrupts for left and right buttons i.e. key2 and key 0
	  	  IOWR_ALTERA_AVALON_PIO_IRQ_MASK(KEYS_BASE, 0xf);
	  	  // register the ISR
	  	  alt_irq_register(KEYS_IRQ,context_going_to_be_passed,
	  			  button_interrupts_function);
  }
  int main(void)
  {
	  unsigned int buttonValue = 0;
	  set_up_interrupt(&buttonValue);
	  while(1);
      return 0;
}

