#include "shell.h"

/**
 * main - The main function of the shell.
 * @ac: The number of command-line arguments.
 * @av: An array containing the command-line arguments.
 *
 * Return: The exit status of the shell.
 */
int	main(int ac, char **av)
{
	char *ln = NULL;
	char **cmd = NULL;
	int stateInfo = 0;
	(void)ac;
	(void)av;

	while (1)
	{
		ln = readRow();
		if (ln == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stateInfo);
		}
		/*  idx++;*/
		cmd = textSegmenter(ln);
		if (!cmd)
			continue;
		/*if (is_builtin(cmd[0]))*/
		 /* handle_builtin(cmd, av, &stateInfo, idx);*/
		/*else*/
		stateInfo = carryOut(cmd, av);
	}
}
