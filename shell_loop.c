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
	ssize_t result = 1;

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

		return (checkcommand(argv, av, buff, count));
	}
	if (processus(argv, av, buff, count) != 0)
	{
		free_pointer(1, buff), free_arrayofpointer(av);
		return (2);
	}
	free_pointer(1, buff), free_arrayofpointer(av);
	return (0);
}
