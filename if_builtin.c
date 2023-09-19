#include "main.h"

/**
* if_builtin - returns 1 for an inbuilt function
* @s: The character to print
*
* Return: On success 0.
* On error, -1 is returned, and errno is set appropriately.
*/

int if_builtin(char *s)
{
	char *built_in[] = {"cd", "exit", "env", "setenv", "unsetenv"};
	int i, len = sizeof(built_in) / sizeof(built_in[0]);

	if (s == NULL)
		return (-1);

	for (i = 0; i < len; i++)
	{
		if (_strcmp(s, built_in[i]) == 0)
		{
			return (0);
		}
	}
	return (1);
}
