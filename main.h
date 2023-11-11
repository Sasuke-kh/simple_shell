#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFSIZE 1204
#define INITIAL_BUFFER_SIZE 128

int _fgetc(int fd);
ssize_t _getline(char **lineptr, size_t *n, int fd);
#endif /* MAIN_H */
