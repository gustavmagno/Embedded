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
#define LED_PORTB   PORTB
#define LED_PORTD   PORTD
#define LED_PINB    PINB
#define LED_PIND    PIND
#define LED_DDRB    DDRB
#define LED_DDRD    DDRD
        
int main (void) {
    LED_DDRD = 0b11110000;
    LED_DDRB = 0xff;
    uint8_t i;
    
    while (1) {
        
            if (LED_PIND & (1 << PIND0)) {
                LED_PORTB = 0b11000011;
                _delay_ms(DELAYTIME);
                LED_PORTB &= ~(1 << PORTB1);
                _delay_ms(DELAYTIME);
            } else if (LED_PIND & (1 << PIND1)) {
                LED_PORTB = 0b11000011;
                LED_PORTB |= (5 << PORTB1);
                 _delay_ms(DELAYTIME);
                LED_PORTB &= ~(5 << PORTB1);
                _delay_ms(DELAYTIME);
            } else {

            while(i < 7) {
                LED_PORTB = (1 << i);
                _delay_ms(DELAYTIME);
                i++;
            }
            while (i > 0) {
                LED_PORTB = (1 << i);
                _delay_ms(DELAYTIME);
                i--; 
            }
            }   
    }
}