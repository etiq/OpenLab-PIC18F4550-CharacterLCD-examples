/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example_7.3 External Character LCD
 *                      : Created on November 28, 2013, 12:50 PM
 *                      : Exmple code displays a character on external character LCD received from UART module.
 */


#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
    #include <plib\usart.h>
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
    #include <usart.h>
#endif

#if defined(__XC) || defined(HI_TECH_C)
#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */
#endif

#if defined(__XC) || defined(__18CXX)
#include "config.h"
#include "xlcd_config.h"
#include "delay.h"
#include "uart.h"
#endif

#define Fosc 20000000
#define baud 9600
#define spbrg ((Fosc/baud/64)-1)

unsigned char config_1 = USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX & USART_BRGH_LOW;
unsigned char config_2 = spbrg;

void New_line(void)
{
 WriteUSART('\n');                                           /* Writing ASCII for return key                         */
    while(BusyUSART());                                         /* Wait until the write complete                        */
    WriteUSART('\r');                                           /* Writing ASCII for return key                         */
    while(BusyUSART());                                         /* Wait until the write complete                        */

}
void main( void )
    {
    unsigned char data, str[20] = "Enter a character\n\r";              /* Initialization of variables                                  */

    unsigned char i= 0;
    ADCON1 = 0X0F;
    ConfigUSART(config_1, config_2);
    OpenXLCD(EIGHT_BIT & LINE_5X7);                                     /* invoking External LCD configuration function                 */
    WriteCmdXLCD (BLINK_OFF & CURSOR_OFF);
    WriteCmdXLCD(0x01);
    while(1)
        {
        putsUSART((char *)str);                                             /*Passing the address of the String to the USART write function */
        while(BusyUSART());                                             /*Wait until USART goes to idle state                           */
        data = ReadUART();
        Write(data);
        New_line();
        while(BusyXLCD());                                              /* Wait if LCD busy                                             */
        WriteCmdXLCD(0x01);                                             /* Clear display                                                */
        WriteCmdXLCD(0x86);
        WriteDataXLCD(data);                                            /* writing data byte to external LCD                            */
        }
    }