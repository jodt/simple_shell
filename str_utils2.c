#include"main.h"
/**
 * _strdup - allocated space in memory with a copy of string
 * @str: string
 *
 * Return: pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *ptr;
	int length, i, j;

	if (str == NULL)
		return (NULL);
	for (length = 0; str[length]; length++)
		;
	ptr = malloc((length + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	for (i = 0, j = 0; i < length; i++, j++)
		ptr[j] = str[i];
	ptr[j] = '\0';
	return (ptr);
}
