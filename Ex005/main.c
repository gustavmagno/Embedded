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
    clock_prescale_set(clock_div_8);
    
    uint8_t i;
    uint8_t repetitions;
    uint8_t whichLED;
    uint16_t randomNumber = 0x1234;
    
    LED_DDRB = 0xff;
    
    while (1) {
        
        for (i = 0; i < 8; i++) {
            LED_PORTB |= (1 << i);
            _delay_ms(DELAYTIME);
        }
        for (i = 0; i < 8; i++) {
            LED_PORTB &= ~(1 << i);
            _delay_ms(DELAYTIME);
        }
        _delay_ms(DELAYTIME);
        
        for (i = 7; i < 255; i--) {
            LED_PORTB |= (1 << i);
            _delay_ms(DELAYTIME);
        }
        for (i = 7; i < 255; i--) {
            LED_PORTB &= ~(1 << i);
            _delay_ms(DELAYTIME);
        }
        _delay_ms(DELAYTIME);
        
        for (repetitions = 0; repetitions < 75; repetitions++) {
            randomNumber = 2053 * randomNumber + 13849;
            
            whichLED = (randomNumber >> 8) & 0b00000111;
            LED_PORTB ^= (1 << whichLED);
            _delay_ms(DELAYTIME);
        }
        LED_PORTB = 0;
        _delay_ms(DELAYTIME);
    }
    return 0;
}