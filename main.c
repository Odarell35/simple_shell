#include "main.h"
/**
 * main - main file for all main ececution files
 * Return: 0
 */
int main(__attribute__((unused))int argc, char **args, char **envp)
{
	ssize_t n, exe;
	pid_t pid;
	int i, no_of_token, status, j, check;
	size_t buf_size;
	char *buf, *token, *delim, *true_path;
	struct stat statbuf;

	while (1)
{
	buf_size = 0;
	no_of_token = 0;
	n = 0;
	delim = " ";
	buf = NULL;;
	
	prompt_user();
	n = getline(&buf, &buf_size, stdin);
	if (n == -1)
	{
	_putchar('\n');	
		free(buf);
		exit(EXIT_SUCCESS);
	}

	if (buf[n - 1] == '\n')
	{
		buf[n - 1] = '\0';
	}
	token = strtok(buf, delim);
	for (j = 0; token != NULL; j++)
	{
		no_of_token++;
		token = strtok(NULL, delim);
	}
	token = strtok(buf, delim);
	args = malloc(sizeof(char *) * no_of_token + 1);
		i = 0;
		while (token)
		{
			args[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		args[i] = NULL;
	/* implement any builtin functions*/	
		check = check_builtin(args);
			if (check == 0)
			{
			    continue;
			}
		

					/* check if command is executable*/
					/*if (status_file(args[0], &statbuf) == -1)
					{
					look for pat
					true_path = look_path(args[0]);
					if (true_path == NULL)
					{
					perror("Error: file nto found");
					free_arr(args);
					free(buf);
					free(token);
					
			
					continue;
					}
					else
					{
					free(args[0]);
					args[0] = true_path;
					}
					}*/

			
		 pid = fork();

                    	if (pid == -1)
                            	return (-1);
             	if (pid == 0)
             	{

                    	exe = execve(args[0], args, envp);
                    	if (exe == -1)
                    	{
                            	perror("Error");
				free_arr(args);
				free(buf);
				free(token);
				exit(EXIT_FAILURE);
                    	}

            	}
             	else
             	{
                    	wait(&status);
				    
             	}

	free(args);
	free(buf);
	free(token);
	
	}
return (0);
}
