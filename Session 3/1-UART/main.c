/************************************************************************************************************************************************
*
*	File Name: main.c
*
*	Author: Ahmed Hisham Fathy Hassabou
*
*	Description: 	Main application source file. This file uses UART to communicate with the PC. the TivaC receives a character from the 
*			PC which is an indication to which LED Color to Turn On
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


int main(void) {
    // Set the system clock to the desired frequency
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Enable GPIO and UART peripherals
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    // Configure UART pins (PA0 - UART0 Rx, PA1 - UART0 Tx)
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Configure GPIO for LEDs
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);

    // Configure UART
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    while (1) {
        char receivedChar = UARTCharGet(UART0_BASE);

        switch (receivedChar) {
            case 'R':
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1); // Turn on RED LED
                break;
            case 'G':
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2); // Turn on GREEN LED
                break;
            case 'B':
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3); // Turn on BLUE LED
                break;
            case 'W':
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0x00); // Turn off all LEDs
                break;
        }
    }
}
