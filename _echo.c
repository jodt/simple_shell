#include "main.h"

int _echo(char **av)
{
	int pid;
	if (av[2])
		write(1, "too many arguments\n", 20);
	else
	{
		if (_strcmp("$$", av[1]) == 0)
		{
			pid = getpid();
			_printf("%i\n", pid);
			return (0);
		}
		else if (_strcmp("$?", av[1]) == 0)
			write(1, "exit command is used for exit the shell.\n", 42);
		else if (_strcmp("$X", av[1]) == 0)
		{
			write(1, "echo command is used for write arguments to the standar ", 57);
			write(1, "output.\n", 9);
		}
		else
			_printf("%s", av[1]);
	}
	return (0);
}