/* 
 * File name            : xlcd_config.h
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ v8
 * Author               : Etiq Technologies
 * Description          : Example_7.1 XLCD
 *                      : Created on November 30, 2013, 12:23 PM
 *                      : xlcd configuration functions header.
 */

#ifndef XLCD_CONFIG_H
#define	XLCD_CONFIG_H

#if defined(__18CXX) || defined(__XC)
#if defined(__18CXX)
#include <xlcd.h>
#elif defined(__XC)
#include <plib\xlcd.h>
#endif

/*Definition for 8bit data input*/
#define BIT8

/* DATA_PORT defines the port to which the LCD data lines are connected */
 #define PORTB                          PORTD
 #define TRISB 				TRISD

/* CTRL_PORT defines the port where the control lines are connected.*/
 #define RW_PIN_   LATAbits.LATA1                                            /* PORT for RW                                      */
 #define TRIS_RW_  TRISAbits.TRISA1                                          /* TRIS for RW                                      */
 #define RS_PIN_   LATAbits.LATA2                                            /* PORT for RS                                      */
 #define TRIS_RS_  TRISAbits.TRISA2                                          /* TRIS for RS                                      */
 #define E_PIN_    LATAbits.LATA0                                            /* PORT for D                                       */
 #define TRIS_E_   TRISAbits.TRISA0

/*___________________________ Command Write Function_________________________________________*/

void WriteCmdXLCD(unsigned char cmd);

/*
 * Include          :       xlcd_config.h
 * Description      :       Function to write commands to external character lcd
 * Arguments        :       Byte
 * Returns          :       None
 */

/*___________________________ Data Write Function_____________________________________________*/

void WriteDataXLCD(char data);

/*
 * Include          :       xlcd_config.h
 * Description      :       Function to write data to external character lcd
 * Arguments        :       Byte
 * Returns          :       None
 */

/*___________________________ XLCD initialization Function___________________________________*/

void OpenXLCD_(unsigned char lcdtype);

/*
 * Include          :       xlcd_config.h
 * Description      :       Function initializes XLCD with required parameters.
 * Arguments        :       Byte
 * Returns          :       None
 */

/*___________________________ XLCD initialization Function___________________________________*/

void putsXLCD_(char *buffer);

/*
 * Include          :       xlcd_config.h
 * Description      :       Function to display a string on XLCD.
 * Arguments        :       Byte
 * Returns          :       None
 */
#endif

#endif	/* XLCD_CONFIG_H */

