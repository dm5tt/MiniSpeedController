#include "minispeedcontroller_usart.h"

#include <ch32v00X.h>

void minispeedcontroller_usart_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};

    RCC_PB2PeriphClockCmd(MINISPEEDCONTROLLER_USART_PORT_RCC | MINISPEEDCONTROLLER_USART_RCC, ENABLE);

    /* USART1 TX-->D.5   RX-->D.6 */
    GPIO_InitStructure.GPIO_Pin = MINISPEEDCONTROLLER_USART_PIN_TX;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(MINISPEEDCONTROLLER_USART_PORT, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = MINISPEEDCONTROLLER_USART_PIN_RX;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(MINISPEEDCONTROLLER_USART_PORT, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART1, &USART_InitStructure);
    USART_Cmd(USART1, ENABLE);
}
