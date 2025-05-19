#include <LPC17xx.h>

int main(void)
{
    SystemInit();
    *((volatile unsigned long *)0xE000E014) = 99999999;
    *((volatile unsigned long *)0xE000E010) = (1 << 0) | (1 << 1) | (1 << 2);
    LPC_GPIO2->FIODIR |= (1 << 2);

    while (1)
    {
    }
}

void SysTick_Handler(void)
{
    LPC_GPIO2->FIOPIN ^= (1 << 2);
}