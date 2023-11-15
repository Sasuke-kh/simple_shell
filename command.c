#include "command.h"
#include "strings.h"

/**
 * is_built_in_commnad - like the name ;)
 * @av: args
 * @ac: args count
 * @exit_status: like the name
 * Return: idk
 */

int is_built_in_commnad(char **av, int *ac, int *exit_status)
{
	command_t commands[NO_COMMANDS] = {{"cd", _cd}, {"exit", shell_exit},
		 {"env", shell_env}, {"setenv", shell_setenv },
						 {"unsetenv", shell_unsetenv}};
	int i = 0;
	int result = -1;

	while (i < NO_COMMANDS)
	{
		result =  _strcmp(av[0], commands[i].command);
		if (result == 0)
		{
			commands[i].function(av, ac, exit_status);
			return (0);
		}
		i++;
	}
	return (-1);
}
