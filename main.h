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
int get_display_env();
int change_dir(char *command);
void create_env(char **env);

/*prototypes for helper functions*/
int _strlen(const char *s);
int _strcmp(char *s1, const char *s2);
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
size_t _strspn(const char *s, const char *accept);

/*prototypes for readline*/
ssize_t my_getline();
void prompt_user(void);

/*prototype for path*/
char *_getenv(const char* name);
#endif
