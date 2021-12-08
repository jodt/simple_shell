#include "main.h"

/**
 * _cd - recreate cd function
 *
 * @av: argument valeur
 * Return: env change
 */

int _cd(char **av)
{
	char hyphen[] = "-";
	char *buff = malloc(sizeof(char) * 1024);

	if (av[1] == NULL)
	{
		if (!_getenv("HOME"))
			write(1, printerror, _strlen(printerror));
		else
		{
			chdir(_getenv("HOME"));
			setenv("OLDPWD", _getenv("PWD"), 1);
			setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
		}
	}
	else if (_strcmp(av[1], hyphen) == 0)
	{
		if (!_getenv("OLDPWD"))
			setenv("OLDPWD", _getenv("PWD"), 1);
		else
		{
			chdir(_getenv("OLDPWD"));
			setenv("OLDPWD", _getenv("PWD"), 1);
			setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
		}
		write(1, _getenv("PWD"), _strlen(_getenv("PWD")));
		_printf("\n");
	}
	else if (av[1] != NULL && av[1] != hyphen)
	{
		if (access(av[1], F_OK) == -1)
			write(1, printerror, _strlen(printerror));
		else
		{
			setenv("OLDPWD", _getenv("PWD"), 1);
			chdir(av[1]);
			setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
		}
	}
	free(buff);
	return (0);
}
