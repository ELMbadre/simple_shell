#include "shell.h"

/**
 * carryOut - Execute a command and wait for its completion.
 * @comd: An array of strings representing the command and its arguments.
 * @argv: An array of strings representing theprogram's command-linearguments.
 *
 * This function forks a child process, executes the specified command using
 * execve, and waits for the child process to complete. It returns the exit
 * status of the child process.
 *
 * Return: The exit status of the child process.
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
