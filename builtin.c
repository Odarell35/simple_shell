#include "main.h"
/**
 * change_dir - change the current working directory
 * @command: parsed command argument
 * Return: 0 on success, -1 on failure
 */
int change_dir(char *command)
{
	char *path = NULL;
	char current_wd[BUFFER_SIZE];

	if (command == NULL) /*if no path is given, go to the home directory*/
	{
		create_env(&path);
	}
	else if (_strcmp(command, "-") == 0) /* if "-" is given, go to the previous directory*/
	{
	       	create_env(&path);
	}
	else /* otherwise, use the given path*/
	{
		path = command;
	}

	if (chdir(path) == -1)
	{ /* try to change the directory*/
		perror("argv[0], command path not found \n");
		return (-1);
	}

/* update the PWD and OLDPWD environment variables*/
	getcwd(current_wd, sizeof(current_wd));
	setenv("OLDPWD", create_env(&path), 1);
	if ((setenv("OLDPWD", create_env(&path), 1)) == -1)
		{
			perror("Could not initialize to PWD");
		}
	setenv("PWD", current_wd, 1);
	if ((setenv("OLDPWD", create_env(&path), 1)) == -1)
                {
                        perror("Could not initialize to PWD");
                }

	return (0);
}
/**
 * get_display_env - Display Environment Variables
 *
 * Return: Always 0
 */
int get_display_env()
{
	const char *env_var;
	size_t i;

		i = 0;

	while ((env_var = environ[i++]) != NULL)
	/*Loop through environment variables*/
	{
		print_string(env_var);
	}
	return (0);
}


