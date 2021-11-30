#include "main.h"
/**
 * freememory - free the memory from buffer and array of arguments
 * @buff: buffer
 * @av: array of arguments
 *
 * Return: void
 */
void freememory(char *buff, char **av)
{
	free(buff);
	free(av);
}
