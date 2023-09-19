#include "main.h"

/**
 * check_null - stores a string from standard input into a buffer
 * @cwd: The character to print
 * @cur_dir: Second Argument
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int check_null(char *cwd, char *cur_dir)
{
	cwd[0] = '\0';
	cur_dir[0] = '\0';

	strcpy(cwd, getenv("PWD"));

	if (chdir(cwd) == -1)
	{
		perror("cd");
	}
	return (1);
}

/**
* check_dash - stores a string from standard input into a buffer
* @mid: The character to print
* @temp: Argument 5
* @cur_dir: Argument 3
* @prev_dir: Argument 4
* @cwd: Argument 3
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int check_dash(char *mid, char *temp, char *cur_dir, char *prev_dir, char *cwd)
{
	_strcpy(mid, cur_dir);
	_strcpy(cur_dir, temp);

	(void)mid;
	(void)temp;
	(void)cur_dir;
	(void)cwd;

	if (chdir(prev_dir) == -1)
	{
		perror("cd");
	}
	else
	{
		prev_dir[0] = '\0';
		_strcpy(prev_dir, cwd);
		_strcpy(temp, mid);
	}
	return (1);
}

/**
* _getline - stores a string from standard input into a buffer
* @dr: The character to print
* @en: The character to print
* @arg: The character to print
* @out: The character to print
* @temp: The character to print
* @cur_dir: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

void check_dir(DIR *dr, struct dirent *en,
	       char *arg, char *out, char *temp, char *cur_dir)
{
	while ((en = readdir(dr)) != NULL)
	{
		if (_strcmp(arg, en->d_name) == 0)
		{
			_strcat(out, arg);
			_strcpy(temp, cur_dir);
			_strcat(cur_dir, out);
			break;
		}
	}
	closedir(dr);
}
