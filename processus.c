#include "main.h"
/**
 * processus - create a processus with the command store in the buffer
 * @av: array of arguments
 * @buf: buffer
 * @characters_numbers: number of characters
 *
 * Return: void
 */
void processus(char **av, char *buf, ssize_t characters_numbers)
{
	int status;
	pid_t id;

	av[0] = buf;
	if (av[0])
		av[0][characters_numbers - 1] = '\0';
	av[1] = NULL;
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
