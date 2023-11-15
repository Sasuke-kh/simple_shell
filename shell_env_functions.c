#include "command.h"
#include "env.h"
#include <stdio.h>

int shell_env(__attribute__ ((unused)) char **av, int *ac)
{
	if (*ac == 1)
	{
		print_env();
		return (0);
	}
	else
	{
		printf("Wrong number of arguments\n");
		return (-1);
	}

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

