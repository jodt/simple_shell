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

	while (result)
	{
		result = prompt(&buff);
		if (result == -1)
		{
			free(buff);
			exit(100);
		}
		av = fillarguments(buff, " ");
    checkBuiltins(av, buff);
		if (av[0][0] != '/')
		{
			if (!(findinthepath(av)))
			{
				printf("%s: 1: %s: not found\n", argv[0], av[0]);
				freememory(buff, av);
				continue;
			}
			else
			{
				processus(av, buff);
				free(*av);
				freememory(buff, av);
				continue;
			}
		}
		processus(av, buff);
		freememory(buff, av);
	}
	free(buff);
	return (0);
}
