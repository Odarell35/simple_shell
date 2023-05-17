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

	result = malloc(sizeof(char) * (_strlen(token) + _strlen(exe_command)) + 2);

	if (result == NULL)
	{
		return (NULL);
		free(result);
	}

	result = _strcat(result, token);
	result = _strcat(result, "/");
	result = _strcat(result, exe_command);

	if (result != NULL)
	{
		free(result);
	}
		return (result);
}
/**
 * look_path - looking for the executable file in the
 * directories found in PATH
 * @command: executable file
 * Return: full path or NULL if not found
 */
char *look_path(char *command)
{
	int i, j, check_status;
	struct stat statbuf;
	char *true_path, *path, *token_path, *delim;
	char **array_of_dir;

	array_of_dir = NULL;
	delim = ":";
	path = _getenv("PATH");
	token_path = strtok(path, delim);

	for (i = 0; token_path != NULL; i++)
	{
		array_of_dir[i] = token_path;
		token_path = strtok(NULL, delim);
	}
	array_of_dir[i] = NULL;
	printf("%s\n", array_of_dir[i + 1]);
	
	for (j = 0; array_of_dir[i] != NULL; j++)
	{
		true_path = concat_path(array_of_dir[i], command);
		check_status = stat(true_path, &statbuf);
		if(check_status == 0)
		{
			free_arr(array_of_dir);
			return (true_path);
		}
	}
/*if path not found*/
	free_arr(array_of_dir);
	free(true_path);
	return (NULL);
}
