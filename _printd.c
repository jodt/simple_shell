#include "main.h"
/**
 * _printd - print an integer
 * @arglist : list of arguments
 * Return: number of characters printed
 */
int _printd(va_list arglist)
{
	int c = va_arg(arglist, int);

	return (write_integer(c));
}
/**
 * write_integer - print an integer with write's function
 * @number: integer
 * Return: number of characters printed
 */

int write_integer(int number)
{
	int temp, characters_printed = 0;
	unsigned int c1;

	if (number < 0)
	{
		number = -number;
		write(1, "-", 1);
		characters_printed++;
	}
	c1 = number;
	if (c1 / 10)
	{
		characters_printed += write_integer(c1 / 10);
	}
	temp = (c1 % 10) + '0';
	return (characters_printed += write(1, &temp, 1));
}
