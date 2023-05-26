#include "main.h"
/**
 * look_path - looking for the executable file in the
 * directories found in PATH
 * @command: executable file
 * Return: full path or NULL if not found
 */
char look_path(char *command, char **cmd)
{
	int name_ptr;
	char *path_cpy, *path, *token_path, *name;
	const char *delim;

	delim = ":";
	name = NULL;
	path = getenv("PATH");
	path_cpy = strdup(path);
	if (path_cpy == NULL)
	{
		free(path_cpy);
		return (-1);
	}
	token_path = strtok(path_cpy, delim);
	if (token_path == NULL)
	{
		perror(command);
		return (-1);
	}
	name = malloc(_strlen(token_path) + _strlen(command) + 2);
	if (name == NULL)
	{
		perror(command);
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
			
			name_ptr = execute(name, cmd);
			free(path_cpy);
			free(name);
			return (name_ptr);
		}
		token_path = strtok(NULL, delim);
	}
free(path_cpy);
free(name);
perror(command);
return (-1);
}
