#include "shell.h"

/**
 * print_env - builtin that print the environment variable
 */
void print_env(void)
{
	int i;
	char **ennv = environ;

	for (i = 0; ennv[i] != NULL; i++)
	{
		printf("%s\n", ennv[i]);
	}
}

/**
 * exit_cmd - implement the exit command
 * @commands: the commands
 * @str: the to be freed
 */
void exit_cmd(char **commands, char *str)
{
	free(str);
	freebuffs(commands);
	exit(0);
}

/**
 * _cd - implement the change directory command
 * @str: the directory to change to
 * Return: an interger 0 or 1
 */
int _cd(char *str)
{
	if (str == NULL)
	{
		fprintf(stderr, "Argument expected after \"cd\"\n");
		return (0);
	}
	else
	{
		if (chdir(str) != 0)
			perror("Error");
	}
	return (1);
}
