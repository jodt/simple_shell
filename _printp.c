#include "main.h"

/**
 * _printp - prints int to hexadecimal
 * @arglist: list of arguments
 *
 * Return: number of characters printed
 */
int _printp(va_list arglist)
{
	uintptr_t ptr = va_arg(arglist, uintptr_t);
	int i = 0;

	if (ptr == 0)
	{
		write(1, "(", 1);
		write(1, "n", 1);
		write(1, "i", 1);
		write(1, "l", 1);
		write(1, ")", 1);
		return (5);
	}

	write(1, "0", 1);
	write(1, "x", 1);
	i += 2;
	i += write_x(ptr);

	return (i);
}
