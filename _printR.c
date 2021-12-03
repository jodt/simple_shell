#include "main.h"
/**
 * _printR - prints a string in ROT13
 * @arglist: list of arguments
 *
 * Return: number of charaters printed
 */
int _printR(va_list arglist)
{
	int i = 0, j, character_found;
	char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(arglist, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		j = 0;
		character_found = 0;
		while (alphabet[j])
		{
			if (str[i] == alphabet[j])
			{
				write(1, &rot13[j], 1);
				character_found = 1;
				break;
			}
			j++;
		}
		if (character_found == 0)
			write(1, &str[i], 1);
		i++;
	}
	return (i);
}
