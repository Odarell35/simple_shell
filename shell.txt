#include "main.h"

int main(__attribute__((unused))int argc, char **argv)
{
	int i;
	
	i = 1;
	while (argv[i] != NULL)
	{
		print_string(argv[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}
