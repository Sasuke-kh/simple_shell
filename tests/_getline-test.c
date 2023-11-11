#include "../main.h"
#include "../strings.h"

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
    int d = 3;

	_putchar('$');
	_putchar(' ');
	int fd =  open("testfile", O_RDONLY);
	printf("fd = %d\n", fd);
	while (read != 0 && read != -2)
	{
		read = _getline(&line, &len, fd);
		printf("_getline returns %d\n",read);
		if (read != -1)
			printf("You entered: %s\n", line);
		else
			printf("Error reading the line.\n");
	}
	free(line);
	return (0);
}
