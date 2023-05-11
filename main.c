#include "main.h"

int main(void)
{
	ssize_t n;
	int i;
	size_t buf_size;
	char *buf, *token;

	buf_size = BUFFER_SIZE;
	n = 0;
	char arg[10][100];
	buf = malloc(sizeof(char) * buf_size);
	prompt_user();
	n = getline(&buf, &buf_size, stdin);
	write(STDOUT_FILENO, buf, n);
	token = strtok(buf, " ");
		i = 0;
		while (token != NULL && i < 10)
		{
		strcpy(arg[i],token);
		i++;
			token = strtok(NULL, " ");
		
		}
		for (i = 0; i < 10; i++)
		{
			write(STDOUT_FILENO, arg[i], _strlen(arg[i]));
		}
	free(buf);
	free(token);
	return (0);
}
