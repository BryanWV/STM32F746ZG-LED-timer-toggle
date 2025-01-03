#include "stm32f7xx.h"

void Init()
{
    // Enable GPIOx Port Clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //TODO: Change to hex number for B port

    /* Configure General Purpose Timers */

    //Enable Counter ENable bit CEN

    RCC->APB2ENR |= 0x20000; // Reference Manual - Page 166 - 172. Enable Peripheral clock for UART, USART, CAN, TIMx
    TIM-> TIM10_CR1 |= 0x1;

    //
    TIM10_DIER |= 0b10; // 10

    TIM10_EGR |= 0b10; // capture mode enabled

    TIM10_CCMR1 |= 0b0110000;  //Reference manual - Page 856 enable toggle mode
    // OC1REF toggles when CNT = CCR1

    // The STM32F7x6 has a maximum speed of 216MHz
    TIM10_PSC |=  ; // Timer prescaler. Formula=216MHz/(PSC[15:0]+1)

}

int main()
{
    Init();

    // Add while loop while(1) {}


}