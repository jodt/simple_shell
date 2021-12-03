#include "main.h"
/**
 * processus - create a processus with the command store in the buffer
 * @av: array of arguments
 * @buf: buffer
 * @count: counter
 * Return: void
 */
void processus(char **av, char *buf, int count)
{
	int status;
	pid_t id;

	if (buf == NULL)
		exit(100);

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
		_printf("./hsh: %d: %s: not found\n", count, av[0]);
		free_pointer(1, buf);
		free_arrayofpointer(av);
		exit(98);
	}
}
