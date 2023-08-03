/************************************************************************************************************************************************
*
*	File Name: main.c
*
*	Author: Ahmed Hisham Fathy Hassabou
*
*	Description: 	Main application source file. This file lights up the white led when PB1 or/and PB2 of the TivaC launchpad is pressed
*								and turns the led off when the 2 buttons are released
*
*************************************************************************************************************************************************/

/************************************************************************************************************************************************

																												LIBRARIES INCLUDES

*************************************************************************************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>
#include "queue.h"
#include "semphr.h"
#include "Port_Config.h"
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


/************************************************************************************************************************************************

																														MAIN FUNCTION

*************************************************************************************************************************************************/

int main()
{
	// GPIO Initialization
	PortF_Config();	// Set up port F for requirements 

	while (1){
		// Check the status of switches
		if ((GPIO_PORTF_DATA_R & (PB1 | PB2)) != (PB1 | PB2)) {
			// At least one of the switches is pressed, turn on the white LED
			GPIO_PORTF_DATA_R |= RedLed | BlueLed | GreenLed;
		} 
		else {
			// Both switches are released, turn off the white LED
			GPIO_PORTF_DATA_R &= ~(RedLed | BlueLed | GreenLed);
		}
	}
	return 0;
}