#include "shell.h"

/**
 * main - the entry point for the program
 * @argc: argument count
 * @argv: argument vectors
 * @envp: the environment variables
 * Return: an integer
 */
int main(int argc, char *argv[], char *envp[])
{
	char **commands = NULL, **paths = NULL;
	char *path = NULL, *line = NULL, *expath = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;

	envp = envp;
	if (argc < 1)
		return (-1);
	while (1)
	{
		print_prompt();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		commands = tokenizer(line);
		if (commands == NULL || *commands == NULL || **commands == '\0')
			continue;
		if (checker(commands, line, argv[0]))
			continue;
		path = find_path();
		paths = tokenizer(path);
		expath = test_path(paths, commands[0]);
		if (!expath)
		{
			perror(argv[0]);
			continue;
		}
		else
			execute(expath, commands);
	}
	if (linesize < 0)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
