#include "main.h"
/**
 * is_valid_cmd - check for valid cmd
 * @command: command to check
 * Return: 0 failure other for otherwise
 */
int is_valid_cmd(char *command)
{
	if (_strncmp(command, "/", 1) == 0)
		return (1);
	if (_strncmp(command, "./", 2) == 0)
		return (1);
	if (_strncmp(command, "../", 3) == 0)
		return (1);
return (0);
}

/**
 * execute - execution
 * @command: command
 * @second_command: second command
 * @argv: array of argument
 * @cmd_num: execution times
 * Return: status or error message
 */
int execute(char *command, char **second_command, char **argv, int cmd_num)
{
	int status = 0;
	pid_t pid;

	if (access(command, X_OK) == 0 && is_valid_cmd(command))
	{
		pid = fork();
		if (pid == -1)
			return (_print_error(argv, cmd_num, command));
		if (pid == 0)
		{
			if ((execve(command, second_command, environ)) == -1)
				return (_print_error(argv, cmd_num, command));
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			status = WEXITSTATUS(status);
			if (!isatty(STDIN_FILENO))
			return (status);
		}

	}
	else
		return (look_path(command, second_command, argv, cmd_num));
	return (status);
}
