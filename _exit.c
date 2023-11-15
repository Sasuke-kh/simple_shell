#include <stdlib.h>
#include "memory_manager.h"
#include "strings.h"
int shell_exit(char **av, int *ac, int *exit_status)
{	
	int status = 0;

	if (*ac > 1)
	{	
		if (!(is_number(av[1])))
		{	
			status = 2;
			print_error("./hsh: ");
			print_error("1: ");
			print_error(av[0]);
			print_error(": Illegal number: ");
			print_error(av[1]);
			print_error("\n");
		}
		else
			status = _atoi(av[1]);
	}
	else
	{
		status = *exit_status;
	}
	free_manager(NULL);
	exit(status);
}
