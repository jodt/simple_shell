#include "main.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: always 0 if success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int count = 0, retour;

	signal(SIGINT, handler);
	while (1)
	{
		retour = shell_loop(argv, count);
		if (retour == 2)
			return (127);
		if (retour != 0)
			break;
		count++;
	}
	return (0);
}
