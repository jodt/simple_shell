#include "main.h"

int _echo(char **av)
{
	int pid;

	if (av[2])
		write(2, "Too many arguments\n", 20);
	else
	{
		if (_strcmp("$$", av[1]) == 0)
		{
			pid = getpid();
			_printf("%i\n", pid);
		}
		else
			_printf("%s", av[1]);
	}
	return (0);
}
