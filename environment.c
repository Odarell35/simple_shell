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

char *_getenv(const char* name)
{
	
	size_t len;
	int i;

	 if (name == NULL) {
        return NULL;
    }

    for ( i = 0; environ[i] != NULL; i++)
    {
        len = _strlen(name);
        if (strncmp(name, environ[i], len) == 0)
	{
             /*Found the environment variable, extract the value and return it*/
          return (_strdup(environ[i] + len + 1));
	}
    }	
    
  /*Environment variable not found*/
  return (NULL);
}
/**
 * main - testing these functions
 */
int main(void)
{
	char *name;

	name = _getenv("PATH");
	printf("%s\n", *environ);
	printf("%s\n", name);
	return(0);
}
