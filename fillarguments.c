#include "main.h"
/**
 * fillarguments - divide a string and fill an array with each word
 * @buf : buffer which contains the string
 *
 * Return: array of words
 */
char **fillarguments(char *buf)
{
	char **arr = NULL;
	char *token;
	int i = 0, length;

	arr = malloc(sizeof(char *) * (number_of_words(buf) + 1));
	if (arr == NULL)
		exit(98);

	token = strtok(buf, " ");

	while (token)
	{
		arr[i++] = token;
		token = strtok(NULL, " ");
	}
	length = _strlen(arr[i - 1]);
	arr[i - 1][length - 1] = '\0';
	arr[i] = NULL;
	return (arr);
}

/**
 * number_of_words - count the number of words in a string
 * @str : a string
 *
 * Return: number of words
 */
int number_of_words(char *str)
{
	int i = 0, etat, nm = 0;

	etat = DEHORS;
	while (str[i])
	{
		if (str[i] == ' ')
			etat = DEHORS;
		else if (etat == DEHORS)
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
