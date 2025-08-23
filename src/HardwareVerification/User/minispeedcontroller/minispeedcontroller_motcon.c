#include "minispeedcontroller_motcon.h"

#include <ch32v00x.h>

#include <stdbool.h>
#include <stdint.h>


#define MINISPEEDCONTROLLER_MOTCON2_PIN_SLEEP GPIO_Pin_3    // PC3
#define MINISPEEDCONTROLLER_MOTCON2_PIN_IN2 GPIO_Pin_4      // PC4
#define MINISPEEDCONTROLLER_MOTCON2_PIN_PWM_IN1 GPIO_Pin_1  // PA1

void minispeedcontroller_motcon_init() {
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = MINISPEEDCONTROLLER_MOTCON2_PIN_SLEEP | MINISPEEDCONTROLLER_MOTCON2_PIN_IN2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_Init (GPIOC, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = MINISPEEDCONTROLLER_MOTCON2_PIN_PWM_IN1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_Init (GPIOA, &GPIO_InitStructure);

    GPIO_WriteBit (GPIOC, MINISPEEDCONTROLLER_MOTCON2_PIN_SLEEP, Bit_SET);

}

void minispeedcontroller_motcon_m1_step() {
    GPIO_WriteBit (GPIOC, MINISPEEDCONTROLLER_MOTCON2_PIN_IN2, Bit_RESET);

    GPIO_WriteBit (GPIOA, MINISPEEDCONTROLLER_MOTCON2_PIN_PWM_IN1, Bit_SET);
    Delay_Ms (50);
    GPIO_WriteBit (GPIOA, MINISPEEDCONTROLLER_MOTCON2_PIN_PWM_IN1, Bit_RESET);
    Delay_Ms (50);

    GPIO_WriteBit (GPIOC, MINISPEEDCONTROLLER_MOTCON2_PIN_IN2, Bit_SET);


    GPIO_WriteBit (GPIOA, MINISPEEDCONTROLLER_MOTCON2_PIN_PWM_IN1, Bit_SET);
    Delay_Ms (50);
    GPIO_WriteBit (GPIOA, MINISPEEDCONTROLLER_MOTCON2_PIN_PWM_IN1, Bit_RESET);
    Delay_Ms (50);

}