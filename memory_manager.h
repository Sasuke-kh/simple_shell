#ifndef _FREE_MANAGER_H_
#define _FREE_MANAGER_H_
#include <stdlib.h>
void free_manager(void *ptr);
void free_av_memory(char **av, int ac);
void free_and_NULL(void **ptr);
void *_malloc(size_t size);
#endif
