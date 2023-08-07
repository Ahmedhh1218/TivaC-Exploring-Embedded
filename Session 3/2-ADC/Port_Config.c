/************************************************************************************************************************************************
*
*	File Name: Port_Config.c
*
*	Author: Ahmed Hisham Fathy Hassabou
*
*	Description: source file for the ports configuration, in this file the following occurs:
*							1- Enable Clock for the Port we tend to use
*							2- Unlock PortF as a special case
*							3- Configure pins direction as input(0)/output(1)
*							4- Enable digital functionality by writting (1) to the pins required
*
***************************************************************************************************************************************************/

#include "Port_Config.h"


void PortF_Config(void) {
    // Enable the clock of PORTF
    SYSCTL_RCGCGPIO_R |= 0x20;
    
    // Unlock PORTF
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x1F;
    
    // Configure pins 0 and 4 as inputs, and pins 1, 2, and 3 as outputs
    GPIO_PORTF_DIR_R = 0x0E;
    
    // Enable digital functionality for all pins
    GPIO_PORTF_DEN_R |= 0x1F;
		
		// Attach pull up functionality to the 2 pushbuttons 
		GPIO_PORTF_PUR_R |= 0x11;
}