#include "list.h"
int get_command(char **av, int *ac);
int fork_and_execve(char **av, char **env);
int get_PATH(char **env, list_t **paths_head);
int is_found_and_excecutable(char **av, list_t *paths_head);
int get_command_from_file(int fd, char **av, int *ac);
