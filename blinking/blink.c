#include <LPC17xx.h>

void delay_ms(unsigned int ms)
{
    volatile unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 2000; j++);
}

int main(void) 
{
    SystemInit();
    LPC_PINCON->PINSEL4 = 0x00000000;
    LPC_GPIO2->FIODIR = 0xFFFFFFFF;

    while(1)
    {
        LPC_GPIO2->FIOSET = 0xFFFFFFFF;
        delay_ms(500);
        LPC_GPIO2->FIOCLR = 0xFFFFFFFF;
        delay_ms(500);
    }
}
