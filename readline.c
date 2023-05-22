#include "main.h"
/**
 * prompt_user - show the prompt ($)
 * Return: nothing
 */
void prompt_user(void)
{
	char *buf;

	buf = "$ ";
	write(STDOUT_FILENO, buf, _strlen(buf));
}

