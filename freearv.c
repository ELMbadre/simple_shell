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
/**
 * printerror - Print an error message for a command not found.
 * @name: The name of the program.
 * @cmd: The command that was not found.
 * @idx: The index or line number where the error occurred.
 *
 * This function prints an error message to the standard error (stderr)
 * indicating that a command was not found. It includes the program name,
 * the index or line number, the command, and a standard error message.
 *
 * Example output: "program_name: idx: cmd: not found\n"
 *
 * @name: Program name or identifier.
 * @cmd: Command that was not found.
 * @idx: Index or line number where the error occurred.
 */
void	printerror(char *name, char *cmd, int idx)
{
	char *indx, mssg[] = ": not found\n";

	indx = _itoa(idx);

	write(STDERR_FILENO, name, strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, indx, strlen(indx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, mssg, strlen(mssg));
	free(indx);
}
/**
 * _itoa - Convert an integer to a string.
 * @n: The integer to be converted.
 *
 * This function takes an integer as input and converts it into a string.
 * The resulting string is dynamically allocated and should be freed by the
 * caller when no longer needed.
 *
 * @n: Integer value to be converted.
 *
 * Return: A dynamically allocated string representing the integer.
 */
char	*_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));
}
/**
 * reverse_string - Reverse the characters in a string.
 * @str: The string to be reversed.
 * @len: The length of the string.
 *
 * This function reverses the characters in a given string in-place.
 *
 * @str: The string to be reversed.
 * @len: The length of the string.
 */
void	reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
