#include "main.h"
/**
 * display_error - prints error message 
 * @args: array of arguments
 * 
 * Return: void
 */
void display_error(char **args)
{
	int i;

	const void *buffer[] = {"argv[0]", ": not found\n", NULL};
	for (i = 0; i < 2; i++)
	{
		write(STDOUT_FILENO, buffer[i], _strlen(buffer[i]));
	}
}
