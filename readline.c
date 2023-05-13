#include "main.h"
/**
 * prompt_user - show the prompt ($)
 * Return: nothing
 */
void prompt_user(void)
{
	char *buf;

	buf = "$ ";
	write(STDOUT_FILENO, buf, strlen(buf));
}

/**
 * my_getline - reads an entire line from stdin
 * @lineptr: address of buffer
 * @n: size of buffer
 * @stream: a line from stdin
 * Return: string from stdin
 */
ssize_t my_getline()
{
	ssize_t nread;
	int buf_size, byte_size;
	char *new_buf, *tmp;
	char buf;


	buf = 0;
	buf_size = BUFFER_SIZE;
	new_buf = malloc(sizeof(char) * buf_size);
	if (new_buf == NULL)
	{
		perror("malloc failed");
		free(new_buf);
		exit(EXIT_FAILURE);
	}

	byte_size = 0;
	while (buf != EOF && buf != '\n')
	{
		nread = read(STDIN_FILENO, &new_buf[byte_size], 1);
		if (nread == 0)
		{
			if (byte_size == 0)
			{
				free(new_buf);
				return (0);
			}
			else 
			{
				break;
			}
		}
		else
		{
			perror("read failed");
			free(new_buf);
			exit(EXIT_FAILURE);
		}

		byte_size++;
		if (byte_size == buf_size)
		{
			buf_size = buf_size * 2;
			tmp = realloc(new_buf, buf_size);
				if (tmp == NULL)
				{
					perror("realloc failed");
					free(new_buf);
					exit(EXIT_FAILURE);
				}
			new_buf = tmp;
		}
		if (new_buf[byte_size - 1] == '\n')
		{
			break;
		}
	}
	
	new_buf[byte_size - 1] = '\0';
/*	nwrite = write(1, new_buf, nread);*/
	return (write(1, new_buf, nread));
}
	
