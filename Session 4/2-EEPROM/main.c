/************************************************************************************************************************************************
*
*	File Name: main.c
*
*	Author: Ahmed Hisham Fathy Hassabou
*
*	Description: 	Main application source file. This file uses the DMA.
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
#include "driverlib/rom.h"
#include "driverlib/udma.h"
#include "driverlib/flash.h"
#include "driverlib/eeprom.h"


/************************************************************************************************************************************************

																														MAIN FUNCTION

*************************************************************************************************************************************************/

int main()
{
	uint32_t pui32Data[2];
	uint32_t pui32Read[2];
	
	pui32Data[0]=0x00000001;
	pui32Data[1]=0x00000002;
	
	SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);
	SysCtlDelay(2000000);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
	
	/*
	
		EEPROMInit() - if not called may lead to dataloss
		it checks for errors in EEPROM due to power failure during previous write operation
	
	*/
	
	EEPROMInit();
	
	/*
	
		EEPROMMassErase - Errases the EEPROM leaving it to the device factory default conditions
		EEPROM will contain the value 0xFFFFFFFF
	
	*/
	
	EEPROMMassErase();
	
	/*
	
		EEPROMRead - is used to read the EEPROM
	
	*/
	
	EEPROMRead(pui32Read, 0x0, sizeof(pui32Read));
	
	/*
	
		EEPROMProgram - Function used to write data into EEPROM
	
	*/
	
	EEPROMProgram(pui32Data, 0x0, sizeof(pui32Data));
	EEPROMRead(pui32Read, 0x0, sizeof(pui32Read));
	
	while(1){
	}
}