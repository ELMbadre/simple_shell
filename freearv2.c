#include "shell.h"

/**
 * isNonNegative - Check if a string represents a non-negative integer.
 * @str: The string to be checked.
 *
 * This function verifies whether the given string 'str' contains only numeric
 * characters and represents a non-negative integer.
 *
 * @str: The string to be checked.
 *
 * Return: 1 if 'str' is a non-negative integer, 0 otherwise.
 */
int isNonNegative(char *str)
{
	int  n;

	if (!str)
		return (0);
	for (n = 0; str[n]; n++)
	{
		if (str[n] < '0' || str[n] > '9')
			return (0);
	}
	return (1);
}

/**
 * cast_atoi - Convert a string to an integer.
 * @str: The string to be converted.
 *
 * This function converts the string 'str' to an integer using the atoi
 * algorithm. It assumes that 'str' contains a valid numeric representation.
 *
 * @str: The string to be converted.
 *
 * Return: The integer representation of 'str'.
 */
int	cast_atoi(char *str)
{
	int n, num = 0;

	for (n = 0; str[n]; n++)
	{
		num *= 10;
		num += (str[n] - '0');
	}
	return (num);
}
