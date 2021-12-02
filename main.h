#ifndef __MAIN_H__
#define __MAIN_H__

#define DEHORS 0
#define DEDANS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
extern char **environ;

int number_of_words(char *str, char *separator);
char **fillarguments(char *buf, char *separator);
int prompt(char **buff);
void processus(char **av, char *buf);
int _strlen(char *str);
char *_strtok(char *string, const char *cutter);
int findinthepath(char **firstargument);
void freememory(char *buff, char **av);
void freememory2(char *str1, char *str2, char *str3);
int _strcmp(char *s1, char *s2);
void printenv(void);
int checkBuiltins(char **av, char *buff);
char *_getenv(const char *name);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
#endif
