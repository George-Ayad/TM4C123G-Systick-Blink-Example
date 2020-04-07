#include "File.h"

void BLINK_RED(void)
{
  
  //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //
    // Check if the peripheral access is enabled.
    //
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }
    
     // Enable the GPIO pin for the LED (PF1)  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
    
    SysTickPeriodSet(0x7A1200);
    SysTickEnable();

    //
    // Loop forever.
    //
    while(1)
    {
        //
        // Turn on the LED.
        //
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
        while (SysTickValueGet()<0x7A11F1);

        //
        // Turn off the LED.
        //
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
        while (SysTickValueGet()<0x7A11F1);
    }
  
}