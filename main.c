#include <xc.h>
#include "sysconfig.h"
#include "interupt.h"
/*
 * 
 From a quick perusal of tiny bootloader, it appears Tiny BL uses the first 4 locations, and the last 200 in ROM.  So we need to tell the linker not to put any code in those areas.
 
It's really easy to set up in MPLAB X.  
1.  Open the "properties" window
2.  Select "XC8 linker"
3.  Option categories: Select "Memory Model".  
4.  Now on the "Memory Ranges" line, put "4-3f00".
 * 
 */

void main(void) {
    TRISB = 0b11110000; //RB0 a RB3 como salidas
    PORTB = 0xFF;
    
    init_timer();
    init_interrupt();
    
    ei(); // Habilita interrupciones generales
    
    while(1)
    {
        PORTBbits.RB3 = 0; // Encendemos RB3 y RB2
        for(long int i = 0; i < 40000; i++){}
        PORTBbits.RB3 = 1; // Apagamos led RB3 y RB2
        for(long int i = 0; i < 40000; i++){}
    }
    return;
}

void INT0_ISR_Callback(void)
{
    PORTBbits.RB2 = !PORTBbits.RB2; // Toggle RB1
}

void TMR0_ISR_Callback(void)
{
    PORTBbits.RB1 = !PORTBbits.RB1; // Toggle RB2
}