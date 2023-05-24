#include "main.h"
/**
 * call_for_execute - executes command
 * @args: array of commands
 * @envp: cureent environment
 * Return; void
 */
void call_for_execute(char **args, char **envp)
{
	int status;
	pid_t pid;
	ssize_t exe;

	status = 0;

	pid = fork();
	if (pid == -1)
	perror("fork failed");
	if (pid == 0)
	{
		exe = execve(args[0], args, envp);
		if (exe == -1)
		{
			perror("./hsh: not found");
			free_arr(args);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
