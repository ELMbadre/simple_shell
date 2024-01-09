#include "shell.h"

/**
 * textSegmenter - Splits a line of text into an array of tokens (words).
 * @line: The input line to be split.
 *
 * Return: An array of strings (tokens) or NULL if an error occurs.
 */
char	**textSegmenter(char *line)
{
	char *tok = NULL, *tmp = NULL;
	char **cmd = NULL;
	int cumpt = 0, i = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	tok = strtok(tmp, DELIM);
	if (tok == NULL)
	{
		free(tmp), tmp = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (tok)
	{
		cumpt++;
		tok = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	cmd = malloc(sizeof(char *) * (cumpt + 1));
	if (!cmd)
	{
		free(line);
		return (NULL);
	}

	tok = strtok(line, DELIM);
	while (tok)
	{
		cmd[i++] = _strdup(tok);
		tok = strtok(NULL, DELIM);
	}
	free(line);/*line == NULL;*/
	cmd[i] = NULL;
	return (cmd);
}
