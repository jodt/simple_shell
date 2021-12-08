#include "main.h"
/**
 * checkcommand - check command who's not starting with a "/"
 * @argv: name of executable
 * @av: array of arguments
 * @buf: buffer
 * @count: counter
 *
 * Return: 0 on success, else nonzero value
 *
 */
int checkcommand(char **argv, char **av, char *buf, int count)
{
	int retour;

	retour = checkBuiltins(av, buf);
	if (retour == 0 || retour == 2)
	{
		free_pointer(1, buf), free_arrayofpointer(av);
		retour == 0 ? (retour = 0) : (retour = 1);
		return (retour);
	}
	if (!(findinthepath(av)))
	{
		printerror(argv, count, av), free_pointer(1, buf), free_arrayofpointer(av);
		return (2);
	}
	else
	{
		processus(argv, av, buf, count);
		free_pointer(2, *av, buf), free_arrayofpointer(av);
		return (0);
	}
}
