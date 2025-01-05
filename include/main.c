#include "stm32f7xx.h"

void Init()
{

    /* Setting Up GPIOx */

    // Enable GPIO Port Clock
    RCC->AHB1ENR |= 0b10; // Enable clock for GPIOB

    // Setting Port Pins as input or output
        // Setting LED2 on PB7 Pin as output
    GPIOB->MODER &= ~(0x3 << (7 * 2)); // Clear PB7 mode bits
    GPIOB->MODER |= (0x01 << (7 * 2));  // Set PB7 as Output mode (01)
    // Reference Manual - Page 208


    /* Configure General Purpose Timers */


    RCC->APB2ENR |= 0x20000; // TIM10 Peripheral Clock Enable
    // Reference Manual - Page 166 - 172. Enable Peripheral clock for UART, USART, CAN, TIMx

    TIM10->CR1 |= 0x1; // Timer: Enable Counter ENable (CEN) bit

    TIM10->DIER |= 0x1; // Enables the timer to trigger an interrupt when timer overflows

    //Reference Manual - Page 853

    TIM10->EGR |= 0b10; // Generates an update event, it means that allows to change values form registers (like PSC "prescaler") without waiting

    // The microcontroller is usually leaded by a main clock signal, which is called the System Clock Source and it can come from an external source (HSE) or internally (HSI)
    // The HSI runs at 16MHz (Reference Manual - page 137. Chapter 5.2.2) and is normally selected after a system reset (Reference Manual page 139. Chapter 5.2.6)


    TIM10->PSC |=  ; // Timer prescaler. Prescaler Value= 16MHz/(PSC[15:0]+1)
    // Reference Manual - Page 859

}

int main()
{
    Init();

    // Add while loop while(1) {}


}