#include "main.h"
/**
 * processus - create a processus with the command store in the buffer
 * @argv: name of the shell
 * @av: array of arguments
 * @buf: buffer
 * @count: counter
 * Return: void
 */
int processus(char **argv, char **av, char *buf, int count)
{
	int status;
	pid_t id;

	if (buf == NULL)
		return (-1);

	id = fork();
	if (id == -1)
	{
		free_pointer(1, buf);
		exit(99);
	}
	if (id != 0)
		wait(&status);
	else if ((execve(av[0], av, NULL)) == -1)
	{
		printerror(argv, count, av);
		free_pointer(1, buf);
		free_arrayofpointer(av);
		_exit(98);
	}
	return (status);
}
