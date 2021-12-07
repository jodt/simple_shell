#include "main.h"
/**
 * shell_loop - shell program
 * @argv: name of executable
 *
 * Return: 0
 */
int shell_loop(char **argv)
{
	char *buff = NULL, **av = NULL;
	ssize_t result = 1, count = 0;

	result = prompt(&buff), count++;
	if (result == -1)
	{
		free_pointer(1, buff);
		exit(100);
	}
	av = fillarguments(buff, " \t");
	if (av[0] == NULL)
	{
		free_pointer(1, buff), free_arrayofpointer(av);
		return (0);
	}
	if (av[0][0] != '/')
	{
		if (checkBuiltins(av, buff) == 0)
		{
			free_pointer(1, buff), free_arrayofpointer(av);
			return (0);
		}
		if (!(findinthepath(av)))
		{
			printerror(argv, count, av), free_pointer(1, buff), free_arrayofpointer(av);
			return (0);
		}
		else
		{
			processus(argv, av, buff, count);
			free_pointer(2, *av, buff), free_arrayofpointer(av);
			return (0);
		}
	}
	processus(argv, av, buff, count);
	free_pointer(1, buff), free_arrayofpointer(av);
	return (0);
}
