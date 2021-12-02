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
	char *pwd = _strdup(_getenv("PWD")), *path = _strdup(_getenv("PATH"));
	char *str, *dirname;
	unsigned int i = 0, j = 0, lengthdirname = 0;
	struct stat st;

	if (path[0] == ':')
	{
		str = malloc(sizeof(char) * (_strlen(pwd) + _strlen(path) + 1));
		_strcpy(str, pwd);
		_strcat(str, path);
	}
	else
	{
		str = malloc(sizeof(char) * (strlen(path)) + 1);
		_strcpy(str, path);
	}
	i = j = 0;
	arr_directory = fillarguments(str, ":");
	while (arr_directory[i])
	{
		lengthdirname = _strlen(arr_directory[i]) + _strlen(*firstargument);
		dirname = malloc(sizeof(char) * (lengthdirname + 2));
		_strcpy(dirname, arr_directory[i]);
		_strcat(_strcat(dirname, "/"), firstargument[0]);
		if (stat(dirname, &st) == 0)
		{
			*firstargument = strdup(dirname);
			free_pointer(4, dirname, str, pwd, path);
			free_arrayofpointer(arr_directory);
			return (1);
		}
		j = 0;
		free(dirname);
		i++;
	}
	free(arr_directory), free_pointer(3, str, pwd, path);
	return (0);
}
