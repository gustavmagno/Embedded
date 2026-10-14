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

void POVDisplay(uint8_t oneByte);

int main(void) {
    DDRB = 0xff;
    
while(1) {
    POVDisplay(0b00001110);
    POVDisplay(0b00011000);
    POVDisplay(0b10111101);
    POVDisplay(0b01110110);
    POVDisplay(0b00111100);
    POVDisplay(0b00111100);
    POVDisplay(0b00111100);
    POVDisplay(0b01110110);
    POVDisplay(0b10111101);
    POVDisplay(0b00011000);
    POVDisplay(0b00001110);
    
    PORTB = 0;
    _delay_ms(100);
    }
    return 0;
}    

void POVDisplay(uint8_t oneByte) {
    PORTB = oneByte;
    _delay_ms(100);
}