/* 
 * File:   main.c
 * Author: Gustavo
 *
 * Created on 12 de Outubro de 2026, 18:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

void main(void) {
    ADCON1 = 0B00001111;
    TRISAbits.TRISA3 = 1; // input
    PORTAbits.RA3 = 0;
    TRISAbits.TRISA4 = 0; // output
    LATAbits.LATA4 = 0;
    
    while(1) {
        if (PORTAbits.RA3 == 1) {
            LATAbits.LATA4 = 1;
        } else {
            LATAbits.LATA4 = 0;
        }
    }
}

