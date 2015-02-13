
/*
 * File name            : xlcd_config.h
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example_7.3 External Character LCD
 *                      : Created on November 28, 2013, 12:50 PM
 *                      : External character LCD port configuration header file
 */

#if defined(__XC)
    #include <plib\xlcd.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
    #include <xlcd.h>
#endif

#ifndef XLCD_CONFIG_H
#define	XLCD_CONFIG_H

#define BIT8
/*                  DATA_PORT definitions                        */

 #define PORTB      			PORTD
 #define TRISB                  TRISD

/*                  CONTROL_PORT definitions                    */

 #define RW_PIN_   LATAbits.LATA1   		/* PORT for RW */
 #define TRIS_RW_  TRISAbits.TRISA1             /* TRIS for RW */

 #define RS_PIN_   LATAbits.LATA2   		/* PORT for RS */
 #define TRIS_RS_  TRISAbits.TRISA2             /* TRIS for RS */

 #define E_PIN_    LATAbits.LATA0  			/* PORT for D  */
 #define TRIS_E_   TRISAbits.TRISA0             /* TRIS for E  */
#endif