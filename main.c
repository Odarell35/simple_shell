#include "main.h"
/**
 * main - main file for all main execution files
 * @argc: argument count
 * @argv: array of arguments
  * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	int i;
	size_t buf_size;
       	ssize_t	buff;
	char *buf, *token, *args[BUFFER_SIZE];
      	const char *delim;

	signal(SIGINT, handle_signal);
	while (1)
{
	buf_size = 0;
	delim = " \n";
	buf = NULL;
	if (isatty(STDIN_FILENO))
	prompt_user();
	fflush(stdout);
	buff = getline(&buf, &buf_size, stdin);
	if (buff == -1)
	{
		free(buf);
		exit(EXIT_SUCCESS);
	}
		/*hashtag(buff);*/
	if (buf[0] != '\n')	
	{
		token = strtok(buf, delim);
		for (i = 0; token != NULL; i++)
		{
			args[i] = token;
			token = strtok(NULL, delim);
		}
		args[i] = NULL;
		if (args == NULL || args[0] == NULL)
			continue;
		if (check_builtin(args) == 0)
			continue;
		execute(args[0], args); 
	}
	free(buf);
	}
return (0);
}
