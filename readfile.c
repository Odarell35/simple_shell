#include "main.h"
/**
 * read_file- reads commands from file
 *@filename: file
 *Return: void
 */
void read_file(char *filename)
{
	char *buf_file, *file_token, *delim, **args_from_file;
	int i, fd, j, status, argc;
	pid_t pid;
	ssize_t nread_file, exe;
	size_t size_file;

	buf_file = NULL;
	argc = size_file = 0;
	delim = " ";
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("file not open");
	}
	nread_file = getline(&buf_file, &size_file, fdopen(fd O_RDONLY));
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
	file_token = strtok(buf_file, delim);
	for (j = 0; file_token != NULL; j++)
	{
		argc++;
		file_token = strtok(NULL, delim);
	}
	hashtag(buf_file);
	file_token = strtok(buf_file, delim);
	args_from_file = malloc(sizeof(char *) * (argc + 1));
	i = 0;
	while (file_token)
	{
		args_from_file[i] = file_token;
		file_token = strtok(NULL, delim);
		i++;
	}
	args_from_file[i] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("pid failed");
	}
	if (pid == 0)
	{
		exe = execve(args_from_file[0], args_from_file, environ);
		if (exe == -1)
		{
			perror("Error file not found");
			free_arr(args_from_file);
			free(buf_file);
			free(file_token);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	free(buf_file);
	close(fd);
}
