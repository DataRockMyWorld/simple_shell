
#include "main.h"

/**
 * exit_error - Checks error on parsed commandt
 * @argv: Argument counter
 * @args: Argument Vector
 * @tally: integer
 * @errmsg: string
 *
 * Return: Errno
 */
int exit_error(char **argv, char **args, int tally, char *errmsg)
{
	char cv;

	cv = (tally + '0');
	exiterr_cmd(argv[0], argv[1], cv, args[0], errmsg);
	errno = 2;
	free(argv);
	return (errno);
}
