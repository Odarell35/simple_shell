#include "main.h"
  /**
 * check_builtin - Function to check if the command is a built-in command
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
	
		exit(EXIT_SUCCESS);
	}
	status_exit = to_int(command[1]);
	exit(status_exit);
}
/**
 * change_dir - change the current working directory
 * @command: parsed command argument
 * Return: 0 on success, -1 on failure
 */
int change_dir(char **command)
{

	char current_wd[BUFFER_SIZE];

	if (command[1] == NULL)
	{
		/* if no path is given, go to the home directory */
		chdir(_getenv("HOME"));
	}
	if (_strcmp(command[1], "-") == 0)
	{
		/* if "-" is given, go to the previous directory */
		chdir(_getenv("OLDPWD"));
	}
		/* otherwise, use the given path */
	if (chdir(command[1]) == -1)
	{
		/* try to change the directory */
		perror("chdir");
		return (-1);
	}
	/* update the PWD and OLDPWD environment variables */
	if (getcwd(current_wd, sizeof(current_wd)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	if (setenv("OLDPWD", _getenv("PWD"), 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	if (setenv("PWD", current_wd, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}
