#include "shell.h"

/**
 * carryOut - Executes a command with arguments.
 * @comd: Array containing the command and its arguments.
 * @argv: Array of strings representing the program's command-line arguments.
 *
 * Return: The exit status of the executed command.
 */
int	carryOut(char **comd, char **argv)
{
	pid_t child;
	int statusFlag;

	child = fork();
	if (child == 0)
	{
		if (execve(comd[0], comd, environ) == -1)
		{
			perror(argv[0]);
			freearv(comd);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &statusFlag, 0);
		freearv(comd);
	}
	return (WEXITSTATUS(statusFlag));
}
