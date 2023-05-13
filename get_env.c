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
                env[i] = strdup(environ[i]);
                if (env[i] == NULL) {
                        /* Handle error if strdup fails */
                        exit(EXIT_FAILURE);
                }
        }

        /* Add a NULL terminator to the end of the array */
        env[i] = NULL;

}
int main(void)
{
	int i;

	create_env(environ);
	for (i = 0; environ[i] != NULL; i++)
	printf("%s\n", environ[i]);
return(0);
}
