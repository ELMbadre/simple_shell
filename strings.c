#include "shell.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string to be duplicated.
 *
 * Return: A pointer to the duplicated string on success, or NULL on failure.
 */
char	*_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str -= len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int	_strcmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)(*s1) - (int)(*s2);
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)(*s1) - (int)(*s2);
	}
	return (cmp);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string to be concatenated.
 *
 * Return: A pointer to the concatenated string (dest) on success.
 */
char	*_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}

/**
 * _strcpy - Copies a string.
 * @dest: The destination string.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination string (dest) on success.
 */
char	*_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
