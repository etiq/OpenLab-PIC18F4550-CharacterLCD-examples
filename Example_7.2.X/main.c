/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ v8
 * Author               : Etiq Technologies
 * Description          : Example_7.2 XLCD_2
 *                      : Created on November 29, 2013, 5:50 PM
 *                      : Example code configures PIC18f microcontroller ports to initialize external character LCD.
 *                      
 */

/*

8 bit data

Control PORT
------------
PORTA

Data PORT
---------
PORTD

Displaying a string on character LCD.

*/
#if defined(__XC)
    #include <plib\xlcd.h>
    #include <plib\usart.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <xlcd.h>
    #include <usart.h>
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#if defined(__XC) || defined(__18CXX)

#include <string.h>
#include "xlcd_config.h"
#include "config.h"
#include "delay.h"

#endif

char string[16] = "MICROCHIP MPLAB";                                       /* Variable declaration in char data type           */

void main( void )
    {
    OpenXLCD_( EIGHT_BIT & LINE_5X7 & BLINK_OFF & CURSOR_OFF);             /* configure external LCD                            */
    WriteCmdXLCD(DON&CURSOR_OFF&BLINK_OFF);
    while(1)
        {
        putsXLCD_((char*)string);                                           /* writing a string to external LCD                  */
        Delay_s(1);
        WriteCmdXLCD(0x01);
        Delay_s(1);
        WriteCmdXLCD(0x80);
        }                                                                  /* Infinite loop                                     */
    }