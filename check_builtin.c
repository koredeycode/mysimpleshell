#include "shell.h"

/**
 * check_builtin - check if command is a builtin command
 * @command: the arrays of command
 * @line: the return from getline
 * Return: return an integer
 */
int check_builtin(char **command, char *line)
{
	struct builtin built;

	built.env = "env";
	built.exit = "exit";
	built.cd = "cd";
	if (strcmp(*command, built.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (strcmp(*command, built.exit) == 0)
	{
		exit_cmd(command, line);
		return (1);
	}
	else if (strcmp(*command, built.cd) == 0)
	{
		_cd(*command);
		return (1);
	}
	return (0);
}
