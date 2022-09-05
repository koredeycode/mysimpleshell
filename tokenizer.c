#include "shell.h"
/**
 * tokenizer - tokenize the inputted string
 * @line: the inputted string
 * Return: the strings array
 */
char **tokenizer(char *line)
{
	int toksize = 1;
	char *delims = " :\t\r\n", *token = NULL, *buf = NULL, *buftmp = NULL;
	char **tokens = NULL;
	size_t index = 0, mark = 0, i = 0;

	buf = strdup(line);
	if (!buf)
		return (NULL);
	buftmp = buf;
	while (buftmp[i])
	{
		if (strchr(delims, buftmp[i]) != NULL && mark == 0)
		{
			toksize++;
			mark = 1;
		}
		else if (strchr(delims, buftmp[i]) == NULL && mark == 1)
			mark = 0;
		i++;
	}
	tokens = malloc(sizeof(char *) * (toksize + 1));
	token = strtok(buf, delims);
	while (token)
	{
		tokens[index] = strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delims);
		index++;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
}
