/*
 * SWV_print.c
 *
 *	Intent is two-fold.
 *	1) move learning-to-debug function (prime #) out of main.c
 *	2) ensure I can add files to project successfully for future operations
 *
 *  Created on: Jun 7, 2021
 *      Author: tech
 */


#include <SWV_print.h>

extern UART_HandleTypeDef huart1;


/*
debug_printf sends a max of 256 characters to the ITM SWO trace debugger.
It uses a _variable length argument_, same as normal printf.
Indeed, just call this function as if it was printf, and you'll get the 
behaviour you expect.
I also like doing it this way since I can change the definition of the 
function as needed. 
 
My note: this requires the ITM_SendChar() found in 
Drivers\CMSIS\Include\core_cm4.h 
 
*/

void debug_printf(const char *fmt, ...) {
    char buffer[256] = {0};
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    uint16_t i = 0;
    while(buffer[i] != '\0') 
    {
      ITM_SendChar(buffer[i]);
      i++;
    }
}



void debug_uart_printf(const char *fmt, ...) {
    char buffer[256] = {0};
    uint8_t* ptr;
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    uint16_t i = 0;
    while(buffer[i] != '\0')
    {
    	ptr = (uint8_t*)&buffer[i];
      //ITM_SendChar(buffer[i]);
  	  HAL_UART_Transmit(&huart1, ptr, 1, 1000); //1 is the number of characters, 1000 milliseconds timeout

      i++;
    }
}





