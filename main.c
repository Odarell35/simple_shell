#include "main.h"
/**
 * main - main file for all main ececution files
 * Return: 0
 */
int main(void)
{
	ssize_t n;
	char *str;
	int i, k;
	size_t buf_size;
	char *buf, *token, *delim;
	char *args[10];


	buf_size = BUFFER_SIZE;
	n = 0;
	delim = " ";
	buf = malloc(sizeof(char) * buf_size);
	str = malloc(sizeof (char) * buf_size);
	prompt_user();
	n = getline(&buf, &buf_size, stdin);
	write(STDOUT_FILENO, buf, n);
	_strcpy(str, buf);
	token = strtok(str, delim);
	i = 0;
		while (token && i < 10)
		{
			args[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		for (k = 0; k < _strlen(*args); k++)
		{
			printf("%s\n", args[k]);
		/*	write(STDOUT_FILENO, args[k], _strlen(args[k]));*/
		}
		
	free(buf);
	free(token);
	free(str);
	return (0);
}
