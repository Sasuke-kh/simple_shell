#include "../main.h"


int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	putchar('$');
	read = _getline(&line, &len, stdin);
	if (read != -1)
		printf("You entered: %s\n", line);
	else
		printf("Error reading the line.\n");
	free(line);
	return (0);
}
