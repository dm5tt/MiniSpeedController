![docs](pictures/minispeedcontroller_pcb.jpg)

# RISC-V DC-Motor Speed Controller

This project implements a compact DC motor speed controller using a RISC-V microcontroller. It is designed for precision control via PWM feedback and communicates through a serial interface. Additional  sensors can be attached using I2C.

Beware that the entire PCB isn't a masterpiece as this is just for technology evaluation. 

## Why this thing?

Mostly for playing around with very cheap RISC-V microcontrollers and an execise for C/Rust with very limited resources.


## Features

- **Microcontroller**: WCH CH32V003  
  - 48 MHz RISC-V core  
  - 16 KB Flash, 2 KB SRAM  

- **Motor Driver**: TI DRV8837GSGR  
  - Low-voltage brushed DC motor driver  
  - Up to 1.8 A continuous current  

- **Power Management**:  
  - **AP62300TWU** (Diodes Inc.): 3 A Step-Down Buck Converter  
  - **AMS1117-3.3** (Advanced Monolithic): LDO for regulated 3.3 V output from 7 V supply  

- **Feedback**:  
  - Motor speed measured via PWM from optical light barriers  

- **Control Interface**:  
  - Commands received over USART
  - Sensors can be attached using I2C  


## Pin Configuration

| Pin | Meaning          |
|-----|------------------|
| PC0 | pwm_speed_input1 |
| PC1 | I2C, SDA         |
| PC2 | I2C, SCL         |
| PC3 | motcon2_sleep    |
| PC4 | motcon2_in       |
| PC5 | motcon1_sleep    |
| PC6 | motcon1_in2      |
| PC7 | X                |
| PD0 | X                |
| PD1 | SWDIO            |
| PD2 | motcon1_pwm_in1  |
| PD3 | pwm_speed_input2 |
| PD4 | X                |
| PD5 | usart_tx         |
| PD6 | usart_rx         |
| PD7 | nRST             |
| PA1 | motcon2_pwm_in1  |
| PA2 | STATUS_LED       |


## Warning

Hardware verification not yet finished.

List:
 - ✅ DCDC
 - ✅ LDO
 - ☐ CH32V003
 - ☐ DRV8837GSGR
 


# License

GPLv3