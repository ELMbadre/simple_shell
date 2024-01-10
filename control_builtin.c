#include "shell.h"

/**
 * check_builtin - Check if a command is a built-in shell command.
 * @cmd: The command to be checked.
 *
 * This function checks if the given command 'cmd' is a built-in shell command.
 * It compares 'cmd' with a list of known built-in commands.
 *
 * @cmd: The command to be checked.
 *
 * Return: 1 if 'cmd' is a built-in command, 0 otherwise.
 */
int check_builtin(char *cmd)
{
	char *builtins[] = {
		"exit", "env", "setenv", "cd", NULL
	};
	int n;

	for (n = 0; builtins[n]; n++)
	{
		if (_strcmp(cmd, builtins[n]) == 0)
			return (1);
	}
	return (0);
}

/**
 * executebuiltin - Execute a built-in shell command.
 * @cmd: The command to be executed.
 * @arv: The argument vector.
 * @stateInfo: Pointer to the shell state information.
 * @idx: Index of the command.
 *
 * This function executes a built-in shell command based on the provided 'cmd'.
 * It handles specific actions for exit and env commands.
 *
 * @cmd: The command to be executed.
 * @arv: The argument vector.
 * @stateInfo: Pointer to the shell state information.
 * @idx: Index of the command.
 */
void	executebuiltin(char **cmd, char **arv, int *stateInfo, int idx)
{
	if (_strcmp(cmd[0], "exit") == 0)
		closeShell(cmd, arv, stateInfo, idx);

	else if (_strcmp(cmd[0], "env") == 0)
		displayenv(cmd, stateInfo);
}

/**
 * closeShell - Close the shell based on the exit command.
 * @cmd: The command to be executed.
 * @arv: The argument vector.
 * @stateInfo: Pointer to the shell state information.
 * @idx: Index of the command.
 *
 * This function handles the exit command, closing the shell with an optional
 * exit value specified as an argument to the exit command.
 *
 * @cmd: The command to be executed.
 * @arv: The argument vector.
 * @stateInfo: Pointer to the shell state information.
 * @idx: Index of the command.
 */
void	closeShell(char **cmd, char **arv, int *stateInfo, int idx)
{
	int exit_value = (*stateInfo);
	char *index, mssg[] = ": exit: illegal number: ";

	if (cmd[1])
	{
		if (isNonNegative(cmd[1]))
		{
			exit_value = cast_atoi(cmd[1]);
		}
		else
		{
			index = _itoa(idx);
			write(STDERR_FILENO, arv[0], strlen(arv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, strlen(index));
			write(STDERR_FILENO, mssg, strlen(mssg));
			write(STDERR_FILENO, cmd[1], strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index);
			freearv(cmd);
			(*stateInfo) = 2;
			return;
		}
	}
	freearv(cmd);
	exit(exit_value);
}

/**
 * displayenv - Display the environment variables.
 * @cmd: The command to be executed.
 * @stateInfo: Pointer to the shell state information.
 *
 * This function displays the environment variables when the 'env' command
 * is executed.
 *
 * @cmd: The command to be executed.
 * @stateInfo: Pointer to the shell state information.
 */
void	displayenv(char **cmd, int *stateInfo)
{
	int i;
	(void) stateInfo;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearv(cmd);
	(*stateInfo) = 0;
}
