#include "main.h"
/**
 * main - main file for all main ececution files
 * Return: 0
 */
int main(void)
{
	ssize_t n;
	size_t buf_size;
	char *buf;

	buf_size = BUFFER_SIZE;
	n = 0;
	buf = malloc(sizeof(char) * buf_size);
	prompt_user();
	n = getline(&buf, &buf_size, stdin);
	write(STDOUT_FILENO, buf, n);
	free(buf);
	return (0);
}
