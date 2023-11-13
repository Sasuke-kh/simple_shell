#include <stdlib.h>
#include "memory_manager.h"
#include "strings.h"
int shell_exit(char **av, int *ac)
{	
	int i = 0;

	if (*ac > 1)
	{
		i = atoi(av[1]);
		free_manager(NULL);	
		exit(i);
	}
	else
	{
		free_manager(NULL);	
		exit(0);
	}
}
