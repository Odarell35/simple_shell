#include "main.h"

/**
 * to_int - convert string  to a int
 * @str:string
 * Return:int
 */
int to_int(char *str)
{
	int result;
	int sign;
	int digit;

	result = 0;
	sign = 1;
	/*Check for negative sign*/
	if (*str == '-')
	{
	sign = -1;
	str++;
	}

	/* Iterate over string characters and convert*/
	while (*str)
	{
	digit = *str - '0';

	if (digit >= 0 && digit <= 9)
	{
		result = result * 10 + digit;
		str++;
	}
	else
	{
		return (0);
	}
	}

	return (sign * result);
}
/**
 * my_puts - main function
 * @s: used for string pointer
 * Return: void
 */
void my_puts(const char *s)
{
	while (*s != '\0')
	{
		_putchar(*s++);
	}
		_putchar('\n');
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_string - prints out string
 *@str: string to be printed
 * Return: nothing
 */

void print_string(const char *str)
{
	size_t len, nwrite;

	len = _strlen(str);
	nwrite = write(STDOUT_FILENO, str, len);
	if (nwrite != len)
	{
		perror("invalid");
	}
}
/**
 * _strdup - returns a pointer  a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be duplicated
 * Return: NULL if str = NULL, pointer upon success
 */
char *_strdup(char *str)
{
	int i, j, len_str;
	char *new_array;

	len_str = 0;
	i = 0;
	if (str == NULL)
		return (NULL);

	while (*str != '\0')
	{
		len_str++;
	i++;
	}
	new_array = malloc(sizeof(char) * len_str);
	for (j = 0; j < len_str; j++)
		new_array[j] = str[j];

	if (new_array == NULL)
		return (NULL);
	free(new_array);
	return (new_array);
	}

