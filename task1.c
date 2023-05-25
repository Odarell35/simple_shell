#include "main.h"

#define MAX_COMMAND_LENGTH 100

void shell(void)
{
    char command[MAX_COMMAND_LENGTH];
    while (1)
    {
        printf("$ ");
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\nExiting the shell.\n");
            break;
        }
        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) == 0)
        {
            continue;
        }

        pid_t pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            execlp(command, command, NULL);
            perror("exec");
            exit(EXIT_FAILURE);
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

