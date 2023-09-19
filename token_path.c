#include "main.h"

/**
* split_input - Tokenizes a string and returns
* a dynamically allocated array of strings
* @s: Buffer entered by user
* Return: Double pointer of the string
*/

char **split_input(char *s)
{
	char **toks = NULL;
	int num = 0;
	char *token = NULL, *delimiter = " \n";

	toks = malloc(sizeof(char *) * 25);
	if (toks == NULL)
		return (NULL);

	token = strtok(s, delimiter);

	while (token != NULL)
	{
		toks[num] = token;
		token = strtok(NULL, delimiter);
		num++;
	}

	toks[num] = NULL;
	return (toks);
}

/**
* find_path - Retrieves and duplicates the path
*
* Return: A strings of the PATH Variable
*/

char *find_path(void)
{
	int i;
	char *path = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
			path = strdup(environ[i]);
	}
	printf("successfuly printed path");

	return (path);
}


/**
* tokenize_path - returns a valid path else NULL
* @paths: A string of multiple directories in the path
* @num_tokens: Command string (Not an array)
* Return: A Pointer to full string or NULL
*/

char **tokenize_path(char *paths, int *num_tokens)
{
	char **path_tokens = NULL;
	char *tmp = NULL, *token = NULL;
	int x = 0;

	if (paths == NULL)
	{
		return (NULL);
	}

	tmp = strtok(paths, "=");
	tmp = strtok(NULL, "=");

	path_tokens = malloc(sizeof(char *) * 30);
	if (path_tokens == NULL)
	{
		return (NULL);
	}

	token = strtok(tmp, " ");

	while (token != NULL)
	{
		path_tokens[x] = token;
		token = strtok(NULL, ":");
		x++;
	}
	path_tokens[x] = NULL;
	*num_tokens = x;

	return (path_tokens);
}

/**
 * get_parsed_path - returns a valid path else NULL
 * @paths: A string of multiple directories in the path
 * @cmd: Command string (Not an array)
 * Return: A Pointer to full string or NULL
 */

char *get_parsed_path(char *paths, char *cmd)
{
	char *comp_path = NULL;
	int num_tokens = 0, index = 0;
	char **path_tokens = tokenize_path(paths, &num_tokens);
	size_t len = 0;

	if (paths == NULL)
		return (NULL);

	for (index = 0; index < num_tokens; index++)
	{
		len = _strlen(path_tokens[index]) + _strlen(cmd) + 2;
		comp_path = malloc(len);

		if (comp_path == NULL)
			continue;

		_strcpy(comp_path, path_tokens[index]);
		_strcat(comp_path, "/");
		_strcat(comp_path, cmd);

		if (access(comp_path, X_OK) == 0)
		{
			free(path_tokens);
			free(paths);
			return (comp_path);
		}
		free(comp_path);
		comp_path = NULL;
		index++;
	}

	free(path_tokens);
	free(paths);
	return (NULL);
}
