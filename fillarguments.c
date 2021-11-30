#include "main.h"
/**
 * fillarguments - divide a string and fill an array with each word
 * @buf: buffer which contains the string
 * @separator: separator use to split the buffer
 *
 * Return: array of words
 */
char **fillarguments(char *buf, char *separator)
{
	char **arr = NULL;
	char *token;
	int i = 0, length;

  if (buf == NULL)
		return (NULL);

	arr = malloc(sizeof(char *) * (number_of_words(buf, separator) + 1));
	if (arr == NULL)
		exit(98);

	token = strtok(buf, separator);
	while (token)
	{
		if (token[0] == '\n')
			break;
		arr[i++] = token;
		token = strtok(NULL, separator);
	}
	length = _strlen(arr[i - 1]);
	if (arr[i - 1][length - 1] == '\n')
		arr[i - 1][length - 1] = '\0';
	arr[i] = NULL;
	return (arr);
}

/**
 * number_of_words - count the number of words in a string
 * @str: a string
 * @separator: separator use to split the string
 * Return: number of words
 */
int number_of_words(char *str, char *separator)
{
	int i = 0, etat, nm = 0;

	if (str == NULL)
		return (0);

	etat = DEHORS;
	while (str[i])
	{
		if (str[i] == separator[0])
			etat = DEHORS;
		else if (etat == DEHORS && str[i] != '\n')
		{
			etat = DEDANS;
			++nm;
		}
		i++;
	}
	return (nm);
}

/**
 * _strlen - count characters in a string
 * @str: a string
 *
 * Return: number of characters
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
