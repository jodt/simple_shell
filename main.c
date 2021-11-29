#include "main.h"
/**
 * main - Entry point
 *
 * Return: always 0 if success
 */
int main(void)
{
	char *buff = NULL;
	char **av = NULL;
	ssize_t result = 1;
	char *output = "exit";
	int i = 0;

	while (result)
	{
		result = prompt(&buff);
		if (result == -1)
		{
			free(buff);
			exit(100);
		}
		av = fillarguments(buff);

		while (output[i]) /** Exit case **/
		{
			if (output[i] != av[0][i])
				break;
			if (i == 3)
				exit(1);
			i++;
		}
		processus(av, buff);
		free(buff);
		free(av);
	}
	free(buff);
	return (0);
}
