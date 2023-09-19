#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <dirent.h>
#include <stdbool.h>
#include <errno.h>

extern char **environ;
int parse_error(char **argv, char **args, int tally);
int exit_error(char **argv, char **args, int tally, char *errmsg);
char **split_input(char *s);
int fexecute(char **argv);
int env_func(char **arg);
int cd_func(char **arg);
int exit_func(char **argv);
void exec_cmd(char **argv);
char *handle_path(char *comnd);
void handle_comments(char *buf);

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *c);
char *_strdup(char *s);
char *_strtok(char *str, const char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *file);
char *_getenv(const char *name);
int set_func(char **args);
int unset_func(char **args);
int if_builtin(char *s);
void check_dir(DIR *dr, struct dirent *en, char *arg, char *out,
	       char *temp, char *cur_dir);
int check_dash(char *mid, char *temp,
	       char *cur_dir, char *prev_dir, char *cwd);
int check_null(char *cwd, char *cur_dir);
char **str_tok(char *str, char d);
int _strncmp(const char *s1, const char *s2, size_t n);
int _putchar(char c);
void error_command(char *prog, int count, char *cmd);
void exiterr_cmd(char *prog, char *prog1, int count, char *cmd, char *errmsg);
void put_string(char *str);
void free_array(int argc, char *argv[]);
int fork_process(char **args, char **argv, char *final_cmd);
int fork_direct(char **args, char **argv);
char *_strchr(char *s, char c);
char *get_parsed_path(char *paths, char *cmd);
char *find_path(void);
int _atoi(char *);
char **tokenize_path(char *paths, int *num_tokens);
int fex(char **, char **, char *, char **);
int _cd(char **, char **, int tally);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
