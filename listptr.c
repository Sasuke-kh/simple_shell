#include "listptr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* list_lenptr - count of number of elements of a list
* @p: pointer to list node
*
* Return: Number of node of list
*/
size_t list_lenptr(const listptr_t *p)
{
	size_t n = 0;

	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	return (n);
}
/**
* print_listptr - prints all elements of a list
* @p: pointer to list node
*
* Return: Number of node of list
*/
size_t print_listptr(const listptr_t *p)
{
	size_t n = 0;

	while (p != NULL)
	{
		printf("%p\n", p->ptr);
		n++;
		p = p->next;
	}
	return (n);
}

/**
 * add_node_ptr - free used malloc
 * @headptr: pointer to linked list
 * @p: idk
 * Return: idk
 */

listptr_t *add_node_ptr(listptr_t **headptr, void *p)
{
	listptr_t *new_node = NULL;


	new_node = (listptr_t *)malloc(sizeof(listptr_t));

	if (new_node == NULL)
		return (NULL);


	new_node->ptr = p;
	new_node->next = *headptr;

	*headptr = new_node;
	return (new_node);
}
/**
 * add_node_end_ptr - adds a new node at end of a list
 * @headptr: double pointer to list
 * @p: string of the new head node
 *
 * Return: pointer to the new node, NULL if failed
 */
listptr_t *add_node_end_ptr(listptr_t **headptr, void *p)
{
	listptr_t *new_node = NULL;
	listptr_t *trav_node = *headptr;

	new_node = (listptr_t *)malloc(sizeof(listptr_t));
	if (new_node == NULL)
		return (NULL);


	new_node->ptr = p;

	new_node->next = NULL;
	if (trav_node == NULL)
	{
		*headptr = new_node;
	}
	else
	{
		while (trav_node->next != NULL)
			trav_node = trav_node->next;
		trav_node->next = new_node;
	}

	return (new_node);
}


/**
* free_list_ptr - frees memory ocuupied by single linked list
* @headptr: pointer to head node of linked list
*/
void free_list_ptr(listptr_t *headptr)
{
	listptr_t *trav_node = headptr;
	listptr_t *free_node = NULL;

	while (trav_node != NULL)
	{
		free_node = trav_node;
		trav_node = trav_node->next;
		if (free_node->ptr)
			free(free_node->ptr);
		free(free_node);
	}
}
