#include "main.h"

/**
 * exit_status - Handle arguments for built in exit
 *
 * @av: argument
 *
 */

int exit_status(char **av, char *buff __attribute__((unused)))
{
	int exit_status = 0;

	if (av[1])
		exit_status = atoi(av[1]);
	else
		return (2);

	if (av[1] && exit_status > 0 && exit_status <= 2147483647)
		exit(exit_status);
	else
		write(2, "Invalid syntax\n", 15);

	return (0);
}
