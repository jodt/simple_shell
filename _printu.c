#include "main.h"
/**
 * _printu - print an unsigned integer
 * @arglist : list of arguments
 * Return: number of characters printed
 */
int _printu(va_list arglist)
{
	unsigned int c;

	c = va_arg(arglist, unsigned int);
	return (write_uninteger(c));
}
/**
 * write_uninteger - print an integer with write's function
 * @number: integer;
 * Return: number of characters printed
 */

int write_uninteger(unsigned int number)
{
	unsigned int temp, characters_printed;

	characters_printed = 0;
	if (number / 10)
		characters_printed = write_uninteger(number / 10);
	temp = (number % 10) + '0';
	return (characters_printed + write(1, &temp, 1));
}
