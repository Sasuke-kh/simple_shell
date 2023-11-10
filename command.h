#ifndef _COMMAND_H_

#define _COMMAND_H_

#define NO_COMMANDS 1

typedef void (*command_func)(char **av);

typedef struct{
	char *command;
	command_func function;
}command_t;




#endif 

