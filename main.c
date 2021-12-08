#include "main.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: always 0 if success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int count = 0, retour, status;
	pid_t id;

	signal(SIGINT, handler);
	while (1)
	{
		if (retour == 2)
			break;
		retour = shell_loop(argv, count);
		if (retour != 0)
		{
			id = fork();
			if (id == -1)
			{
				perror("Error fork: ");
				return (EXIT_FAILURE);
			}
			if (id != 0)
			{
				wait(&status);
				return (127);
			}
			else
				continue;
		}
		count++;
	}
	return (0);
}
