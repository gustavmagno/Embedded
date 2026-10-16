/* 
 * File:   main.c
 * Author: admin
 *
 * Created on 14 de Outubro de 2026, 09:42
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include "pinDefines.h"
#include "USART.h"
/*
 * 
 */

#define DELAYTIME   80
#define LED_PORTB   PORTB
#define LED_PORTD   PORTD
#define LED_PINB    PINB
#define LED_PIND    PIND
#define LED_DDRB    DDRB
#define LED_DDRD    DDRD
        
int main (void) {
    char serialCharacter;
    
    LED_DDRB = 0xff;
    initUSART();
    printString("Hello World!\r\n");
    
    while (1) {
        serialCharacter = receiveByte();
        transmitByte(serialCharacter);
        LED_PORTB = serialCharacter;
    }
    return 0;
}