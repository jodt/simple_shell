#include "main.h"
/**
 * main - Entry point
 *
 * Return: always 0 if success
 */
int main(void)
{
	char *buff = NULL;
	char *av[] = {NULL};
	ssize_t result = 1;

	while (result)
	{
		result = prompt(&buff);
		if (result == -1)
		{
			free(buff);
			exit(100);
		}

		processus(av, buff, result);
		free(buff);
	}
	free(buff);
	return (0);
}
