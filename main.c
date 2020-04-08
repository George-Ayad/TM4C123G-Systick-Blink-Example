#include "File.h"


int main(){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);

  SysTickPeriodSet(0x7A1200);
  SysTickEnable();

  uint32_t counter1 = 0;
  uint32_t counter2 = 0;
  uint32_t counter3 = 0;
  while(1){
    if(SysTickValueGet()<1)counter1++;
    counter2 = counter1/2;
    counter3 = counter1/3;

    if (counter1%2 == 0) GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);
    else GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);

    if (counter2%2 == 0) GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
    else GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);

    if (counter3%2 == 0) GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
    else GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);
  }

  return 0;
}
