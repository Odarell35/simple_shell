#include "main.h"
/**
 * main - main file for all main execution files
 * @argc: argument count
 * @args: array of arguments
 * @envp: environment
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
	prompt_user();
	fflush(stdout);
	buff = getline(&buf, &buf_size, stdin);
	if (buff == -1)
		return(-1);
		/*hashtag(buff);*/
	token = strtok(buf, delim);
	if (token == NULL)
		return (-1);
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
	free(buf);
}
return (0);
}
