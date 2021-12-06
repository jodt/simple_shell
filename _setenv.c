#include "main.h"
/**
 * _setenv -dds the variable name to the environment with the value
 * @name: name of the variable
 * @value: value of the variable
 * @overwrite: a nonzero overwrite the value, 0 does'nt change the value.
 *
 * Return: 0 if success, -1 if error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0, j = 0;
	char *variable, **environ;
	int length = _strlen((char *)name) + _strlen((char *)value) + 1;

	if (name == NULL || value == NULL || i < 0)
		return (-1);
	variable = malloc(sizeof(char) * (length + 1));
	if (variable == NULL)
		return (-1);
	while (name[i])
		variable[i] = name[i], i++;
	variable[i] = '=', i++;
	while (value[j])
		variable[i + j] = value[j], j++;
	variable[i + j] = '\0', i = 0;
	while (environ[i])
	{
		j = 0;

		while (name[j] == environ[i][j])
		{
			if (!name[j + 1] && environ[i][j + 1] == '=')
			{
				if (overwrite > 0)
				{
					environ[i] = strdup(variable), free(variable);
					return (0);
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	environ[i] = strdup(variable);
	free(variable), i++;
	environ[i] = NULL;
	return (0);
}