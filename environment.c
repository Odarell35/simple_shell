#include "main.h"
/**
 * create_env - Creates an array of environment variables
 * @env: Array of environment variables to be created
 * Return: void
 */
void display_environ(char **env)
{
	int i;

	env = environ;
	i = 0;
	while(env[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	
	
}

/**
 * *_getenv - gets an environment variable
 * @name: name of variable
 * Return: pointer to string
 */

char *_getenv(const char *name)
{
	char **env;
	size_t len;

	 if (name == NULL) {
        return NULL;
    }

    for (env = environ; *env != NULL; env++)
    {
        len = _strlen(name);
        if (strncmp(name, *env, len) == 0 && (*env)[len] == '=')
	{
            /* Found the environment variable, extract the value and return it*/
            return (&((*env)[len + 1]));
        }
    }

    /* Environment variable not found*/
    return (NULL);
}
