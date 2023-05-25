#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

extern char **environ;

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
            char *args[] = {command, NULL};
            execve(command, args, environ);
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

int main(void)
{
    shell();
    return 0;
}

