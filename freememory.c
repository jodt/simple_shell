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

/**
 * freememory2 - free the memory from buffer and array of arguments
 * @str1: string's pointer
 * @str2: string's pointer
 * @str3: string's pointer
 *
 * Return: void
 */
void freememory2(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
}
