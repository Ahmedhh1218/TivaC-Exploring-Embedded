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

/************************************************************************************************************************************************

																														Initialization

*************************************************************************************************************************************************/

// allocate the channel control table, which must be of 1024-byte aligned
uint8_t DMA_Control_Table[1024];

// source and destination buffers for DMA transfer
uint8_t Source_Buffer[256] = "Hassabou was Here";
uint8_t Destination_Buffer[256];

/************************************************************************************************************************************************

																														MAIN FUNCTION

*************************************************************************************************************************************************/

int main()
{
	// Enable the UDMA peripheral
	SysCtlPeripheralEnable(SYSCTL_PERIPH_UDMA);
	
	// Check if UDMA module ready
	while(!(SysCtlPeripheralReady(SYSCTL_PERIPH_UDMA))){
	};
		
	// Enable the uDMA controller
	uDMAEnable();
	
	// set the base for the channel control table
	uDMAControlBaseSet(&DMA_Control_Table[0]);
	
	// The attributes are cleared here, if they were set elsewhere
	uDMAChannelAttributeDisable(UDMA_CHANNEL_SW, UDMA_ATTR_ALL);
	
	// 8-bit data size, with bytewise buffer copy & bus arbitration size of 8 
	uDMAChannelControlSet(UDMA_CHANNEL_SW | UDMA_PRI_SELECT , 
												UDMA_SIZE_8 		| UDMA_SRC_INC_8 |
												UDMA_DST_INC_8 	| UDMA_ARB_8 );
	
	// DMA transfer using AUTO mode
	uDMAChannelTransferSet(	UDMA_CHANNEL_SW | UDMA_PRI_SELECT,
													UDMA_MODE_AUTO, Source_Buffer, Destination_Buffer, sizeof(Destination_Buffer));
	
	// The channel is enabled & for software transfer, a request must also be made
	uDMAChannelEnable(UDMA_CHANNEL_SW);
	uDMAChannelRequest(UDMA_CHANNEL_SW);
	
	while(1)
	{
		// check if source buffer equal to destination
	}
	
	return 0;
	
}