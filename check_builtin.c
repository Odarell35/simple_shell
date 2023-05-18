#include "main.h"
  /**
 * check_builtin - Function to check if the command is a built-in command
 * @command: command to check
 * Return: 1 succes 0 fail
 */
void check_builtin(char *command)
{
	 if (_strncmp(command, "exit", 4) == 0)
	 {
		 exit_myshell(args);
        }
	 if (_strncmp(command, "env", 3) == 0)
	 {
		 display_environ(environ);
	 }
	 if (_strncmp(command, "cd", 2) == 0)
	 {
		 change_dir(command);
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
		free(command);
		exit(EXIT_SUCCESS);
		
	}
	status_exit = to_int(command[1]);
	free_arr(command);
	exit(status_exit);
}

/**
 * change_dir - change the current working directory
 * @command: parsed command argument
 * Return: 0 on success, -1 on failure
 */
int change_dir(char *command)
{
	char *path = NULL;
	char current_wd[BUFFER_SIZE];

	if (command == NULL) {
		/* if no path is given, go to the home directory */
		path = _getenv("HOME");
	} else if (_strcmp(command, "-") == 0) {
		/* if "-" is given, go to the previous directory */
		path = _getenv("OLDPWD");
	} else {
		/* otherwise, use the given path */
		path = command;
	}

	if (chdir(path) == -1) {
		/* try to change the directory */
		perror("chdir");
		return (-1);
	}

	/* update the PWD and OLDPWD environment variables */
	if (getcwd(current_wd, sizeof(current_wd)) == NULL) {
		perror("getcwd");
		return (-1);
	}

	if (setenv("OLDPWD", _getenv("PWD"), 1) == -1) {
		perror("setenv");
		return (-1);
	}

	if (setenv("PWD", current_wd, 1) == -1) {
		perror("setenv");
		return (-1);
	}

	return (0);
}

