#include "main.h"
/**
 * printerror - prints an error message on stderr
 *
 * @argv: name of the executable
 * @count: counter of errors
 * @av: name of the command
 */

void printerror(char **argv, int count, char **av)
{
	write(2, *argv, strlen(*argv));
	write(2, ": ", 2);
	write_integer(count);
	write(2, ": ", 2);
	write(2, *av, strlen(*av));
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}
