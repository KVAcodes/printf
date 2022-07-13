#include "main.h"

/**
 * print_char - prints a char to stdout
 * @c: character argument
 *
 * Return: The no characters printed
 */
int print_char(va_list c)
{
	char tmpchar;
	int moreCharsPrinted;

	moreCharsPrinted = 0;
	tmpchar = va_arg(c, int);
	_putchar(tmpchar);
	moreCharsPrinted++;
	return (moreCharsPrinted);
}

/**
 * print_string - prints a string to stdout
 * @s: string argument
 *
 * Return: The no of characters printed
 */
int print_string(va_list s)
{
	int var1;

	char *str = va_arg(s, char *);

	for (var1 = 0; str[var1]; var1++)
	{
		_putchar(str[var1]);
	}
	return (var1);
}

/**
 * print_int - prints an integer
 * @id: an integer argument
 * Return: The no of characters printed to stdout
 * or the no of digits the integer is made of
 */
int print_int(va_list id)
{
	int num, order, digit, moreCharsPrinted;

	moreCharsPrinted = 0;

	num = va_arg(id, int);
	if (num < 0)
	{
		_putchar('-');
		num = num * -1;
		moreCharsPrinted++;
	}
	for (order = 1; num / order != 0; order *= 10)
	{
	}
	for (order /= 10; order > 0; order /= 10)
	{
		digit = num / order;
		num -= (digit * order);
		_putchar(digit + '0');
		moreCharsPrinted++;
	}
	return (moreCharsPrinted);
}

/**
 * print_binary - converts unsigned int argument to binary
 * and print it to stdout
 * @toBin: th unsigned int in base 10 to be converted and
 * printed to stdout
 *
 * Return: The no of binary digits printed to stdout
 */
int print_binary(va_list toBin)
{
	int var1, var2, baseNum, modValue, moreCharsPrinted;
	int binArr[50];

	var1 = 0;
	baseNum = va_arg(toBin, int);

	while (baseNum != 0)
	{
		modValue = baseNum % 2;
		baseNum /= 2;
		binArr[var1] = modValue;
		var1++;
	}
	for (var2 = var1 - 1; var2 >= 0; var2--)
	{
		_putchar('0' + binArr[var2]);
		moreCharsPrinted++;
	}
	return (moreCharsPrinted);
}
