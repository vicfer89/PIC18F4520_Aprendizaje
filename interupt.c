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
    RCONbits.IPEN = 0; // Deshabilitadas prioridades en interrupciones
    
    // Habilitamos pin como entrada
    TRISBbits.TRISB0=1;
    
      
    INTCON2=0x00;		/* Set Interrupt on falling Edge*/
    INTCONbits.INT0IF=0;	/* Clear INT0IF flag*/
    INTCONbits.INT0IE=1;	/* Enable INT0 external interrupt*/
    INTCON2bits.INTEDG0 = 1; // Interrupt on rising edge
    
}

void init_timer(void)
{
    T0CONbits.T0CS = 0; // Reloj interno Fosc/4
    T0CONbits.PSA = 0; // Uso de preescaler
    T0CONbits.T08BIT = 0; // Modo 8 bits (0 - 255)
    T0CONbits.T0PS = 0b101; // Preescaler 256    
    TMR0L = 0x07;
    TMR0H = 0xD0;
    
    INTCONbits.TMR0IF = 0; // Limpiamos bandera de TMR0 interrupt
    INTCONbits.TMR0IE = 1; // Activación de interrupción de timer 0
    INTCON2bits.TMR0IP = 1; // TMR0 como high priority
    
    T0CONbits.TMR0ON = 1; // Activamos timer
}

void __interrupt(high_priority) ISR_HighPrio(void)
{
    if( INTCONbits.TMR0IF == 1)
    {
        TMR0_ISR_Callback(); // Procesamos interrupción en su manejador
        INTCONbits.TMR0IF = 0; // Bajamos bandera de interrupción
    }
    
    if( INTCONbits.INT0IF == 1 )
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