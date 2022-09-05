#include "shell.h"
/**
 * print_prompt - print the prompt for the user
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO) == 1 && (isatty(STDOUT_FILENO) == 1))
		write(STDERR_FILENO, "$ ", 2);
}
