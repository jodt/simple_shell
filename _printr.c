#include "main.h"

/**
  * _printr - Print reverted string
  * @arg: Current arg.
  *
  * Return: number of characters
  */

int _printr(va_list arg)
{
	char *str = va_arg(arg, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	return (write_reverse(str));
}

/**
  * write_reverse - write string in reverse
  * @str: string
  *
  * Return: Number of characters
  */

int write_reverse(char *str)
{
	int count = 0;

	if (!*str)
		return (count);

	count = write_reverse(str + 1);

	return (count += write(1, &*str, 1));
}
