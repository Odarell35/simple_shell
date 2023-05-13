#include "main.h"
/**
 * main - main file for all main ececution files
 * Return: 0
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char *argv[], char**envp)
{
	ssize_t n, exe;
	pid_t pid;
	char *str;
	int i, k, status;
	size_t buf_size;
	char *buf, *token, *delim;
	char *args[10];


	buf_size = BUFFER_SIZE;
	n = 0;
	delim = " ";
	buf = malloc(sizeof(char) * buf_size);
	str = malloc(sizeof (char) * buf_size);
	prompt_user();
	n = getline(&buf, &buf_size, stdin);
	write(STDOUT_FILENO, buf, n);
	_strcpy(str, buf);
	token = strtok(str, delim);
	i = 0;
		while (token && i < 10)
		{
			args[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		args[i] = NULL;
		for (k = 0; args[k] != NULL; k++)
		{
			printf("%s\n", args[k]);
		}
		 pid = fork();

                    	if (pid == -1)
                            	return (-1);
             	if (pid == 0)
             	{

                    	exe = execve(args[0], args, envp);
                    	if (exe == -1)
                    	{
                            	perror("Error");
                    	}

            	}
             	else
             	{
                    	wait(&status);
             	}

		
	free(buf);
	free(token);
	free(str);
	return (0);
}
