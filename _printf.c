#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
/**
 * funcIdentifier - this function takes in a conversion specifier
 * and returns the corresponding print_* function to be used
 * @checkSpec: a character proceeding the % symbol to be checked
 * if its a conv specifier character listed in the array match
 *
 * Return: returns a function pointer or NULL if the checkSpec char
 * isn't among the list of conversion specifiers in the match array
 */
int (*funcIdentifier(char checkSpec))(va_list)
{
	int var1;
	match matcharr[] = {
				{'c', print_char},
				{'s', print_string},
				{'d', print_int},
				{'i', print_int},
				{'b', print_binary}
				};
	for (var1 = 0; var1 < 5; var1++)
	{
		if (matcharr[var1].convSpec == checkSpec)
		{
			return (matcharr[var1].funcPtr);
		}
	}
	return (NULL);
}

/**
 * _printf - produces output according to a format
 * @format: format is a character string which consists of one
 * or more directives
 *
 * Return: The number of characters printed (excluding the null
 * byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int var1, var2, charsPrinted;
	int (*printSubFunction)(va_list);
	va_list args;

	charsPrinted = 0;
	va_start(args, format);
	for (var1 = 0; format[var1] != 0; var1++)
	{
		if (format[var1] != '%' && format[var1 - 1] != '%')
		{
			_putchar(format[var1]);
			charsPrinted++;
			continue;
		}
		if (format[var1] == '%')
		{
			printSubFunction = funcIdentifier(format[var1 + 1]);
			if (printSubFunction != NULL)
			{
			var2 = printSubFunction(args);
			charsPrinted += var2;
			}
		}
		if (format[var1 - 1] == '%' && printSubFunction == NULL)
		{
			_putchar(format[var1]);
			charsPrinted++;
			continue;
		}
	}
	va_end(args);
	return (charsPrinted);
}
