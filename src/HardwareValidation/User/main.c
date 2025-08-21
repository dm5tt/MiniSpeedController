#include "debug.h"
#include "minispeedcontroller_led.h"
#include "minispeedcontroller_usart.h"

int main (void) {
    NVIC_PriorityGroupConfig (NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    minispeedcontroller_led_init();
    minispeedcontroller_usart_init();

    printf ("SystemClk:%d\r\n", SystemCoreClock);
    printf ("ChipID:%08x\r\n", DBGMCU_GetCHIPID());

    while (1) {
        minispeedcontroller_led_set (false);
        Delay_Ms (1000);
        minispeedcontroller_led_set (true);
        Delay_Ms (1000);
    }
}
