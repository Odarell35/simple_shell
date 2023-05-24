#include "main.h"
/**
 * check_builtin - execute command if the command is a built-in function
 * @command: command to check
 * Return:  0  Succes 1 fail
 */
int check_builtin(char **command)
{
	if (_strncmp(command[0], "exit", 4) == 0)
	{
		exit_myshell(command);
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
 * Return: void
 */
void exit_myshell(char **command)
{
	int status_exit;

	status_exit = 0;
	if (command[1] == NULL)
	{
		free_arr(command);
		exit(EXIT_SUCCESS);
	}
	status_exit = atoi(command[1]);
	free_arr(command);
	exit(status_exit);
}
