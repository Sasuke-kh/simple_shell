#ifndef _COMMAND_H_

#define _COMMAND_H_

#define NO_COMMANDS 2

typedef int (*command_func)(char **av, int *ac);

typedef struct{
	char *command;
	command_func function;
}command_t;

int is_built_in_commnad(char **av, int *ac);

/* Declaration of built in commands*/
int _cd(char **av, int *ac);
int shell_exit(char **av, int *ac);
#endif 

