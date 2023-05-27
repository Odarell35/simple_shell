#include "main.h"
/**
 * main - main file for all main execution files
 * @argc: argument count
 * @argv: array of arguments
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	int i, cmd_num = 0, status = 0;
	size_t buf_size;
	char *buf, *token, *args[BUFFER_SIZE];
	const char *delim;

	signal(SIGINT, handle_signal);
	while (1)
	{
		cmd_num++;
		buf_size = 0;
		delim = " \n";
		buf = NULL;
		if (isatty(STDIN_FILENO))
			prompt_user();
		fflush(stdout);
		_getline(&buf, &buf_size, status);
		if (buf[0] != '\n')
		{
			token = strtok(buf, delim);
			if (token == NULL)
			{
				free(buf);
				continue;
			}
			for (i = 0; token != NULL; i++)
			{
				args[i] = token;
				token = strtok(NULL, delim);
			}
			args[i] = NULL;
			if (check_builtin(args, status, &buf) == 0)
				status = 0;
			else
				status = execute(args[0], args, argv, cmd_num);
		}
		free(buf);
	}
	return (0);
}
