#include "main.h"

int _strlen(char *str);

/**
  * _printS - Handling the %S format of printf
  * @arg: Current arg.
  *
  * Return: Full string
  */

int _printS(va_list arg)
{
	int i, count = 0;
	char *str = va_arg(arg, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			write(1, &str[i], 1);
			count++;
		}
		else
		{
			write(1, "\\", 1);
			write(1, "x", 1);
			count += 2;
			if (str[i] < 16)
			{
				write(1, "0", 1);
				count++;
			}
			count += write_X(str[i]);
		}
		i++;
	}
	return (count);
}
