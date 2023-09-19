#include "main.h"

/**
 * fex - executes builtins
 * @argv: argument
 * @args: argument
 * @buffer: buffer
 * @env: environment variable
 *
 * Return: 1 on success
 */
int fex(char **argv, char **args, char *buffer, char **env)
{
	int i = 0, c = 0, d = 0, rev_value = 0, tally = 1;
	char errmesg[] = "Illegal number: ";

	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
		{
		i = _atoi(argv[1]);
		if ((i == 0 && (_strcmp(argv[1], "0") != 0)) || i < 0)
			exit(exit_error(argv, args, tally, errmesg));
		free(argv);
		free(buffer);
		exit(i);
		}
		free(argv);
		free(buffer);
		exit(errno);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		while (env[c])
		{
			while (env[c][d])
			{
				write(1, &env[c][d], 1);
				d++;
			}
			d = 0;
			c++;
			write(1, "\n", 1);
		}
		free(argv);
		rev_value = 1;
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		if (_cd(argv, args, tally) == 1)
			rev_value = 1;
	}
return (rev_value);
}
