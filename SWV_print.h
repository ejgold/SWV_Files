/*
 * SWV_print.h
 *
 *  Created on: Jun 7, 2021
 *      Author: tech
 */

#ifndef INC_SWV_PRINT_H_
#define INC_SWV_PRINT_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

// For the F4xx family include this one (test to see if it works - ejf 6-10)
#include <stm32f4xx.h>

void debug_printf(const char *fmt, ...);
void debug_uart_printf(const char *fmt, ...);


#endif /* INC_SWV_PRINT_H_ */
