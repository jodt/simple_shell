#include "main.h"

#define BUF 1000

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
		setenv("OLDPWD", _getenv("PWD"), 1);
		chdir("/home/vagrant");
		setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
	}
	else if (_strcmp(av[1], hyphen) == 0)
	{
		setenv("OLDPWD", _getenv("PWD"), 1);
		chdir("..");
		setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
	}
	else if (av[1] != NULL && av[1] != hyphen)
	{
		setenv("OLDPWD", _getenv("PWD"), 1);
		chdir(av[1]);
		setenv("PWD", getcwd(buff, sizeof(char) * 1024), 1);
	}

	free(buff);
	return (0);
}
