#include "command.h"
#include "env.h"
#include <stdio.h>

int shell_env(char **av, int *ac)
{
	print_env();
	printf("Yeah that is me\n");

}
int shell_setenv(char **av, int *ac)
{
	if(*ac != 3)
	{
		printf("Error wrong number of arguments\n");
		return(-1);	
	}
	else
	{
		if(_setenv(av[1], av[2], 1))
		{
			return (-2);
		}
	}
	return (0);
}
int shell_unsetenv(char **av, int *ac)
{
	if(*ac != 2)
    {
        printf("Error wrong number of arguments\n");
        return(-1);
    }
    else
    {
        if(_unsetenv(av[1]))
        {
            return (-2);
        }
    }
    return (0);
}

