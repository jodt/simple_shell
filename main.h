#ifndef __MAIN_H__
#define __MAIN_H__

#define DEHORS 0
#define DEDANS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

int number_of_words(char *str);
char **fillarguments(char *buf);
int prompt(char **buff);
void processus(char **av, char *buf);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
void printenv(void);
void checkBuiltins(char **av, char *buff);

#endif
