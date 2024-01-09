#include "shell.h"

/**
 * freearv - Frees memory allocated for an array of strings.
 * @aray: Array of strings to be freed.
 */
void	freearv(char **aray)
{
	int n;

	if (!aray)
		return;
	for (n = 0 ; aray[n]; n++)
	{
		free(aray[n]);
		aray[n] = NULL;
	}
	free(aray), aray = NULL;
}
