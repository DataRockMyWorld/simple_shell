#include "main.h"

/**
 * set_func - set environment
 * @arg: argument
 *
 * Return: 1 on success
 */

int set_func(char **arg)
{
	size_t len = strlen(arg[1]) + strlen(arg[2]) + 2;
	char *var = (char *)malloc(len);
	int result = putenv(var);

	if (getenv(arg[1]) != NULL && arg[3] == 0)
	{
		return (1);
	}

	if (var == NULL)
	{
		perror("Memory allocation error");
		return (-1);
	}
	strcpy(var, arg[1]);
	strcat(var, "=");
	strcat(var, arg[2]);

	if (result != 0)
	{
		perror("putenv error");
		free(var);
		return (-1);
	}
return (1);
}
