#include "main.h"
/**
 * count - will count the number of arguments
 * @token: tokenized string
 * @buff: holds tokenized string
 * Return: argc or 1 failure
 */
int count(char *token, char *buff)
{
	int j, argc;
	char *delim;

	delim = " ";
	argc = 0;
	token = strtok(buff, delim);
	for (j = 0; token != NULL; j++)
	{
		argc++;
		token = strtok(NULL, delim);
	}
	return (argc);
}
