#include "shell.h"
/**
 * freebuffs - free the buffers
 * @buff: the buffers to be free
 */
void freebuffs(char **buff)
{
	int i = 0;

	if (!buff || buff == NULL)
		return;
	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}
