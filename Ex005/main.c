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

#define DELAYTIME   85
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
    
}