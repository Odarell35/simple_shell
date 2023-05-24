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
	int i, status;
	pid_t pid;
	size_t buf_size;
	char *buf, *token, *delim, *buff;

	if (args[1] != NULL)
	read_file(args[1]);
	signal(SIGINT, handle_signal);
	while (1)
{
	buf_size = argc  = 0;
	delim = " ";
	buf = NULL;
	prompt_user();
	buff = read_command(buf, buf_size);
	argc = count(token, buff);
	hashtag(buff);
	token = strtok(buff, delim);
	args = malloc(sizeof(char *) * (argc + 1));
	for (i = 0; token != NULL; i++)
	{
		args[i] = token;
		token = strtok(NULL, delim);
	}
	args[i] = NULL;
	if (check_builtin(args) == 0)
	continue;
	pid = fork();
	if (pid == 0)
	execve(args[0], args, envp);
	else
	wait(&status);
	free(args);
	free(buff);
	free(token);
}
return (0);
}
