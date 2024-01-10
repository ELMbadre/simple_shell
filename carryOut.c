#include "shell.h"

/**
 * carryout - Execute a command and handle the associated processes.
 * @comd: An array containing the command and its arguments.
 * @argv: An array containing the program name and its arguments.
 * @idx: The index representing the command's position in input sequence.
 *
 * This function executes a command specified by the 'comd' parameter.
 * It looks for the full path of the command using the 'fetchpath' function,
 * forks a child process to execute the command, and waits for the child's
 * completion. The function also handles errors and prints relevant messages.
 *
 * @comd: An array containing the command and its arguments.
 * @argv: An array containing the program name and its arguments.
 * @idx: The index representing the command's position in input sequence.
 *
 * Return: The exit status of the executed command.
 */
int	carryout(char **comd, char **argv, int idx)
{
	 char *full_cmd;
	pid_t child;
	int statusFlag;

	full_cmd = fetchpath(comd[0]);
	if (!full_cmd)
	{
		printerror(argv[0], comd[0], idx);
		freearv(comd);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, comd, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			freearv(comd);
		}
	}
	else
	{
		waitpid(child, &statusFlag, 0);
		freearv(comd);
		 free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(statusFlag));
}
