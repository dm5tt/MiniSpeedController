#include "minispeedcontroller_led.h"

#include <ch32v00x.h>

#define MINISPEEDCONTROLLER_LED_PIN GPIO_Pin_2 /* PA2 */

void minispeedcontroller_led_init (void) {
    /* Disable OSC so we can use PA1 and PA2 as I/O */
    AFIO->PCFR1 &= ~(1U << 15);

    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = MINISPEEDCONTROLLER_LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_Init (GPIOA, &GPIO_InitStructure);
}

void minispeedcontroller_led_set (_Bool state) {
    GPIO_WriteBit (GPIOA, MINISPEEDCONTROLLER_LED_PIN, state ? Bit_SET : Bit_RESET);
    Delay_Ms (10);
    GPIO_WriteBit (GPIOA, MINISPEEDCONTROLLER_LED_PIN, state ? Bit_SET : Bit_SET);
    Delay_Ms (10);
}