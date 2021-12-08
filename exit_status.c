#include "main.h"

/**
 * exit_status - Handle arguments for built in exit
 *
 * @av: argument
 *
 */

int exit_status(char *av)
{
	int exit_status = 0;

	if (!av)
		return (2);

	exit_status = atoi(av);
	if (av && exit_status > 0 && exit_status <= 2147483647)
	{
		printf("%d\n", exit_status);
		_exit(exit_status);
	}
	else
	{
		if (atoi(av) != 0)
		{
			write(2, "1: exit: Illegal number:", 24);
			write(2, &exit_status, 25);
			write(2, "\n", 1);
		}
	}

	return (0);
}
