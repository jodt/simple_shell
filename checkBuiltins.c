#include "main.h"

/**
 * checkBuiltins - Check for built in commands
 * @av: Argument to check
 * @buff: buffer
 *
 * Return : void
 */

void checkBuiltins(char **av, char *buff)
{
	if (_strcmp("env", av[0]) == 0 && _strlen(av[0]) == 3)
		printenv();
	if (_strcmp("exit", av[0]) == 0 && _strlen(av[0]) == 4)
	{
		free(buff);
		exit(100);
	}
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
		printf("%s\n", environ[i]);
		i++;
	}
}
