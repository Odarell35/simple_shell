#include "main.h"
ssize_t _getline(char **buf, size_t *buf_size, int status)
{
	ssize_t buff;

	buff = getline(buf, buf_size, stdin);
	if (buff == -1)
	{
		free(*buf);
		exit(status);
	}
	return (buff);
}
