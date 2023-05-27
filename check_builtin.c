#include "main.h"
/**
 * check_builtin - execute command if the command is a built-in function
 * @command: command to check
 * @status: number of executions
 * @buf: user input
 * Return:  0  Succes 1 fail
 */
int check_builtin(char **command, int status, char **buf)
{
	if (_strncmp(command[0], "exit", 4) == 0)
	{
		exit_myshell(command, status, buf);
		return (0);
	}
	if (_strncmp(command[0], "env", 3) == 0)
	{
		display_environ(environ);
		return (0);
	}
	if (_strncmp(command[0], "cd", 2) == 0)
	{
		change_dir(command);
		return (0);
	}
	if (_strncmp(command[0], "alias", 5) == 0)
	{
		display_alias();
		return (0);
	}
	else
	{
		return (1);
	}
}
/**
 * exit_myshell - exits the shell
 * @command: the pointer to tokenized command
 * @status: number of executions
 * @buf: input
 * Return: void
 */
void exit_myshell(char **command, int status, char **buf)
{
	int status_exit;

	status_exit = 0;
	if (command[1] == NULL)
	{
		free(*buf);
		exit(status);
	}
	else
	{
		status_exit = atoi(command[1]);
		free(*buf);
		exit(status_exit);
	}
}
