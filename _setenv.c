#include "main.h"

/**
 * _setenv - Set or create an existing environnement variable.
 * @name: Name of the variable
 * @value: Value of the variable
 * @overwrite: replace variable if nonzero value
 *
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0;
	char *variable;
	int length = _strlen((char *)name) + _strlen((char *)value) + 1;

	if (name == NULL || value == NULL || i < 0)
	{
		return (-1);
	}
	variable = malloc(sizeof(char) * (length + 1));
	if (variable == NULL)
		return (-1);
	while (name[i])
	{
		variable[i] = name[i];
		i++;
	}
	variable[i] = '=';
	i++;
	while (value[j])
	{
		variable[i + j] = value[j];
		j++;
	}
	variable[i + j] = '\0';
	i = 0;
	while (environ[i])
	{
		j = 0;

		while (name[j] == environ[i][j])
		{
			if (!name[j + 1] && environ[i][j + 1] == '=')
			{
				if (overwrite > 0)
				{
					environ[i] = strdup(variable);
					free(variable);
					return (0);
				}
				else
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	environ[i] = strdup(variable);
	free(variable);
	i++;
	environ[i] = NULL;
	return (0);
}
