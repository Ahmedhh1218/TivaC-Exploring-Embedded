 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the Keypad driver
 *
 *******************************************************************************/
#include "bitwise_operation.h" /* To use the macros like SET_BIT */
#include "keypad.h"
#include "gpio.h"




/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
uint8 KEYPAD_getPressedKey(void)
{
	uint8 col,row;
	uint8 keypad_port_value = 0;
	while(1)
	{
		for(col=0;col<KEYPAD_NUM_COLS;col++) /* loop for columns */
		{
			/* 
			 * Each time setup the direction for all keypad port as input pins,
			 * except this column will be output pin
			 */
			GPIO_setupPortDirection(KEYPAD_PORT_ID,PORT_INPUT);
			GPIO_setupPinDirection(KEYPAD_PORT_ID,KEYPAD_FIRST_COLUMN_PIN_ID+col,PIN_OUTPUT);
			
                        #if(KEYPAD_BUTTON_PRESSED == LOGIC_LOW)
			/* Clear the column output pin and set the rest pins value */
			keypad_port_value = ~(1<<(KEYPAD_FIRST_COLUMN_PIN_ID+col));
                         #else
			/* Set the column output pin and clear the rest pins value */
			keypad_port_value = (1<<(KEYPAD_FIRST_COLUMN_PIN_ID+col));
                        #endif
			GPIO_writePort(KEYPAD_PORT_ID,keypad_port_value);

			for(row=0;row<KEYPAD_NUM_ROWS;row++) /* loop for rows */
			{
				/* Check if the switch is pressed in this row */
				if(GPIO_readPin(KEYPAD_PORT_ID,row+KEYPAD_FIRST_ROW_PIN_ID) == KEYPAD_BUTTON_PRESSED)
				{
					(KEYPAD_NUM_COLS == 4)
                                         return KEYPAD_4x4_adjustKeyNumber((row*KEYPAD_NUM_COLS)+col+1);
					
				}
			}
		}
	}	
}


