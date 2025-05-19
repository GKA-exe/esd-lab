#include <LPC17xx.h>

void EINT0_IRQHandler(void)
{
    LPC_SC->EXTINT = (1 << 0);
    LPC_GPIO2->FIOPIN ^= (1 << 2);
}

void EINT1_IRQHandler(void)
{
    LPC_SC->EXTINT = (1 << 1);
    LPC_GPIO2->FIOPIN ^= (1 << 3);
}

int main()
{
    SystemInit();
    LPC_SC->EXTINT = (1 << 0) | (1 << 1);
    LPC_PINCON->PINSEL4 = (1 << 20) | (1 << 22);
    LPC_SC->EXTMODE = (1 << 0) | (1 << 1);
    LPC_SC->EXTPOLAR = (1 << 0) | (1 << 0);
    LPC_GPIO2->FIODIR = (1 << 2) | (1 << 3);
    LPC_GPIO2->FIOPIN = 0x00;
    NVIC_EnableIRQ(EINT0_IRQn);
    NVIC_EnableIRQ(EINT1_IRQn);
    while (1)
    {
    }
}
