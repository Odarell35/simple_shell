#include "main.h"
/**
 * display_alias - prins the list of alias found on the shell
 *
 * Return: void
 */
void display_alias(void)
{
	int i;
	char *alias[] = {"alias egrep='egrep --color=auto'",
		"alias fgrep='fgrep --color=auto'",
		"alias grep='grep --color=auto'",
		"alias l='ls -CF'",
		"alias la='ls -A'",
		"alias ls='ls --color=auto'",
		"alias ll='ls -alF'",
		NULL};

	i = 0;
	while (alias[i] != NULL)
	{
		write(STDOUT_FILENO, alias[i], strlen(alias[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
/**
 * get_alias - get alias value from alias list
 * @name: alias name
 * Return: value of alias and the name
 */
char *get_alias(const char *name)
{
	char **alias_list;
	char *alias[] = {"alias egrep='egrep --color=auto'",
		"alias fgrep='fgrep --color=auto'",
		"alias grep='grep --color=auto'",
		"alias l='ls -CF'",
		"alias la='ls -A'",
		"alias ls='ls --color=auto'",
		"alias ll='ls -alF'",
		NULL};
	size_t length_alias;

	if (name == NULL)
		return (NULL);
	for (alias_list = alias; *alias_list != NULL; alias_list++)
	{
		length_alias = _strlen(name);
		if (_strncmp(name, *alias_list, length_alias) == 0)
		return (&((*alias_list)[length_alias]));
	}
return (NULL);
}
