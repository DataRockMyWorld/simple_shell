#include "main.h"
/**
 * main - Simple shell entry point
 * @argc: Argument counter
 * @args: Argument Vector parsed_cmd = get_parsed_path(find_path(), argv[0]);
 * @env: environment variable
 * Return: Errno
 *
 */
int main(int __attribute__((unused)) argc, char **args, char **env)
{
	char *buffer = NULL, **argv = NULL, *parsed_cmd = NULL;
	size_t buff_len = 0;
	ssize_t num = 0;
	int in_option = isatty(0), tally = 0;

	errno = 0;
	while (1)
	{
		tally++;
		if (in_option == 1)
			write(1, "$ ", 2);
		num = getline(&buffer, &buff_len, stdin);
		if (num == -1)
		{
			free(buffer);
			exit(errno);
		}
		handle_comments(buffer);
		argv = split_input(buffer);
		if (argv[0] == NULL)
		{
			free(argv);
			continue;
		}
		if (fex(argv, args, buffer, env) == 1)
			continue;
		if (access(argv[0], X_OK) == -1)
		{
			parsed_cmd = handle_path(argv[0]);
			if (parsed_cmd == NULL)
			{
				parse_error(argv, args, tally);
				continue;
			}
			fork_process(argv, args, parsed_cmd);
			continue;
		}
		fork_direct(argv, args);
	}
	return (errno);
}
