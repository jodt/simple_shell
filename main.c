#include "main.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: always 0 if success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *buff = NULL;
	char **av = NULL;
	ssize_t result = 1;
	int count = 0;

	while (result)
	{
		result = prompt(&buff);
		count++;
		if (result == -1)
		{
			free_pointer(1, buff);
			exit(100);
		}
		av = fillarguments(buff, " \t");
		if (checkBuiltins(av, buff) != 0)
		{
			free_pointer(1, buff), free_arrayofpointer(av);
			continue;
		}
		if (av[0][0] != '/')
		{
			if (!(findinthepath(av)))
			{
				_printf("%s: %d: %s: not found\n", argv[0], count, av[0]);
				free_pointer(1, buff), free_arrayofpointer(av);
				continue;
			}
			else
			{
				processus(av, buff, count);
				free_pointer(2, *av, buff), free_arrayofpointer(av);
				continue;
			}
		}
		processus(av, buff, count);
		free_pointer(1, buff), free_arrayofpointer(av);
	}
	free_pointer(1, buff);
	return (0);
}
