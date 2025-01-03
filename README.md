# STM32F746ZG-LED-timer-toggle
Project using STM32F746ZG microcontroller and PlatformIO. <br>
Framework: CMSIS <br>
Purpose: Create a timer-based LED toogle. <br>
## Acknoledgement
https://www.st.com/en/microcontrollers-microprocessors/stm32f746zg.html <br>

## Explanation (Step by step)
### Requirements
As it is going to be used a LED User and a timer, the Port where the LED is located must be configured (Reference Manual - page 163), in addition the timer needs to be enabled. <br>
### Timers
There are a total of 16 timers, but it was chosen the timer 10, just because... (More info about timers in Datasheet page 32)<br>
This timer is a general purpose timer with a 16 bit (from 1 to 65536) programmable prescaler. (Reference Manual - page 859) <br>
### LEDs
There are only 3 User LEDs in the microcontroller, and for convenience the LED 2 is chosen for this project <br>





