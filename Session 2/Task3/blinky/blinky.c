//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED Using SysTick Register
// Level Programming
// Copyright (c) 2012-2019 Ain Shams University; Faculty of Engineering (ASUENG)
// Authored by Sherif Hammad
// Software License Agreement
// 
// ASUENG is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// ASUENG and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. ASUENG SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
//
//*****************************************************************************

#include "tm4c123gh6pm.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************

int
main(void)
{

  __asm("CPSID  I");

    SYSCTL_RCGCGPIO_R = 0x20U;
    GPIO_PORTF_DIR_R = 0x0EU;
    GPIO_PORTF_DEN_R = 0x0EU;
/* Configure SysTick */
    NVIC_ST_RELOAD_R = 0xFFFFFF;   /* reload reg. with max value */

    // Enable interrupts to the processor.
    //
    __asm("CPSIE  I");
    //
    // Start SysTick Timer.
    //
    NVIC_ST_CTRL_R = 7;         /* enable it, enable interrupt, use system clock */
    //
    // Loop forever.
    //
    while(1)
    {
    //
    // Processor enters Sleep Mode to save Power instead of Looping
    // Once Interrupt happens, Processor goes directly into Run mode
    //      
      __asm("      wfi\n");
    }
}
void
SysTickIntHandler(void)
{
    // Toggling by XOR with ONE
       
  GPIO_PORTF_DATA_R ^=0x04;

}

