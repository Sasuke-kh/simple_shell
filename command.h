#ifndef _COMMAND_H_

#define _COMMAND_H_

#define NO_COMMANDS 5
typedef int (*command_func)(char **av, int *ac, int *exit_status);

typedef struct{
	char *command;
	command_func function;
}command_t;

int is_built_in_commnad(char **av, int *ac, int *exit_status);

/* Declaration of built in commands*/
int _cd(char **av, int *ac, int *exit_status);
int shell_exit(char **av, int *ac, int *exit_status);
int shell_env(char **av, int *ac, int *exit_status);
int shell_setenv(char **av, int *ac, int *exit_status);
int shell_unsetenv(char **av, int *ac, int *exit_status);
#endif 

