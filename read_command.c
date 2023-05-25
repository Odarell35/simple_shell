#include "main.h"
/**
 * read_command - read command from stdin
 * @buf: buffer holding command line
 * @buf_size: size of buffer
 *Return: buf
 */
char *read_command(char  *buf, size_t buf_size)
{
	ssize_t n;

	buf_size = 0;
	n = 0;
	buf = NULL;
	n = getline(&buf, &buf_size, stdin);
	if (n == -1)
	{
		_putchar('\n');
		free(buf);
		exit(EXIT_SUCCESS);
	}
return (buf);
}
