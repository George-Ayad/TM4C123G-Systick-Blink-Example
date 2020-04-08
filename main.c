#include "File.h"


int main(){
  // Enable GPIO port f Peripheral
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

  // Set Systick period to 500 ms -> 500,000,000 nanoseconds * (1/16Mhz)
  SysTickPeriodSet(0x7A1200);
  SysTickEnable();

  // initialize 3 counters - 500ms, 1000ms, 1500ms
  uint32_t counter1 = 0;
  uint32_t counter2 = 0;
  uint32_t counter3 = 0;

  while(1){
    //increase counter1 value each 500ms
    if(SysTickValueGet()<1)counter1++;
    //calculate counter2(1000ms) and counter3(1500ms) from counter1(500ms)
    counter2 = counter1/2;
    counter3 = counter1/3;

    // switch LED state according to respective counter value
    // set high for even numbers and low for odd numbers
    if (counter1%2 == 0) GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
    else GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);

    if (counter2%2 == 0) GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);
    else GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);

    if (counter3%2 == 0) GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);
    else GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
  }

  return 0;
}
