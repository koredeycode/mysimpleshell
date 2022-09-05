#include "shell.h"
/**
 * checker - check the command
 * @cmd: the command arrays to check
 * @buf: buffer string
 * Return: an integer
 */
int checker(char **cmd, char *buf, char *arg)
{
	int i = 0;
	char *a, *str;

	str = cmd[0];
	a = malloc(sizeof(char) * 1024);
	if (check_builtin(cmd, buf))
		return (1);
	else if (str[0] == '.' && str[1] == '/')
	{
		while (*str && i < 2)
		{
			str++;
			i++;
		}
		a = getcwd(a, 1024);
		a = append(a, str);
		execute(a, cmd);
		return (1);
	}
	else if (**cmd == '/')
	{
		if (access(*cmd, F_OK & X_OK) == 0)
		{
			execute(cmd[0], cmd);
			return (1);
		}
		else
		{
			perror(arg);
			return (1);
		}
	}
	return (0);
}
