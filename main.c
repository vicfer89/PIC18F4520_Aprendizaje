#include <xc.h>
#include "sysconfig.h"
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

void __interrupt(high_priority) ISR_HighPrio(void);
void __interrupt(low_priority) ISR_LowPrio(void);

void tmr1_isr_handler(void);

void init_interrupt(void);

void main(void) {
    TRISB = 0b11110000; //RB0 a RB3 como salidas
    PORTB = 0xFF;
    init_interrupt();
    while(1)
    {
        PORTBbits.RB2 = PORTBbits.RB3 = 0; // Encendemos RB3 y RB2
        for(long int i = 0; i < 40000; i++){}
        PORTBbits.RB2 = PORTBbits.RB3 = 1; // Apagamos led RB3 y RB2
        for(long int i = 0; i < 40000; i++){}
    }
    return;
}

void init_interrupt(void)
{
    IPEN = 1; // Habilitamos interrupciones de periferico interno
    TMR1IP = 1;
    TMR1IE = 1;
    // Habilitamos pin como entrada
    TRISBbits.TRISB0=1;
    
      
    INTCON2=0x00;		/* Set Interrupt on falling Edge*/
    INTCONbits.INT0IF=0;	/* Clear INT0IF flag*/
    INTCONbits.INT0IE=1;	/* Enable INT0 external interrupt*/
    INTCON2bits.INTEDG0 = 1; // Interrupt on rising edge
   
    ei(); // Habilita interrupciones generales

   
}

void __interrupt(high_priority) ISR_HighPrio(void)
{
    if(TMR1IE && TMR1IF)
    {
        tmr1_isr_handler(); // Procesamos interrupción en su manejador
        TMR1IF = 0; // Bajamos bandera de interrupción
    }
    
    if(INTCONbits.INT0IF==1)
    {
        PORTBbits.RB1 = !PORTBbits.RB1;
        INTCONbits.INT0IF = 0;
    }
}