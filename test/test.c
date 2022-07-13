#include <stdio.h>
#include "main.h"
int main(void)
{
	int num, order, digit, moreCharsPrinted;

	moreCharsPrinted = 0;

	num = 1928;
	if (num < 0)
	{
		_putchar('-');
		num = num * -1;
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
