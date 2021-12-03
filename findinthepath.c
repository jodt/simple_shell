#include "main.h"
/**
 * findinthepath - looking for a command in the PATH
 * @firstargument: list of arguments
 *
 * Return: 1 if the command is found, otherwhise 0
 */
char *findinthepath(char **firstargument)
{
	char **arr_directory = NULL;
	char *pwd, *path, *str, *dirname;
	unsigned int i = 0, j = 0, lengthdirname = 0;
	struct stat st;

	if (firstargument == NULL)
		return (NULL);
	pwd = _strdup(_getenv("PWD"));
	if (pwd == NULL)
		return (NULL);
	path = _strdup(_getenv("PATH"));
	if (path == NULL)
	{
		free_pointer(1, pwd);
		return (NULL);
	}
	if (path[0] == ':')
	{
		str = malloc(sizeof(char) * (_strlen(pwd) + _strlen(path) + 1));
		if (str == NULL)
		{
			free_pointer(2, pwd, path);
			return (NULL);
		}
		_strcpy(str, pwd);
		_strcat(str, path);
	}
	else if (_strstr(path, "::") != NULL)
	{
		str = updatethepath(path, pwd);
		if (str == NULL)
		{
			free_pointer(2, pwd, path);
			return (NULL);
		}
	}
	else
	{
		str = malloc(sizeof(char) * (strlen(path)) + 1);
		if (str == NULL)
		{
			free_pointer(2, pwd, path);
			return (NULL);
		}
		_strcpy(str, path);
	}
	i = j = 0;
	arr_directory = fillarguments(str, ":");
	if (arr_directory == NULL)
		return (NULL);
	while (arr_directory[i])
	{
		lengthdirname = _strlen(arr_directory[i]) + _strlen(*firstargument);
		dirname = malloc(sizeof(char) * (lengthdirname + 2));
		if (dirname == NULL)
		{
			free_pointer(3, path, pwd, str);
			free_arrayofpointer(arr_directory);
			return (NULL);
		}
		_strcpy(dirname, arr_directory[i]);
		_strcat(_strcat(dirname, "/"), firstargument[0]);
		if (stat(dirname, &st) == 0)
		{
			*firstargument = _strdup(dirname);
			if (*firstargument == NULL)
			{
				free_pointer(4, dirname, str, pwd, path);
				free_arrayofpointer(arr_directory);
				return (NULL);
			}
			free_pointer(4, dirname, str, pwd, path);
			free_arrayofpointer(arr_directory);
			return (*firstargument);
		}
		j = 0;
		free_pointer(1, dirname);
		i++;
	}
	free_arrayofpointer(arr_directory), free_pointer(3, str, pwd, path);
	return (NULL);
}
