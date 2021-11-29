#include "main.h"
/**
 * processus - create a processus with the command store in the buffer
 * @av: array of arguments
 * @buf: buffer
 *
 * Return: void
 */
void processus(char **av, char *buf)
{
	int status;
	pid_t id;

	id = fork();
	if (id == -1)
	{
		free(buf);
		exit(99);
	}
	if (id != 0)
		wait(&status);
	else if ((execve(av[0], av, NULL)) == -1)
	{
		free(buf);
		exit(98);
	}
}
