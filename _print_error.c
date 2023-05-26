#include "main.h"
/**
 * _print_error - prints error message
 * @argv: argument
 * @cmd_num: execution time
 * @command: entered command
 * Return: error mgs or 127 
 */
int _print_error(char **argv, int cmd_num, char *command)
{
	char *error_mgs;
	char *str_cmd_num = int_to_string(cmd_num);
	int cmd_len = _strlen(str_cmd_num);
	int len_error_mgs = _strlen(argv[0]) + (2 * _strlen(": ")) + _strlen(command) + _strlen(": not found\n") + cmd_len + 1;
	error_mgs = malloc(sizeof(char) * len_error_mgs);
	if (error_mgs == NULL)
		return (-1);
	strcpy(error_mgs, argv[0]);
	_strcat(error_mgs, ": ");
	_strcat(error_mgs, str_cmd_num);
	_strcat(error_mgs, ": ");
	_strcat(error_mgs, command);
	_strcat(error_mgs, ": not found\n");
	_strcat(error_mgs, "\0");
	write(STDERR_FILENO, error_mgs, _strlen(error_mgs));
	free(error_mgs);
	free(str_cmd_num);
	return (127);
}
