#include "main.h"

/**
 * _setenv - Set or create an existing environnement variable.
 * @name: Name of the variable
 * @value: Value of the variable
 *
 */

int _setenv(char *name, char *value)
{
	int i = 0, j = 0;
	char *variable;
	int length = _strlen(name) + _strlen(value) + 1;

	if (name == NULL && value == NULL)
	{
		printenv();
		return (0);
	}

	variable = malloc(sizeof(char) * (length + 1));
	if (variable == NULL)
		return (0);

	_strcat(_strcpy(variable, name), "=");
	if (value)
		_strcat(variable, value);

	while (environ[i++])
	{
		j = 0;
		while (name[j] == environ[i][j])
		{
			if (!name[j + 1] && environ[i][j + 1] == '=')
			{
				environ[i] = strdup(variable);
				free(variable);
				return (0);
			}
			j++;
		}
	}
	environ[i] = strdup(variable);
	free(variable);
	i++;
	environ[i] = NULL;
	return (0);
}
