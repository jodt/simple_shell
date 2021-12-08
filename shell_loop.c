#include "main.h"
/**
 * shell_loop - shell program
 * @argv: name of executable
 * @count: counter
 *
 * Return: 0
 */
int shell_loop(char **argv, int count)
{
	char *buff = NULL, **av = NULL;
	ssize_t result = 1, retour;

	result = prompt(&buff), count++;
	if (result == -1)
	{
		free_pointer(1, buff);
		return (1);
	}
	av = fillarguments(buff, " \t");
	if (av[0] == NULL)
	{
		free_pointer(1, buff), free_arrayofpointer(av);
		return (0);
	}
	if (av[0][0] != '/')
	{
		retour = checkBuiltins(av, buff);
		if (retour == 0 || retour == 2)
		{
			free_pointer(1, buff), free_arrayofpointer(av);
			retour == 0 ? (retour = 0) : (retour = 1);
			return (retour);
		}
		if (!(findinthepath(av)))
		{
			printerror(argv, count, av), free_pointer(1, buff), free_arrayofpointer(av);
			return (2);
		}
		else
		{
			if (processus(argv, av, buff, count) != 0)
			{
				free_pointer(2, *av, buff), free_arrayofpointer(av);
				return (3);
			}
			else
			{
				free_pointer(2, *av, buff), free_arrayofpointer(av);
				return (0);
			}
		}
	}
	if (processus(argv, av, buff, count) != 0)
	{
		free_pointer(1, buff), free_arrayofpointer(av);
		return (2);
	}
	free_pointer(1, buff), free_arrayofpointer(av);
	return (0);
}
