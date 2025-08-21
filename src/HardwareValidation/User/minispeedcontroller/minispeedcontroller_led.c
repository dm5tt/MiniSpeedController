#include "minispeedcontroller_led.h"

#include <ch32v00X.h>

void minispeedcontroller_led_init (void) {
    /* Disable OSC so we can use PA1 and PA2 as I/O */
    AFIO->PCFR1 = AFIO->PCFR1 & 0xFFFF7FFF;

    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_PB2PeriphClockCmd (MINISPEEDCONTROLLER_LED_PORT_RCC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = MINISPEEDCONTROLLER_LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_Init (MINISPEEDCONTROLLER_LED_PORT, &GPIO_InitStructure);
}

void minispeedcontroller_led_set (_Bool state) {
    GPIO_WriteBit (MINISPEEDCONTROLLER_LED_PORT, MINISPEEDCONTROLLER_LED_PIN, state ? Bit_SET : Bit_RESET);
}