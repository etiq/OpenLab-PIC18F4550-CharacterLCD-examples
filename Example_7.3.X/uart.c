/*
 * File name            : uart.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example_7.3 External Character LCD
 *                      : Created on November 28, 2013, 12:50 PM
 *                      : uart functions source file
 */
#if defined(__XC)
    #include <plib\usart.h>

#elif defined(__18CXX)
    #include <usart.h>
#endif

/*_____________________________________________configure USART____________________________________________________________*/

void ConfigUSART(unsigned char config_1, unsigned char config_2)
{
OpenUSART(config_1, config_2);
}

unsigned char ReadUART(void)
{
while(!(DataRdyUSART()));                                           /* Reading a data byte                                        */
     return(ReadUSART());
}


void Write_str(unsigned char* str)
{
putsUSART((char *)str);                                         /*Passing the address of the String to the USART write function */
    while(BusyUSART());                                         /*Wait until USART goes to idle state                           */

}

void Write(char data)
{
    WriteUSART(data);                                           /* Write a byte through USART module                    */
    while(BusyUSART());                                         /* Wait until the write complete                        */
}
