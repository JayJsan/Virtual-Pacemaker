/*
 * led_control.h
 *
 *  Created on: 20/10/2023
 *      Author: Jobsa
 */

#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

#include <system.h>
#include "defines.h"

void clear_red_leds_x_to_x(int LEDRX1, int LEDRX2);
void clear_green_leds_x_to_x(int LEDGX1, int LEDGX2);

void set_green_leds_x_to_x(int LEDGX1, int LEDGX2);
void set_red_leds_x_to_x(int LEDRX1, int LEDRX2);

void set_half_green_leds_x_to_x(int LEDGX1, int LEDGX2);
void set_half_red_leds_x_to_x(int LEDRX1, int LEDRX2);


#endif /* LED_CONTROL_H_ */
