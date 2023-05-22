#include "main.h"
/**
 * status_file - gets the file status
 * @pathname: file name
 * @statbuf:stores the status of file
 * Return: 0 on success and -1 faiure
 */
int status_file(const char *pathname, struct stat *statbuf)
{
	int results;

	results = stat(pathname, statbuf);
	if (results == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}
/**
 * free_arr- freess array
 * @arr: array to be freed
 * @size: size of array
 * Return: void
 */
void free_arr(char **arr)
{
	int i;

	i = 0;
	while(arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
