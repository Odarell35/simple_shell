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

/*	if (result != NULL)*/
	
		free(result);
	
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
	int i, j, check_status, no_of_dir;
	struct stat statbuf;
	char *true_path, *path, *token_path, *delim;
	char **array_of_dir;

	no_of_dir = 0;
	delim = ":";
	true_path = NULL;
	path = _getenv("PATH");
	token_path = strtok(path, delim);
	i = 0;
	while (token_path != NULL)
	{
		no_of_dir++;
		token_path = strtok(NULL, delim);
		i++;
	}
	  array_of_dir = malloc(sizeof(char *) * no_of_dir + 1);
	  token_path = strtok(path, delim);


	for (i = 0; token_path != NULL; i++)
	{
		array_of_dir[i] = token_path;
		token_path = strtok(NULL, delim);
	}
	array_of_dir[i] = NULL;
printf("%ld\n", sizeof(array_of_dir));
printf("%s\n", array_of_dir[2]);
	for (j = 0;  j < 7 ; j++)
	{
		printf("%s\n", array_of_dir[2]);
		true_path = concat_path(array_of_dir[j], command);
		check_status = stat(true_path, &statbuf);
		if (check_status == 0)
		{
			printf("%d\n", check_status);
        printf("%s\n", true_path);
			return (true_path);
		
			
		}
	}	
/*	printf("%d\n", check_status);
	printf("%s\n", true_path);
	}*/
/*if path not found*/
	free_arr(array_of_dir);
	free(true_path);
	return (NULL);
}
