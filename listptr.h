#ifndef _LISTPTR_H_
#define _LISTPTR_H_
#include <stddef.h>
/**
 * struct list_ptr - singly linked list
 * @ptr: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure for pointers
 */
typedef struct list_ptr
{
	void *ptr;
	struct list_ptr *next;
} listptr_t;

size_t print_listptr(const listptr_t *p);
size_t list_lenptr(const listptr_t *p);
listptr_t *add_node_ptr(listptr_t **headptr, void *p);
listptr_t *add_node_end_ptr(listptr_t **headptr, void *p);
void free_list_ptr(listptr_t *headptr);
#endif
