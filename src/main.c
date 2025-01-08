#include "stm32f7xx.h"

void Init()
{

    /* Setting Up GPIOx */

    // Enable GPIO Port Clock
    RCC->AHB1ENR |= 0b10; // Enable clock for GPIOB

    // Setting Port Pins as input or output
    // Note: According to Reference Manual - page 199 (Chapter 6.1) every GPIO port has 4 register to configure (Moder, Otyper, Ospeedr and pupdr)
    // Note: It also has registers to check/change the value of its pin (data registers) called ODR and IDR
        // Setting LED2 on PB7 Pin as output
    GPIOB->MODER &= ~(0x3 << (7 * 2)); // Clear PB7 mode bits
    GPIOB->MODER |= (0x01 << (7 * 2));  // Set PB7 as Output mode (01)
    GPIOB->OSPEEDR |= (0b10 << (7 * 2)); // Setting speed for the pin
    // Reference Manual - Page 208


    /* Configure General Purpose Timers */


    RCC->APB2ENR |= 0x20000; // TIM10 Peripheral Clock Enable
    // Reference Manual - Page 166 - 172. Enable Peripheral clock for UART, USART, CAN, TIMx

    TIM10->CR1 |= 0x1; // Timer: Enable Counter ENable (CEN) bit

    TIM10->DIER |= 0x1; // Enables the timer to trigger an interrupt when timer overflows

    //Reference Manual - Page 853

    TIM10->EGR |= 0b10; // Generates an update event, it means that allows to change values form registers (like PSC "prescaler") without waiting

    // The microcontroller is usually leaded by a main clock signal, which is called the System Clock Source and it can come from an external source (HSE) or internally (HSI)
    // The HSI runs at 16MHz (Reference Manual - page 137. Chapter 5.2.2) and is normally selected after a system reset by default (Reference Manual page 139. Chapter 5.2.6)



    /* Setting up timer
        ARR + 1 = time_base_required * ( TIMx_CLK / prescaler + 1 )
        Where:
        * time_base_required is the time desired (in this case is 1 second)
        * PSC and ARR are a 16 bit value
        * TIMx_CLK (in Hz) is the clock signal for the timer. (In this case it is the same as the System Clock source so its 16E+6 Hz)
        * PSC and ARR control the timer's behavior:
        * The ARR defines the maximum counter value will count to. When counter reaches the ARR value the counter resets to 0. If the counter is down counting, the counter resets to the ARR value
        * The prescaler divides the timer frequency, slowing down the timer clock.
        * So it means the timer will count at the ftimer value
        * . Its formula is:
        ftimer=fSYS_CLK/(PSC+1)
        => PSC=fSYS_CLK/(ftimer) - 1
    */

    TIM10->PSC |=  500; // Prescaler register
    TIM10->ARR = 31935; // Auto Reload register
    // Reference Manual - Page 859

}

int main()
{
    Init();

    while (1) //Infinite loop
    {
        //According to the graphic in page 818, the UIF flags changes its value to 1 when the counter finishes (but it remains its value) so it may be useful to toggle the value of the LED. The UIF is located in the TIMx_Status Register (TIM SR)
        if (TIM10->SR & (1 << 0)) //Checking bit 0 which is the UIF flag
            {
                TIM10->SR &= ~(1 << 0);
                GPIOB->ODR ^= (1 << 7); // Toggle the LED B7
            }


    }



}