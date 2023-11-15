#include "memory_manager.h"
#include <stdlib.h>
#include "listptr.h"
#include <stdio.h>

/**
 * free_manager - free used malloc
 * @ptr: pointer to mallocs
 * Return: voin oc
 */

void free_manager(void *ptr)
{
	static listptr_t *headptr;

	if (ptr != NULL)
	{
		add_node_end_ptr(&headptr, (void *)ptr);
	}
	else
	{
		free_list_ptr(headptr);
	}
}

/**
 * _malloc - free used malloc
 * @size: linked list
 * Return: voin oc
 */

void *_malloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr)
		free_manager(ptr);

	return (ptr);
}
