#include "free_manager.h"
#include <stdlib.h>
#include "listptr.h"

void free_manager(void *ptr)
{
	static listptr_t *headptr = NULL;
	if (ptr != NULL)
	{
		add_node_end_ptr(&headptr, ptr);
	}
	else
	{
		free_list_ptr(headptr);
	}
}
