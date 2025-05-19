#include <LPC17xx.h>
#define STCTRL      (*( ( volatile unsigned long *) 0xE000E010 ))
#define STRELOAD    (*( ( volatile unsigned long *) 0xE000E014 ))
#define STCURR      (*( ( volatile unsigned long *) 0xE000E018 ))  
#define SBIT_ENABLE     0
#define SBIT_TICKINT    1
#define SBIT_CLKSOURCE  2
#define RELOAD_VALUE  99999999
#define LED   2 //P2_2

int main (void) 
{
		SystemInit();
    STRELOAD = RELOAD_VALUE;
    STCTRL = (1<<SBIT_ENABLE) | (1<<SBIT_TICKINT) | (1<<SBIT_CLKSOURCE);
    LPC_GPIO2->FIODIR = (1<<LED);
		while(1)
    {
			
    }
}

void SysTick_Handler(void)
{
    LPC_GPIO2->FIOPIN ^= (1<<LED);
}
