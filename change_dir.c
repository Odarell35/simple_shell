#include"main.h"
/**
 * change_dir - change the current working directory
 * @command: parsed command argument
 * Return: 0 on success, -1 on failure
 */
int change_dir(char **command)
{
	char current_wd[BUFFER_SIZE], *old_pwd;

	if (command[1] == NULL)
	{
		if (chdir(_getenv("HOME")) == -1)
		perror("chdir");
	}
	else if (_strcmp(command[1], "-") == 0)
	{
		chdir(_getenv("OLDPWD"));
	}
	if (chdir(command[1]) == -1)
	{
		old_pwd = _getenv("OLDPWD");
		if (old_pwd == NULL)
		{
			printf("OLDPWD not set\n");
			return (-1);
		}
		if (chdir(old_pwd) == -1)
			perror("chdir");
	}
	else
	{
		if (chdir(command[1]) == -1)
		{
			perror("chdir");
			return (-1);
		}
	if (getcwd(current_wd, sizeof(current_wd)) == NULL)
	{
		perror("getcwd");
		return (-1);
	}
	if (setenv("OLDPWD", _getenv("PWD"), 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	if (setenv("PWD", current_wd, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}
	}
return (0);
}
