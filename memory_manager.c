#include "memory_manager.h"
#include <stdlib.h>
#include "listptr.h"
#include <stdio.h>
void free_manager(void *ptr)
{
	static listptr_t *headptr = NULL;
	if (ptr != NULL)
	{
		add_node_end_ptr(&headptr, (void *)ptr);
	}
	else
	{
		free_list_ptr(headptr); 
	}
}

void *_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr)
		free_manager(ptr);

	return (ptr);
}
