#include "main.h"
/**
 * main - main file for all main ececution files
 * Return: 0
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char **argv[], char**envp)
{
	ssize_t n, exe;
	pid_t pid;
	char *str;
	int i, status;
	size_t buf_size;
	char *buf, *token, *delim;
	char *args[10];


	while (1)
{
	buf_size = BUFFER_SIZE;
	n = 0;
	delim = " ";
	buf = malloc(sizeof(char) * buf_size);
	str = malloc(sizeof (char) * buf_size);
	prompt_user();
	signal(SIGINT, handle_signal);
	n = getline(&buf, &buf_size, stdin);
	if (n == -1)
	{
	_putchar('\n');	
		free(buf);
		free(str);
		free(token);
		exit(EXIT_SUCCESS);
	}

	/*write(STDOUT_FILENO, buf, n);*/
	if (buf[n - 1] == '\n')
	{buf[n - 1] = '\0';}
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
	/* implement any builtin functions*/	
	if (_strcmp(args[0], "exit") == 0)
	{
		free(buf);
		free(str);
		free(token);
		exit(EXIT_SUCCESS);
	}
	/* check if command is executable*/
	if (status_file(args[0],statbuf) == -1)
	{
		/*look for path*/
		true_path = look_path(args[0]);
			if (true_path == NULL)
			{
				perror("Error: file nto found");
				free(buf);
				free(str);
				free(token);
				continue;
			}
			else
			{
				free(args[0]);
				args[0] = true_path;
			}
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
				free(buf);
				free(token);
				free(str);
                    	}

            	}
             	else
             	{
                    	wait(&status);
			if(!wait)
			{
				perror("Error: wait failed");
				free(buf);
				free(token);
				free(str);
			}
				    
             	}

		
	free(buf);
	free(token);
	free(str);
}
	return (0);
}
