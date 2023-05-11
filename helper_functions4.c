#include "main.h"

/**
 * print_number - prints an integer.
 * @n: input integer.
 * Return: no return.
 */
void print_number(int n)
{
	unsigned int m, d, count;

	if (n < 0)
	{
		_putchar(45);
		m = n * -1;
	}
	else
	{
		m = n;
	}

	d = m;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (; count >= 1; count /= 10)
	{
		_putchar(((m / count) % 10) + 48);
	}
}
/**
 * _strcpy - copies
 * @dest: destination
 * @src: source
 * Return: nothing
 */
char *_strcpy(char *dest, char *src)
{
	return (strcpy(dest, src));
}
/**
 * _strspn - calculates the length of the initial segment
 * entirely of characters from a given set of characters.
 * @s: string
 * @accept: containing the characters to search for
 * Return: length of the initial substring of characters from accept.
 */
size_t _strspn(const char *s, const char *accept)
{
	size_t count = 0;
	const char *p = s;

	while (*p != '\0')
	{
		const char *a = accept;

		while (*a != '\0')
		{
		if (*p == *a)
		{
		count++;
		break;
		}
			a++;
		}

	if (*a == '\0')
	{
		break;
	}
		p++;
	}

	return (count);
}

