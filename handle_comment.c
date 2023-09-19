#include "main.h"

/**
 * handle_comments - Checks if the string is a comment
 * @buf: The string to check and fix a null byte at point of #
 * Return: Void
 */

void handle_comments(char *buf)
{

	int j = 0;

	for (; buf[j]; j++)
	{

		if (j > 0 && buf[j] == '#' && buf[j - 1] != ' ')
			break;

		if (buf[j] == '#')
		{
			buf[j] = '\0';
			break;
		}
	}
}
