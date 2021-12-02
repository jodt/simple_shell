#include "main.h"
/**
 * free_pointer - free the memory from buffer and array of arguments
 * @n: number of arguments
 *
 * Return: void;
 */
void free_pointer(const unsigned int n, ...)
{
	va_list arglist;
	unsigned int i;
	char *arg;

	va_start(arglist, n);
	for (i = 0; i < n; i++)
	{
		arg = va_arg(arglist, char *);
		free(arg);
	}
}

/**
 * free_arrayofpointer - free the memory of pointer array
 * @arr: pointer array
 * Return: void
 */
void free_arrayofpointer(char **arr)
{
	free(arr);
}
