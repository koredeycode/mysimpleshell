#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

void print_env(void);
void exit_cmd(char **commands, char *str);
int _cd(char *str);
int check_builtin(char **command, char *line);
int checker(char **cmd, char *buf, char *arg);
void execute(char *expath, char **commands);
char *find_path(void);
void freebuffs(char **buff);
void print_prompt(void);
char *append(char *str1, char *str2);
char *test_path(char **paths, char *cmd);
char **tokenizer(char *line);

/**
 * Description - for the builtin commands
 * @builtin: contain the builtin commands
 * @env: the environment variable
 * @exit: for the exit command
 * @cd: for the change directory command
 */
struct builtin
{
	char *env;
	char *exit;
	char *cd;
};
#endif
