#include "main.h"

/**
 * _fgetc - reads characters from stream
 * @stream: characters to read
 * Return: buffer or eof
 */

int _fgetc(FILE *stream)
{
	static char buffer[BUFSIZ];
	static ssize_t buf_pos;
	static ssize_t buf_size;

	if (buf_pos >= buf_size)
	{
		buf_size = read(fileno(stream), buffer, BUFSIZ);
		buf_pos = 0;
		if (buf_size <= 0)
			return (EOF);
	}

	return (buffer[buf_pos++]);
}
