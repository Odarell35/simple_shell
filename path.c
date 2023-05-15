#include "main.h"
/**
 * *_getenv - gets an environment variable
 * @name: name of variable
 * Return: pointer to string
 */
char *_getenv(const char* name)
{
	char **env;
	size_t len;

	 if (name == NULL) {
        return NULL;
    }

    for ( env = environ; *env != NULL; env++) {
        len = _strlen(name);
        if (_strncmp(name, *env, len) == 0 && (*env)[len] == '=') {
            /* Found the environment variable, extract the value and return it*/
            return (_strdup(*env + len + 1));
        }
    }

    /* Environment variable not found*/
    return (NULL);
}

