#include "main.h"
/**
 * examine_command - execute command
 * @input: user input
 * @command: command to be passed
 * @argv: argument to be executed
 * @sec: execution status
 * Return: 0 on sucess
 */

int examine_command(char *input, char **command,char argv, int sec)
{
	pid_t pid;
	int status;

	if (*command == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("pid not found");
		return(-1);
	}

	if (pid == 0)
	{
		if (strncmp(*command, "./", 2) !=  0 && strncmp(*command, "./", 1) != 0)
		{
			look_path(*command);
		}

		if (execve(*command, command, environ) == 0)
		{
			return (EXIT_SUCCESS);
		}
		else
		{

			free(input);
			free(command);
			exit(EXIT_FAILURE);
		}
	}

	wait(&status);
}
