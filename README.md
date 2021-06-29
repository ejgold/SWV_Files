# SWV_Files
Last Update 6/21/2021 Contains the separate files to do string print thru ITM console.
The header file may need to have the included file (<stm32f4xx.h>) changed to fit the family of the MCU.
Copy SWV_print.c into Core\src
Copy SWV_print.h into Core\inc
example_main.c shows where to place the include file SWV_print.h
main() shows example usage


HUART1 extern added - may need to change to HUART2
debug_uart_printf() implemented for transmission to TT

