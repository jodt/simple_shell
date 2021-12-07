#include "main.h"
/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: always 0 if success
 */
int main(int argc __attribute__((unused)), char **argv)
{

	signal(SIGINT, handler);
	while (1)
	{
		shell_loop(argv);
	}
	return (0);
}
