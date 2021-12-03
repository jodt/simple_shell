#include "main.h"
/**
 * updatethepath - update the path with current directory
 *
 * @path: path
 * @pwd: working directory
 *
 * Return: path updated
 */
char *updatethepath(char *path, char *pwd)
{
	int i = 0, j = 0, k = 0;
	char *str = malloc(sizeof(char) * (strlen(pwd) + strlen(path) + 1));

	while (path[i])
	{
		if (path[i] == ':' && path[i + 1] == ':')
		{
			str[k++] = ':';
			while (pwd[j])
			{
				str[k] = pwd[j];
				k++, j++;
			}
			str[k] = ':';
			while (path[i] == ':')
				i++;
			i--;
		}
		else
			str[k] = path[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
