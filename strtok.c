#include "main.h"

/**
 * *_strtok - writs the character c to stdout
 * @str: The character to print
 * @delim: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

char *_strtok(char *str, const char *delim)
{
	char *begin;
	static char *next;

	if (str == NULL && next == NULL)
		return (NULL);
	if (str == NULL)
		str = next;
	str = str + strspn(str, delim);

	if (*str == '\0')
	{
		next = NULL;
		return (NULL);
	}
	begin = str;

	str = str + strcspn(str, delim);

	if (*str != '\0')
	{
		*str = '\0';
		next = str + 1;
	}
	else
	{
		next = NULL;
	}
	return (begin);
}
