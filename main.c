#include "main.h"
/**
 * main - main file for all main execution files
 * @argc: argument count
 * @args: array of arguments
 * @envp: environment
 * Return: 0
 */
int main(int argc, char **args, char **envp)
{
	ssize_t exe;
	pid_t pid;
	int i, status, j, check;
	size_t buf_size;
	char *buf, *token, *delim, *buff;

	if (args[1] != NULL)
	{
		read_file(args[1]);
	}
	signal(SIGINT, handle_signal);
	while (1)
{
	buf_size = 0;
	argc  = 0;
	delim = " ";
	buf = NULL;
	if (isatty(STDIN_FILENO))
	prompt_user();
	buff = read_command(buf, buf_size);
	token = strtok(buff, delim);
	for (j = 0; token != NULL; j++)
	{
		argc++;
		token = strtok(NULL, delim);
	}
	hashtag(buff);
	token = strtok(buff, delim);
	args = malloc(sizeof(char *) * (argc + 1));
	i = 0;
	while (token)
	{
		args[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	check = check_builtin(args);
	if (check == 0)
	{
		continue;
	}
	pid = fork();
	if (pid == -1)
	return (-1);
	if (pid == 0)
	{
		exe = execve(args[0], args, envp);
		if (exe == -1)
		{
			perror("Error file not found");
			free_arr(args);
			free(buf);
			free(token);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	free(args);
	free(buff);
	free(token);
}
return (0);
}
