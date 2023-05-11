#include "main.h"

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
/*	char arg[10][100];*/
	buf = malloc(sizeof(char) * buf_size);
	str = malloc(sizeof (char) * buf_size);
	prompt_user();
	n = getline(&buf, &buf_size, stdin);
	write(STDOUT_FILENO, buf, n);
	strcpy(str, buf);
	token = strtok(str, delim);
	i = 0;
		while (token && i < 10)
		{
			/*printf("%s\n",token);*/
			args[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		for (k = 0; k < _strlen(*args); k++)
		{
			printf("%s\n", args[k]);
		}
			/*for (j = 0, i = 0; args[i] != NULL; j++, i++)
			{
			write(1, args[i], _strlen(args[i]));
			}
			strcpy(arg[i], token);
			token = strtok(NULL, " ");*/
		
		
		/*for (j = 0; j < i; j++)
		{
			write(STDOUT_FILENO, arg[i], _strlen(arg[i]));
		}*/
	free(buf);
	free(token);
	free(str);
	return (0);
}
