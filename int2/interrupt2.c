#include <LPC17xx.h>
#define PINSEL_EINT0    20
#define PINSEL_EINT1    22
#define LED1            2  
#define SBIT_EINT0      0
#define SBIT_EINT1      1  
#define SBIT_EXTMODE0   0
#define SBIT_EXTMODE1   1
#define SBIT_EXTPOLAR0  0
#define SBIT_EXTPOLAR1  1
void EINT0_IRQHandler(void)
{
    LPC_SC->EXTINT = (1<<SBIT_EINT0);
    LPC_GPIO2->FIOPIN ^= (1<< LED1);
}

int main()
{
SystemInit();
    LPC_SC->EXTINT      = (1<<SBIT_EINT0)    | (1<<SBIT_EINT1);
    LPC_PINCON->PINSEL4 = (1<<PINSEL_EINT0)  | (1<<PINSEL_EINT1);
    LPC_SC->EXTMODE     = (1<<SBIT_EXTMODE0) | (1<<SBIT_EXTMODE1);
    LPC_SC->EXTPOLAR    = (1<<SBIT_EXTPOLAR0)| (1<<SBIT_EXTPOLAR0);
    LPC_GPIO2->FIODIR   = (1<<LED1);
    LPC_GPIO2->FIOPIN   =  0x00;
NVIC_EnableIRQ(EINT0_IRQn);
NVIC_EnableIRQ(EINT1_IRQn);  
while(1)
    {
      // Do nothing
    }      
}