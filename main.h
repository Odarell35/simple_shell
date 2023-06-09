#ifndef _MAIN_H_
#define _MAIN_H_

extern char **environ;



/* LIBS USED*/

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/*MACROS*/
#define BUFFER_SIZE 1024

/*prototypes for builtin*/
void display_environ(char **env);
int change_dir(char **command);
void exit_myshell(char **command, int status, char **buf);
int check_builtin(char **command, int status, char **buf);
void display_alias(void);
void call_for_execute(char **args, char **envp);
char *get_alias(const char *name);


/*prototypes for helper functions*/
int count(char *token, char *buff);
int _strlen(const char *s);
int _strcmp(char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strncpy(char *dest, char *src, size_t n);
char *_strcat(char *dest, char *src);
int to_int(char *str);
void my_puts(const char *s);
int _putchar(char c);
char *_strchr(char *s, char c);
char *_strdup(char *str);
char *int_to_string(int num);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, char *src);
void print_string(const char *str);
void print_number(int n);
int status_file(const char *pathname, struct stat *statbuf);
void free_arr(char **arr);
void display_error(void);
size_t _strspn(const char *s, const char *accept);

void shell(void);

/*prototypes for readline*/
char *read_command(char *buf, size_t buf_size);
void prompt_user(void);
int _print_error(char **argv, int cmd_num, char *command);
ssize_t _getline(char **buf, size_t *buf_size, int status);

/*prototype for path*/
char *_getenv(const char *name);
int execute(char *command, char **second_command, char **argv, int cmd_num);
int look_path(char *command, char **cmd, char **argv, int cmd_num);
char *concat_path(char *token, char *exe_command);
int examine_command(char *input, char **command, char argv, int sec);
/*prototypes for handles*/
void hashtag(char *str);
void handle_signal(int n);
/*prototype for file*/
void read_file(char *filename);
#endif
