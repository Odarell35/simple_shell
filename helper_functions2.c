#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 same, positive and negative value not same
 */
int _strcmp(char *s1, const char *s2)
{
	int i = 0;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (0);
}

/**
 * _strncmp - Compare of characters of two strings.
 * @s1: first string.
 * @s2: second string.
 * @n: amount of characters to compare.
 *
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *s1, char *s2, int n)
{
	int i = 0;

	if (s1 == NULL)
	{
		return (-1);
	}


		while (s2[i] && i < n)
		{
			if (s1[i] == s2[i])
			{
				i++;
			}
			else
			{
				return (1);
			}
		}

	if (s1 == NULL)
	{
		return (0);
	}

	return (1);
}

/**
 * _strlen - returns the length of a string.
 * @s: input string.
 * Return: length of a string.
 */

int _strlen(const char *s)
{
	size_t length = 0;

	while (*s++)
	length++;
	return (length);
}

/**
 * _strncpy - copies at most n bytes of the string pointed to by src,
 * including the terminating null byte, to the buffer pointed to by dest.
 * @dest: destination.
 * @src: source.
 * @n: maximum number of bytes to copy.
 * Return: the pointer to dest.
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t count = 0;

	while (count < n)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
		break;
		count++;
	}

	return (dest);
}
/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = 0, i;

	while (dest[dest_len] != '\0')
	{
		dest_len++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return (dest);
}

