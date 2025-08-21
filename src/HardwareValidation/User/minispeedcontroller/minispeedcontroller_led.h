#pragma once

#include <stdbool.h>

#define MINISPEEDCONTROLLER_LED_PIN         GPIO_Pin_2
#define MINISPEEDCONTROLLER_LED_PORT        GPIOA
#define MINISPEEDCONTROLLER_LED_PORT_RCC    RCC_PB2Periph_GPIOA
void minispeedcontroller_led_init (void);
void minispeedcontroller_led_set (_Bool state);