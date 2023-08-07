# Tiva C Launchpad Microcontrollers Training

Welcome to the Tiva C Launchpad Microcontrollers Training repository by Ahmed Hassabou, during the internship with Garraio Company. This repository is designed to provide you with a comprehensive learning experience in the world of microcontrollers, focusing on the Tiva C Launchpad development board. Whether you're a beginner or an experienced developer, this repository has something for everyone who wants to dive into embedded systems.

## What's Inside

- **ARM Architecture Fundamentals:** Lay a strong foundation by understanding the basics of the ARM architecture and its significance in the embedded world.

- **Tiva C Launchpad Introduction:** Get started with the Tiva C Launchpad development board. Learn about its components, how to set up your development environment, and begin writing your first program.

- **Peripherals Exploration:** Explore the vast array of peripherals that Tiva C offers. From GPIO control to UART communication, SPI interfacing to ADC conversion, you'll learn how to make the most of each peripheral.

- **Hands-On Projects:** Put your knowledge into action with a series of hands-on projects. Build LED blinking patterns, create sensor interfaces, establish communication between devices, and even delve into motor control applications.


## Projects Description
### Session 1
1. Write a C code project to turn ON the white LED when switch 1 or switch 2 or both
of them are pressed, and the white LED should be turned OFF if all of the switches
are released.
### Session 2
1. Write a C code project to toggle the white LED each 500 ms using the SysTick timer,
one time using the registers, and another time using TivaWare library.
2. Write a C code project to toggle the white LED each 1000 ms using GPTM one time
using the registers, and another time using TivaWare library.
3. Write a C code project to toggle the white LED each 2500 ms using SysTick timer
using SysTick Interrupt and TivaWare library.
4. Write a C code project to develop the project mentioned in “Keypad_with_GPIO” lab
document, but you will make it work only using Interrupts. (You will need to buy a simple 4*4 keypad)
### Session 3
1. UART, make this project work on your board using UART 0:
https://microcontrollerslab.com/uart-communication-tm4c123-tiva-c-launchpad/
2. ADC, make this project work on your board, send the voltage value to your PC using
UART 0: https://microcontrollerslab.com/adc-tm4c123g-tiva-c-launchpad-measureanalog-voltage-signal/
3. I2C, make this project work on your Tiva C board and another Arduino board:
https://microcontrollerslab.com/i2c-communication-tm4c123g-tiva-c-launchpad/
### Session 4
1. DMA, https://www.youtube.com/watch?v=_mH-_joVpKA, implement the project 
mentioned in this video, make your own modifications.
2. EEPROM, https://www.youtube.com/watch?v=ylN0GT4zJW8, implement the project 
mentioned in this video, make your own modifications.
### Final Project
#### Objectives
The goal of this project is to design a traffic light control system. The system simply 
contains two traffic lights. One allows cars to move from north to south, and the other 
one allows cars to move from east to west. Beside each traffic there is also a pedestrian 
traffic light. The pedestrian has to press on a button to have his light green to cross the 
street safely.
#### Features
1. Set the normal traffic light
   Use one of the timers to have the two car traffic lights working. The traffic light shall stay GREEN for 5 seconds,
   then YELLOW for 2 seconds, then turns RED. When one of the traffic lights is set to RED the other one has to go GREEN exactly after 1 second.
   The same sequence then is repeated again.
   GREEN : 5 seconds YELLOW: 2 seconds Then RED.
   Wait 1 second, then start the sequence on the other traffic
2. Implement the pedestrian traffic light
    Use two push buttons and 4 LEDs for this system. There will be two pedestrian traffic, each with a push button and 2 LEDS: GREEN and RED.
    Whenever a pedestrian presses the button, the traffic light that is green shall be interrupted, and the pedestrian traffic light will be green for 2 seconds.
    Then it will be back to RED and the traffic light that was interrupted will resume from when it was paused.
    Example: If the car traffic light was green for 2 seconds and interrupted it will then resume the remaining 3 seconds to finish the 5 seconds.
3. UART
   Send the current state of the whole system via UART whenever the system changes its state.
   The possible states, for example, are CARS NORTH SOUTH, CARS EAST WEST, PEDESTRIAN NORTH SOUTH, PEDESTRIAN EAST WEST
#### Special Cases Handling 
1. Handle the case if two pedestrians pushed the button together in two different traffics.
2. Handle the case if the same button was being pressed more than one time during the same period of pedestrian crossing.
   (Period of pedestrian crossing is from when the button is pressed for the first time till the pedestrian traffic gets back to RED again.)
3. Handle the case to delay the request of the pedestrian to cross if the button was pressed after 1 second from the end of the Period of pedestrian crossing

## Getting Started

1. Clone this repository to your local machine using the following command:
git clone https://github.com/Ahmedhh1218/TivaC-Exploring-Embedded.git

2. Navigate to the relevant project folders to access project-specific instructions and source code.

3. Follow along with the step-by-step guides to complete each project. Feel free to experiment and modify the code to deepen your understanding.

## Contributing

We welcome contributions from the community! If you find any issues, have suggestions for improvements, or want to add your own projects, feel free to create pull requests or open issues. Let's learn and collaborate together.
