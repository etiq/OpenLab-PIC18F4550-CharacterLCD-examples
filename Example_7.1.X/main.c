/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ v8
 * Author               : Etiq Technologies
 * Description          : Example_4.1 XLCD
 *                      : Created on January 7, 2014, 05:31 PM
 *                      : Example code configures PIC18f4550 microcontroller ports to initialize and display characters on external character LCD continuously.
 */

/*

8 bit data

Control PORT
------------
PORTA

Data PORT
---------
PORTD

A variable is initialized with a character 'A', then continuously displayed on LCD by incrementing
its ASCII value upto 'Z'. Again repeating display starting from 'A'. 

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

void main( void )
    {
    char data;                                                            /*Initialization of variables                         */
    unsigned char i= 0;
        OpenXLCD_( EIGHT_BIT & LINE_5X7 & BLINK_OFF & CURSOR_OFF);              /*configure external LCD                              */
		WriteCmdXLCD(DON&CURSOR_OFF&BLINK_OFF);     

    while(1)                                                                    /*Infinite loop                                       */
            {
            data = 'A';
            i= 0;
            while(i!=26)                                                        /*Displaying 5 times the character in variable data   */
                {
            WriteCmdXLCD(0x84);
            WriteDataXLCD(data++);                                              /*writing data to external LCD                        */
                i++;
			Delay_s(1);
			WriteCmdXLCD(0x01);                 	
                }
            }
    }