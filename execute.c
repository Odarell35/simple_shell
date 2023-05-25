#include "main.h"
/**
 *
 *
 */
int execute(char *command, char **second_command)
{
	int status = 0;
	pid_t pid;
	

	if(access(command, X_OK) == 0)
	{
		pid = fork();
		if(pid == -1)
		{
			perror(command);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			if((execve(command, second_command, environ)) == -1)
			{
				perror(command);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	else
		look_path(command, second_command);
return (-1);
}
