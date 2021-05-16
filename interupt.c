/*
 * File:   interrupts.c
 * Author: Vic
 *
 * Created on 16 de mayo de 2021, 12:21
 */



#include <xc.h> // include processor files - each processor file is guarded.  
#include "interupt.h"

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
        //tmr1_isr_handler(); // Procesamos interrupción en su manejador
        TMR1IF = 0; // Bajamos bandera de interrupción
    }
    
    if(INTCONbits.INT0IF==1)
    {
        INT0_ISR_Callback();
        INTCONbits.INT0IF = 0;
    }
}

// Si no está definida, se ejecuta este código
/*__attribute__((weak)) void INT0_ISR_Callback(void)
{
    // No hacer nada
}*/