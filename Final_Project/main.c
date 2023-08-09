/************************************************************************************************************************************************
*
*	File Name: main.c
*
*	Author: Ahmed Hisham Fathy Hassabou
*
*	Description: 	Main application source file for the final project concerned with the mimicing of the traffic lights system with pedestrian
*								limitations taken in considerations
*
*	Features: 		1- Set the normal traffic light:
*									Use one of the timers to have the two car traffic lights working. The traffic light shall stay 
*									GREEN for 5 seconds, then YELLOW for 2 seconds, then turns RED. When one of the 
*									traffic lights is set to RED the other one has to go GREEN exactly after 1 second. The 
*									same sequence then is repeated again.
*									GREEN : 5 seconds YELLOW: 2 seconds Then RED.
*									Wait 1 second, then start the sequence on the other traffic.
*
*								2- Implement the pedestrian traffic light:
*									Use two push buttons and 4 LEDs for this system. There will be two pedestrian traffic, 
*									each with a push button and 2 LEDS: GREEN and RED. Whenever a pedestrian 
*									presses the button, the traffic light that is green shall be interrupted, and the pedestrian 
*									traffic light will be green for 2 seconds. Then it will be back to RED and the traffic light 
*									that was interrupted will resume from when it was paused.
*									Example: If the car traffic light was green for 2 seconds and interrupted it will then 
*									resume the remaining 3 seconds to finish the 5 seconds.
*				
*								3- UART
*									Send the current state of the whole system via UART whenever the system changes its 
*									state. The possible states, for example, are CARS NORTH SOUTH, CARS EAST 
*									WEST, PEDESTRIAN NORTH SOUTH, PEDESTRIAN EAST WEST.
*
*************************************************************************************************************************************************/

/************************************************************************************************************************************************

																												LIBRARIES INCLUDES

*************************************************************************************************************************************************/

#include <FreeRTOS.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <task.h>
#include "semphr.h"
#include "Port_Config.h"
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/debug.h"
#include "driverlib/uart.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/rom.h"
#include "driverlib/udma.h"
#include "Traffic_light.h"

/************************************************************************************************************************************************

																														INITIALIZATIONS

*************************************************************************************************************************************************/

// global variables 

int_32 next_state = GREEN_1; 					// Traffic light 1 state 
int_32 next_state_2 = RED_2; 					// Traffic light 2 state 
int_32 next_state_ps = GREEN_ps_1; 		// Pedstrain 1 state
int_32 elapsed_time_1 = 0; 						// Elapsed time Green in traffic light 1
int_32 elapsed_time_2 = 0; 						// Elapsed time Green in traffic light 2

/************************************************************************************************************************************************

																															MAIN FUNCTION

*************************************************************************************************************************************************/

int main()
{
  // Port inizialization 
  PORTA_init();
  PORTC_init();
  PORTE_init();
  PORTF_init();
  PORTD_init();
  // Timer inizialization 
  Timer0_init(1);
  // START
  Traffic_light_init();
  while(1)
  {
	SysCtlSleep(); //Sleep
  }
}
