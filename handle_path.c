#include "main.h"
/**
 * look_path - looking for the executable file in the
 * directories found in PATH
 * @command: executable file
 * @cmd: cmd argument
 * @argv: array argument
 * @cmd_num: execution times
 * Return: full path or NULL if not found
 */
int look_path(char *command, char **cmd, char **argv, int cmd_num)
{
	int name_ptr;
	char *path_cpy, *path, *token_path, *name;
	const char *delim;

	delim = ":";
	name = NULL;
	path = getenv("PATH");
	if (path == NULL)
		return (_print_error(argv, cmd_num, command));
	path_cpy = strdup(path);
	token_path = strtok(path_cpy, delim);
	if (token_path == NULL)
		return (_print_error(argv, cmd_num, command));
	name = malloc(_strlen(token_path) + _strlen(command) + 2);
	if (name == NULL)
	{

		_print_error(argv, cmd_num, command);
		free(path_cpy);
		return (-1);
	}

	while (token_path != NULL)
	{
		_strcpy(name, token_path);
		_strcat(name, "/");
		_strcat(name, command);
		if (access(name, X_OK) == 0)
		{
			name_ptr = execute(name, cmd, argv, cmd_num);
			free(path_cpy);
			free(name);
			return (name_ptr);
		}
		token_path = strtok(NULL, delim);
	}
	free(path_cpy);
	free(name);
	return (_print_error(argv, cmd_num, command));
}
