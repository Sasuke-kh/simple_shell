#include "command.h"
#include "env.h"
#include <stdio.h>
#include "strings.h"

int shell_env(__attribute__ ((unused)) char **av, int *ac, __attribute__ ((unused)) int *exit_status)
{
	if (*ac == 1)
	{
		print_env();
		return (0);
	}
	else
	{
		print_error("Wrong number of arguments");
		print_str("\n");
		return (-1);
	}

}
int shell_setenv(char **av, int *ac, __attribute__ ((unused)) int *exit_status)
{
	if(*ac != 3)
	{
		print_error("Error wrong number of arguments");
		print_error("\n");
		return(-1);	
	}
	else
	{
		if(_setenv(av[1], av[2], 1))
		{         
			print_error("Error Can't unset env");
            print_error("\n");
			return (-2);
		}
	}
	return (0);
}
int shell_unsetenv(char **av, int *ac, __attribute__ ((unused)) int *exit_status)
{
	if(*ac != 2)
	{
		print_error("Error wrong number of arguments");
		print_error("\n");
		return(-1);
	}
	else
	{
		if(_unsetenv(av[1]))
		{	
			print_error("Error Can't unset env");
			print_error("\n");
			return (-2);
		}
	}
	return (0);
}

