#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"
/**
* list_len - count of number of elements of a list
* @h: pointer to list node
*
* Return: Number of node of list
*/
size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		n++;
		h = h->next;
	}
	return (n);
}
/**
* add_node - prints all elements of a list
* @head: pointer to list node
* @str: IDW
* Return: Number of node of list
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = NULL;
	char *new_string = NULL;
	unsigned int len = 0;

	new_node = (list_t *)_malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);
	new_string = _strdup((char *)str);
	if (new_string == NULL)
	{
		return (NULL);
	}
	len = strlen(new_string);
	new_node->str = new_string;
	new_node->len = len;
	new_node->next = *head;

	*head = new_node;
	return (new_node);
}
/**
 * add_node_end - adds a new node at end of a list
 * @head: double pointer to list
 * @str: string of the new head node
 *
 * Return: pointer to the new node, NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = NULL;
	char *new_string = NULL;
	unsigned int len = 0;
	list_t *trav_node = *head;

	new_node = (list_t *)_malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_string = _strdup((char *)str);
	if (new_string == NULL)
	{
		return (NULL);
	}
	len = strlen(new_string);
	new_node->str = new_string;
	new_node->len = len;
	new_node->next = NULL;
	if (trav_node == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (trav_node->next != NULL)
			trav_node = trav_node->next;
		trav_node->next = new_node;
	}

	return (new_node);
}
