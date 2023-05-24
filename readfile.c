#include "main.h"
/**
 * read_file- reads commands from file
 *@filename: file
 *Return: void
 */
void read_file(char *filename)
{
	char *buf_file, *file_token, *delim, **args_from_file;
	int i, fd, status, argc;
	pid_t pid;
	ssize_t nread_file;
	size_t size_file;

	buf_file = NULL;
	argc = size_file = 0;
	delim = " ";
	fd = open(filename, O_RDONLY);
	nread_file = getline(&buf_file, &size_file, fdopen(fd, O_RDONLY));
	if (nread_file == -1)
	{
		_putchar('\n');
		free(buf_file);
		close(fd);
		exit(EXIT_SUCCESS);
	}
	if (buf_file[nread_file - 1] == '\n')
	{
		buf_file[nread_file - 1] = '\0';
	}
	file_token = NULL;
	argc = count(file_token, buf_file);
	hashtag(buf_file);
	file_token = strtok(buf_file, delim);
	args_from_file = malloc(sizeof(char *) * (argc + 1));
	for (i = 0; file_token != NULL; i++)
	{
		args_from_file[i] = file_token;
		file_token = strtok(NULL, delim);
	}
	args_from_file[i] = NULL;
	pid = fork();
	if (pid == 0)
	execve(args_from_file[0], args_from_file, environ);
	else
	wait(&status);
	free(buf_file);
	close(fd);
}
