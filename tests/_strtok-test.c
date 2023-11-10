#include "../main.h"

int main(void)
{
	char str[] = "This,is,a,test";
	char* delim = ",";
	char* token = _strtok(str, delim);

	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, delim);
	}
	return (0);
}
