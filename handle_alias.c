/**
 * handle_alias - implements the alias built-in command
 * @alias_list: a pointer to the head of the alias list
 * @args: an array of strings representing the command arguments
 *
 * Return: 0 on success, or a non-zero value on error
 */
int handle_alias(alias_t **alias_list, char **argv)
{
	int i;
	char *name, *equals;

	if (!argv[1]) 
	{
		print_aliases(*alias_list);
		return (0);
	}
/* if  one or more arguments are given, parse them and update aliases*/
	for (i = 1; argv[i]; i++)
	{
		name = argv[i];
		equals = _strchr(name, '=');

/* if no equals sign is present, print or unset the alias*/
		if (!equals)
		{
			if (name[0] == '-')
			{
				if (unset_alias(alias_list, name + 1) != 0)
				{
					perror("Failed to unset alias");
					return (1);
				}
			} 
			else 
			{
				print_alias(*alias_list, name);
			}
			continue;
		}

/* temporarily replace the equals sign with a null terminator*/
		equals = '\0';

/* update the alias or create a new one*/
		if (set_alias(alias_list, name, equals + 1) != 0) 
		{
			perror("Failed to create alias");
			return (1);
		}

/* restore the equals sign*/
		equals = '=';
	}

	return (0);
}
/**
 * set_alias - adds or updates an alias in the list
 * @alias_list: a pointer to the head of the alias list
 * @name: the name of the alias to set
 * @value: the value of the alias to set
 *
 * Return: 0 on success, or a non-zero value on error
 */
int set_alias(alias_t **alias_list, const char *name, const char *value)
{
/*search the list for an existing alias with the same name*/
	alias_t *cur, new_alias;
       
	cur = *alias_list;
    while (cur != NULL)
    {
        if (_strcmp(cur->name, name) == 0)
	{/* found an existing alias, update its value*/
            free(cur->value);
            cur->value = _strdup(value);
            if (cur->value == NULL) 
	    {
                perror("Failed to set alias");
                return (1);
            }
            return (0);
        }
        cur = cur->next;
    }

/* no existing alias found, create a new one*/
	new_alias = malloc(sizeof(alias_t));
    if (new_alias == NULL)
    {
        perror("Failed to set alias");
        return (1);
    }
    new_alias->name = _strdup(name);
    new_alias->value = _strdup(value);
    if (new_alias->name == NULL || new_alias->value == NULL)
    {
        free(new_alias->name);
        free(new_alias->value);
        free(new_alias);
        perror("Failed to set alias");
        return (1);
    }
    new_alias->next = *alias_list;
    *alias_list = new_alias;

    return (0);
}

/**
 * delete_alias - removes an alias from the list
 * @alias_list: a pointer to the head of the alias list
 * @name: the name of the alias to delete
 *
 * Return: 0 on success, or a non-zero value on error
 */
int delete_alias(alias_t **alias_list, const char *name)
{
    alias_t *prev, *cur;
	
    prev = NULL;
    cur = *alias_list;
    while (cur != NULL)
    {
        if (_strcmp(cur->name, name) == 0)
	{/*found the alias to delete, remove it from the list*/
            if (prev == NULL) 
	    {/*deleting the first node*/
                *alias_list = cur->next;
            } 
	    else
	    {
                prev->next = cur->next;
            }
            free(cur->name);
            free(cur->value);
            free(cur);
            return (0);
        }
        prev = cur;
        cur = cur->next;
    }
/* no matching alias found*/
    perror("Alias not found");
    return (1);
}

/**
 * print_aliases - prints all aliases in the list
 * @alias_list: a pointer to the head of the alias list
 */
void print_aliases(alias_t *alias_list)
{
    alias_t *cur;

	    *cur= alias_list;
    while (cur != NULL)
    {
        print_string(cur->name);
	print_string(cur->value);
        cur = cur->next;
    }
}

/**
 * print_alias - prints the value of a single alias
 * @alias_list: a pointer to the head of the alias list
 * @name: the name of the alias to print
 */
void print_alias(alias_t *alias_list, const char *name)
{
    alias_t *cur;

	*cur = alias_list;
    while (cur != NULL)
    {
        if (_strcmp(cur->name, name) == 0)
	{
		print_string(cur->value);
	}
	else
		perror("alias not found");
    }
}
           

