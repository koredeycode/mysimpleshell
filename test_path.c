#include "shell.h"

/**
 * append - append str2 to the back of str1
 * @str1: the string to be appended
 * @str2: the appended string
 * Return: the appended string whole
 */
char *append(char *str1, char *str2)
{
	char *buf;
	size_t i = 0, j = 0;

	if (str1 == NULL)
		str1 = "";
	if (str2 == NULL)
		str2 = "";
	buf = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 2));
	if (!buf)
		return (NULL);
	while (str1[i])
	{
		buf[i] = str1[i];
		i++;
	}
	if (str1[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
	while (str2[j])
	{
		buf[i + j] = str2[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}
/**
 * test_path - check if paths with cmd exist
 * @paths: the paths variables
 * @cmd: the command
 * Return: return the correct path or null
 */
char *test_path(char **paths, char *cmd)
{
	int i = 0;
	char *ret = NULL;

	while (paths[i])
	{
		ret = append(paths[i], cmd);
		if (access(ret, F_OK & X_OK) == 0)
			return (ret);
	/*	free(ret);*/
		i++;
	}
	return (NULL);
}
