# FPGA - Pacemaker

## If nothing is happening after programming, press KEY3 to re-initialise the code.

> This code written in C is for the FPGA ALTERA DE2-115.

> This project is made to simulate a virtual pacemaker. It uses UART to communicate to the computer with the CS303-Heart.exe program. Otherwise, you can simulate heart events by putting it in buttons mode.

### Pacemaker in Action on the FPGA Altera DE2-115

<video src="pacemaker_vid.mp4" controls title="Title"></video>

> The green lights indicate pacing of the heart where the left half of the LEDs indicate the atrium and the right half to be the ventricle.

> The red lights indicate sensing of the heart pulses where the left half of the LEDs indicate the atrium and the right half to be the ventricle.

## Switches

> ### **SW0**
>
> #### - 0 = UART MODE
>
> #### - 1 = BUTTONS MODE

> ### **SW1**
>
> #### - 0 = C IMPLEMENTATION MODE
>
> #### - 1 = SCCHARTS IMPLEMENTATION MODE

## Buttons

> ### **KEY0**
>
> #### - PRESS = PACE ATIRAL

> ### **KEY1**
>
> #### - PRESS = PACE VENTRICLE

> ### **KEY3**
>
> #### - PRESS = RESTART MAIN LOOP

## LEDS

> ### **LEDG0 -> LEDG3**
>
> #### - **VENTRICLE** PACED
>
> #### - ALL LIT - C MODE
>
> #### - HALF LIT - SCCHARTS MODE

> ### **LEDG4 -> LEDG7**
>
> #### - **ATRIUM** PACED
>
> #### - ALL LIT - C MODE
>
> #### - HALF LIT - SCCHARTS MODE

> ### **LEDR0 -> LEDR8**
>
> #### - **VENTRICLE** SENSED (FROM UART)
>
> #### - ALL LIT - C MODE
>
> #### - HALF LIT - SCCHARTS MODE

> ### **LEDR9 -> LEDR17**
>
> #### - **ATRIUM** SENSED (FROM UART)
>
> #### - ALL LIT - C MODE
>
> #### - HALF LIT - SCCHARTS MODE
