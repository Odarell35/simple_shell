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

/**
 * my_getline - reads an entire line from stdin
 * @lineptr: address of buffer
 * @n: size of buffer
 * @stream: a line from stdin
 * Return: string from stdin
 */
char *my_getline(void)
{
	ssize_t nread;
	int buf_size;
	char *buf, *new_buf;
	
	buf_size = BUFFER_SIZE;
	buf = malloc(sizeof(char) * buf_size);
	if (buf == NULL);
	{
		free(buf);
		exit(EXIT_SUCCESS);
	}

	while (buf != EOF && != '\n')
	{
		nread = read(STDIN_FILENO, &buf, buf_size);
		if (nread == 0)
		{
			free(buf);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(buf)
				exit(EXIT_FAILURE);
		}/*END HERE*/


	stream = stdin;
	n = _strlen(stream);
	lineptr = &buf;

	while (stream != NULL)
	{
		buf = malloc(sizeof(char) * n);
		buf = stream;
	}
	return (buf);
}
