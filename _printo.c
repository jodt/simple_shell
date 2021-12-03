#include "main.h"
/**
 * _printo - prints integer to octal
 * @arglist: list of arguments
 *
 * Return: number of characters printed
 */
int _printo(va_list arglist)
{
	unsigned int n = va_arg(arglist, unsigned int);

	return (write_octal(n));
}

/**
 * write_octal - prints integer to octal with write's function
 * @number: integer;
 * Return: number of characters printed
 */
int write_octal(unsigned int number)
{
	int temp, characters_printed;

	characters_printed = 0;
	if (number / 8)
	{
		characters_printed = write_octal(number / 8);
	}
	temp = number % 8 + '0';
	return ((characters_printed + write(1, &temp, 1)));
}
