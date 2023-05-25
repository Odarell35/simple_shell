#include "main.h"
/**
 * concat_path - used for concatinating two strings
 * @token: used for path connection
 * @exe_command: used for executing the command
 * Return: results
 */
char *concat_path(char *token, char *exe_command)
{
	char *result;

	result = malloc(sizeof(char) * (_strlen(token) + _strlen(exe_command) + 2));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	result = _strcat(result, token);
	result = _strcat(result, "/");
	result = _strcat(result, exe_command);
	free(result);
	return (result);
}
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
	name = malloc(strlen(token_path) + strlen(command) + 2);
	if (name == NULL)
	{
		perror(command);
		free(path_cpy);
		return (-1);
	}

	while (token_path != NULL)
	{
		strcpy(name, token_path);
		strcat(name, "/");
		strcat(name, command);
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
