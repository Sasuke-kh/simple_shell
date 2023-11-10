#include "main.h"
#include <stdlib.h>

/**
* _strdup - created duplicate to string
* @str: char pointer to string to be duplicated
*
* Return: char pointer to duplicated string
*/
char *_strdup(char *str)
{
	unsigned int size = 0, i = 0;
	char *dup_str;

	if (str == NULL)
		return (NULL);

	while (str[size] != '\0')
		size++;

	size++; /* null terminator*/
	dup_str = (char *)malloc(size);
	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		dup_str[i] = str[i];
	}
	return (dup_str);
}
