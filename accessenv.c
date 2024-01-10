#include "shell.h"

/**
 * accessenv - Retrieves the value of an environment variable.
 * @var: The name of the environment variable to retrieve.
 *
 * Return:A pointer to the value of environment variable or NULL if n found.
 */
char *accessenv(char *var)
{
	int i;
	char *tmpe, *ky, *vale, *enve;

	for (i = 0; environ[i]; i++)
	{
		tmpe = _strdup(environ[i]);
		ky = strtok(tmpe, "=");
		if (_strcmp(ky, var) == 0)
		{
			vale = strtok(NULL, "\n");
			enve = _strdup(vale);
			free(tmpe);
			return (enve);
		}
		free(tmpe), tmpe = NULL;
	}
	return (NULL);
}
