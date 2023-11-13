#include "command.h"
#include "strings.h"

int is_built_in_commnad(char **av, int *ac)
{
    command_t commands[NO_COMMANDS] = {{"cd" , _cd}, {"exit", exit}};
    int i = 0;
    int result = -1;

    while (i < NO_COMMANDS)
    {
        result =  _strcmp(av[0], commands[i].command);
        if (result == 0)
        {
            commands[i].function(av, ac);
            return (0);
        }
        i++;
    }
    return (-1);
}

