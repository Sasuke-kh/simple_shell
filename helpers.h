#ifndef _HELPERS_H_
#define _HELPERS_H_
#include "list.h"
int get_PATH(char **env, list_t **paths_head);
int fork_and_execve(char **av, char **env, int *exit_status);
int get_command_from_file(int fd, char **av, int *ac);
int is_found_and_excecutable(char **av, list_t *paths_head);
#endif
