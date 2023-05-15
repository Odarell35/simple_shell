#include "main.h"

/**
 * handle_signal - handle signal
 * @n: signal
 * Return: nothing
 */
void handle_signal(int n)
{
	char *buf;

	buf = "\n$";
	if (n == SIGINT)
	{
		write(STDOUT_FILENO, buf, _strlen(buf));
	}
}
/**
 * hashtag - removes anything after # sign
 * @str: string
 * Return: nothing (# only)
 */
void hashtag(char *str)
{
	int index;

	index = 0;
	while(str[index] != '\0')
	{
		if (str[index] == 35)
		{
			str[index] = '\0';
		}
		index++;
	}
}
