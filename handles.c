#include "main.h"
#include <dirent.h>
#include <string.h>
#define MAX_ARGS 10

/**
 * handle_signal - handle signal
 * @n: signal
 * Return: nothing
 */
void handle_signal(void)
{
	signal(SIGINT, handle_signal);

        char command[100];
        char *args[MAX_ARGS];
        int i = 0;

        printf("\n$ ");
        fflush(stdout);

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';

        args[i] = strtok(command, " ");

        while (args[i] != NULL && i < MAX_ARGS - 1)
        {
                i++;
                args[i] = strtok(NULL, " ");
        }

        args[i + 1] = NULL;
	 if (args[0] != NULL)
        {
                if (strcmp(args[0], "exit") == 0)
                        exit(0);
                else if (strcmp(args[0], "ls") == 0)
	{
		DIR *dir;
		struct dirent *entry;


		dir = opendir(".");
		if (dir == NULL)
		{
			perror("opendir");
			return;
		}

		while ((entry = readdir(dir)) != NULL)
		{
			if (entry->d_type == DT_DIR)
			{
				if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
				{
					printf("%s ", entry->d_name);
				}
			}
		}
		closedir(dir);
	}
		else
		{
			printf("unknown command: %s\n", args[0]);
		}
	}

		printf("\n$ ");
		fflush(stdout);

}

/**
 * hashtag - removes anything after # sign
 * @str: string
 * Return: nothing (# only)
 */
void hashtag(char *str)
{
        int index;

        index = 0;
        while(str[index] != '\0')
        {
                if (str[index] == 35)
                {
                        str[index] = '\0';
                }
                index++;
        }
}                           

