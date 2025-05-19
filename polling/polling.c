#include <LPC17xx.h>

#define SwitchPinNumber 10
#define LedPinNumber    2

int main() 
{
    uint32_t switchStatus;

    SystemInit();

    LPC_PINCON->PINSEL4 &= ~((3 << (2 * SwitchPinNumber)) | (3 << (2 * LedPinNumber)));

    LPC_GPIO2->FIODIR |= (1 << LedPinNumber);
    LPC_GPIO2->FIODIR &= ~(1 << SwitchPinNumber);

    while (1)
    {
        switchStatus = (LPC_GPIO2->FIOPIN >> SwitchPinNumber) & 0x01;

        if (switchStatus == 0)
        {
            LPC_GPIO2->FIOSET = (1 << LedPinNumber);
        }
        else
        {
            LPC_GPIO2->FIOCLR = (1 << LedPinNumber);
        }
    }
}
