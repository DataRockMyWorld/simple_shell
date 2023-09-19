#include "main.h"

/**
 * _cd - changes the directory
 * @argv: argument
 * @args: argument
 * @tally: sum of iterations
 *
 * Return: 1 on success
 */

int _cd(char **argv, char **args, int tally)
{
	char *con = NULL;
	size_t size = 0;
	char *old_pwd = getenv("OLDPWD"), errmsg[] = "can't cd to ";

	if (argv[1] != NULL)
	{
		if (argv[1][0] == '-')
		{
			chdir(old_pwd);
		}
		else if (chdir(argv[1]) == -1)
		{
			exit_error(argv, args, tally, errmsg);
		}
		return (1);
	}
	if (chdir(getcwd(con, size)) == -1)
	{
		exit_error(argv, args, tally, errmsg);
		free(argv);
		free(con);
		return (1);
	}
	free(argv);
	free(con);
	return (1);
}
