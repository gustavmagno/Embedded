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
/*
 * 
 */

#define DELAYTIME   100
#define LED_PORT    PORTB
#define LED_PIN     PINB
#define LED_DDR     DDRB
        
int main (void) {
    LED_DDR = 0xff;
    uint8_t i;
    
    while (1) {
   
        while(i < 8) {
            PORTB = (1 << i);
            _delay_ms(DELAYTIME);
            i++;
        }
        while (i > 0) {
            PORTB = (1 << i);
            _delay_ms(DELAYTIME);
            i--;
        }
    }
}