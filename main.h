#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int number_of_words(char *str);
char **fillarguments(char *buf);
int prompt(char **buff);
void processus(char **av, char *buf, ssize_t charactersnumbers);
#endif
