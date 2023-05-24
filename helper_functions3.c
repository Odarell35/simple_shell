#include "main.h"
/**
 * _strchr -  a function that locates a character in a string.
 * @s: string
 * @c: character
 * Return: s where character appears first or NULL for non match
 */
char *_strchr(char *s, char c)
{
	for ( ; *s != '\0'; s++)
	{
		if (*s == c)
		return (s);
	}
return ('\0');
}
/**
 * _strstr -  a function that locates a string in a string.
 * @haystack: string
 * @needle: string to look for in haystack
 * Return: needle
 */
char *_strstr(char *haystack, char *needle)
{
	return (strstr(haystack, needle));
}
/**
 * int_to_string -  a function that converts a int to a string.
 * @num: number to convert
 * Return: string
 */
char *int_to_string(int num)
{
	int i, sign, j, count, temp_num;
	char temp, *str;

	i = 0;
	sign = 0;
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	count = 1;
	temp_num = num;
	while (temp_num / 10 > 0)
	{
		count++;
		temp_num /= 10;
	}
	str = malloc((count + sign + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
		free(str);
	}
	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	while (num)
	if (sign)
	{
		str[i++] = '-';
	}
	for (j = 0; j < i / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
	}
	str[i] = '\0';
return (str);
}
