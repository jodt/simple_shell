#include "main.h"

/**
  * _prints - Handling the %s format of printf
  * @arg: Current arg.
  *
  * Return: Full string
  */

int _prints(va_list arg)
{
	int i;
	char *str = va_arg(arg, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}
