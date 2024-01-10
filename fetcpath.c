#include "shell.h"

/**
 * fetchpath - Search for the full path of a command in the PATH directories.
 * @comma: The command or a partial path to search for.
 *
 * This function attempts to find the full path of a command by searching
 * through the directories listed in the PATH environment variable.
 *
 * @comma: The command or a partial path to search for.
 *
 * Return: A dynamically allocated string containing the full path of the
 * command if found, or NULL if the command is not found in any directory.
 */
char	*fetchpath(char *comma)
{
	char *fetch_env, *total_cmd, *dir;
	int n;
	struct stat st;

	for (n = 0; comma[n]; n++)
	{
		if (comma[n] == '/')
		{
			if (stat(comma, &st) == 0)
				return (_strdup(comma));
			return (NULL);
		}
	}
	fetch_env = accessenv("PATH");
	if (!fetch_env)
		return (NULL);
	dir = strtok(fetch_env, ":");
	while (dir)
	{
		total_cmd = malloc(strlen(dir) + strlen(comma) + 2);
		if (total_cmd)
		{
			_strcpy(total_cmd, dir);
			_strcat(total_cmd, "/");
			_strcat(total_cmd, comma);
			if (stat(total_cmd, &st) == 0)
			{
				free(fetch_env);
				return (total_cmd);
			}
			free(total_cmd), total_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(fetch_env);
	return (NULL);
}
