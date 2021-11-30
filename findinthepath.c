#include "main.h"
/**
 * findinthepath - looking for a command in the PATH
 * @firstargument: list of arguments
 *
 * Return: 1 if the command is found, otherwhise 0
 */
int findinthepath(char **firstargument)
{
	char **arr_directory = NULL;
	char *str = strdup(_getenv("PATH"));
	char *dirname;
	unsigned int i = 0, j = 0, k = 0, lengthdirname = 0;
	struct stat st;

	arr_directory = fillarguments(str, ":");
	while (arr_directory[i])
	{
		lengthdirname = _strlen(arr_directory[i]) + _strlen(*firstargument);
		dirname = malloc(sizeof(char) * (lengthdirname + 2));
		while (arr_directory[i][j])
		{
			dirname[j] = arr_directory[i][j];
			j++;
		}
		dirname[j++] = '/';
		while (firstargument[0][k])
		{
			dirname[j + k] = firstargument[0][k];
			k++;
		}
		dirname[j + k] = '\0';
		if (stat(dirname, &st) == 0)
		{
			*firstargument = strdup(dirname);
			free(dirname);
			free(arr_directory);
			free(str);
			return (1);
		}
		j = 0;
		k = 0;
		free(dirname);
		i++;
	}

	free(arr_directory);
	free(str);
	return (0);
}
