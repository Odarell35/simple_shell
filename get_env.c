#include "main.h"
/**
 * create_env - Creates an array of environment variables
 * @env: Array of environment variables to be created
 * Return: void
 */
void create_env(char **env)
{
        int i;

        /* Copy each environment variable into the array */
        for (i = 0; environ[i]; i++) {
                env[i] = _strdup(environ[i]);
                if (env[i] == NULL) {
                        /* Handle error if strdup fails */
                        exit(EXIT_FAILURE);
                }
        }

        /* Add a NULL terminator to the end of the array */
        env[i] = NULL;

}
/**
 * get_path - the path of has the directories
 * Return: string with the path
 

char *get_path(void)
{
	char *path = create_env("PATH");
	if (path == NULL)
	{
		perror("failed to get path");
	}
	return (path);
}*/
