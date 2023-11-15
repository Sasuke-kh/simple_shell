#ifndef STRINGS_H
#define STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include "memory_manager.h"
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strtok(char *str, const char *delim);
void print_str(char *str);
void print_error(char *str);
int _atoi(char *s);
int is_number(char *str);
#endif /* STRINGS_H */
