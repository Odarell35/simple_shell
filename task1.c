#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

extern char **environ;

bool is_builtin_command(const char *command)
{
    const char *builtins[] = {
        "cd",
        "pwd",
        "exit"
    };
    int num_builtins = sizeof(builtins) / sizeof(char *);

    for (int i = 0; i < num_builtins; i++)
    {
        if (strcmp(command, builtins[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

void execute_builtin_command(const char *command, char *args[])
{
    if (strcmp(command, "cd") == 0)
    {
        if (args[1] != NULL)
        {
            if (chdir(args[1]) != 0)
            {
                perror("cd");
            }
        }
        else
        {
            fprintf(stderr, "cd: missing argument\n");
        }
    }
    else if (strcmp(command, "pwd") == 0)
    {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
        {
            printf("%s\n", cwd);
        }
        else
        {
            perror("pwd");
        }
    }
    else if (strcmp(command, "exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }
}

void shell(void)
{
    char command[MAX_COMMAND_LENGTH];
    char *args[MAX_ARGUMENTS];

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

        char *token;
        int i = 0;
        token = strtok(command, " ");
        while (token != NULL && i < MAX_ARGUMENTS - 1)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (is_builtin_command(args[0]))
        {
            execute_builtin_command(args[0], args);
        }
        else
        {
            pid_t pid = fork();
            if (pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0)
            {
                execvp(args[0], args);
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
}

int main(void)
{
    shell();
    return 0;
}

