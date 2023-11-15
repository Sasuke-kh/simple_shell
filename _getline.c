#include "main.h"
#include "memory_manager.h"
/**
 * _getline - gets line from stream
 * @lineptr: doc
 * @n: doc
 * @fd: doc
 * Return: number of characters read or -1 on failure
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t i;
	int c;
	size_t new_size;
	char *new_ptr;
	size_t j;

	if (*lineptr == NULL || *n == 0)
	{
		*n = INITIAL_BUFFER_SIZE;
		*lineptr = (char *)_malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1); /*Allocation failure*/
		}
	}
	i = 0;
	while ((c = _fgetc(fd)) != EOF && c != '\n')
	{
		if (i >= *n - 1)
		{
			new_size = *n * 2;
			new_ptr = (char *)_malloc(new_size);
			if (new_ptr == NULL)
				return (-1); /*Allocation failure*/
			for (j = 0; j < *n; j++)
				new_ptr[j] = (*lineptr)[j];
			free(*lineptr);
			*lineptr = new_ptr;
			*n = new_size;
		}
		(*lineptr)[i++] = c;
	}
	if (c == EOF && i == 0)
	{
		return (-2); /*no characters read, and EOF reched*/
	}
	(*lineptr)[i] = '\0';
	return (i); /*number of characters read*/
}
