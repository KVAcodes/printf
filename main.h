#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct match - contains conversion specifiers and its corresponding
 * function pointers
 * @convSpec: a char representing the position and datatype 
 * of an argument to be substituted into the format string
 * @funcPtr: function pointer to a function that takes in a va_list argument
 * and returns nothing but prints the argument to stdout
 */
typedef struct match
{
	char convSpec;
	int (*funcPtr)(va_list);
} match;
int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list);
int print_string(va_list);
int print_int(va_list);
int print_binary(va_list);
int (*funcIdentifier(char checkSpec))(va_list);

#endif
