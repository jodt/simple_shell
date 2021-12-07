#include "main.h"

/**
 * checkBuiltins - Check for built in commands
 * @av: Argument to check
 * @buff: buffer
 *
 * Return: 0 success, 1 not found
 */

int checkBuiltins(char **av, char *buff)
{
	if (av && buff)
	{
		if (_strcmp("env", av[0]) == 0 && _strlen(av[0]) == 3)
		{
			printenv();
			return (0);
		}
		else if (_strcmp("exit", av[0]) == 0 && _strlen(av[0]) == 4)
		{
			free_pointer(1, buff), free_arrayofpointer(av);
			exit(100);
		}
		else if (_strcmp("cd", av[0]) == 0 && _strlen(av[0]) == 2)
		{
			_cd(av);
			return (0);
		}
		if (_strcmp("help", av[0]) == 0 && _strlen(av[0]) == 4)
		{
			_help(av);
		}
		if (_strcmp("echo", av[0]) == 0 && _strlen(av[0]) == 4)
		{
			_echo(av);
		}
		return (0);
	}
	return (1);
}

/**
 * printenv - Print the environnment
 *
 * Return: Void
 */

void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_printf("%s\n", environ[i]);
		i++;
	}
}
