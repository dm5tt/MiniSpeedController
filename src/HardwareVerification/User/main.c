#include "debug.h"

#include "minispeedcontroller_led.h"
#include "minispeedcontroller_usart.h"
#include "minispeedcontroller_motcon.h"

int main (void) {
    NVIC_PriorityGroupConfig (NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    minispeedcontroller_led_init();
    minispeedcontroller_motcon_init();
    minispeedcontroller_usart_init();

    printf ("SystemClk:%d\r\n", SystemCoreClock);
    printf ("ChipID:%08x\r\n", DBGMCU_GetCHIPID());

    while (1) {
        minispeedcontroller_led_set (true);
        minispeedcontroller_motcon_m1_step();
        minispeedcontroller_led_set (false);
    }
}
