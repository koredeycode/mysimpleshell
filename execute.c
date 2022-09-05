#include "shell.h"
/**
 * execute - execute the command
 * @expath: the executing path to the command
 * @commands: the arguments to the command
 */

void execute(char *expath, char **commands)
{
	pid_t child;
	int status;
	char **ennv = environ;

	child = fork();
	if (child < 0)
		perror(expath);
	if (child == 0)
	{
		execve(expath, commands, ennv);
		perror(expath);
		free(expath);
		freebuffs(commands);
		exit(98);
	}
	else
		wait(&status);
}
