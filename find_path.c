#include "shell.h"
/**
 * find_path - find path variable from the environment
 * Return: the string to the beginnig of the path variable
 */

char *find_path(void)
{
	int i = 0;
	char **ennv = environ, *path = NULL;

	while (*ennv)
	{
		if (strncmp(*ennv, "PATH=", 5) == 0)
		{
			path = *ennv;
			while (*path && i < 5)
			{
				path++;
				i++;
			}
			return (path);
		}
		*ennv = *ennv + 1;
	}
	return (NULL);
}
