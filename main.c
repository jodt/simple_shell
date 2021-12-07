#include "main.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: always 0 if success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int count = 0;

	signal(SIGINT, handler);
	while (1)
	{
		shell_loop(argv, count);
		count++;
	}
	return (0);
}
