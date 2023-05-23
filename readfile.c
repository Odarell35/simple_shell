#include "main.h"
/**
 * readfile- reads commands from file
 *
 *
 */
int readfile()
{
	char *buf_file, *file_token;
	char **args_from_file;
	int i, fd;
	ssize_t nread_file;
	size_t size_file;

	buf_file = NULL;
	size_file = 0;
	buf-size = 0;
	fd = open(args[0], "r");
	if (fd == -1)
	{
		perror("file not open");
		return (NULL);
	}
	nread_file = getline(&buf_file, &buf_size, fd);
	if (nread_file == -1)
	{
		_putchar('\n');
		free(buf_file);
		close(fd);
		exit(EXIT_SUCCESS);
	}
	free(buf-file);
	close(fd);
	return (0);
}

