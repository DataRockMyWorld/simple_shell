#include "main.h"

/**
 * fork_process - initiates the processes in a shell
 * @args: The string to initiate
 * @argv: Array of command line arguments
 * @fullcmd: Full command
 * Return: On success 1.
 * On error, 0 is returned, and errno is set appropriately.
 */

int fork_process(char **args, char **argv, char *fullcmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror(fullcmd);
		exit(-1);
	}
	else if (pid == 0)
	{
		execve(fullcmd, argv, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		errno = status;

		free(fullcmd);
		free(args);
	}
	return (status);
}


/**
* fork_direct - Executes the command
* @args: An array of user arguments
* @argv: Array of command line arguments
*
* Return: Void
*/

int fork_direct(char **argv, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid == 0)
	{
		execve(argv[0], argv, environ);
		perror(args[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);

		errno = status;
		free(argv);
	}

	return (status);
}
