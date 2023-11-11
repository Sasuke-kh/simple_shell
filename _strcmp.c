#include "main.h"

/**
* _strcmp - compares the two strings s1 and s2
* @s1: pointer to first string
* @s2: pointer to second string
*
* Return: returns an integer less that, equal to, or greater than zero if
* s1 is found, respectively to be less than, to match, or to be greater than
* s2.
*/

int _strcmp(char *s1, char *s2)
{
	int idx = 0;
	int result = 0;

	while (s1[idx] != '\0' && s2[idx] != '\0' && result == 0)
	{
		result = s1[idx] - s2[idx];
		idx++;
	}

	return (result);
}


int _strncmp(char *s1, char *s2, int n)
{
    int idx = 0;
    int result = 0;

    while ((s1[idx] != '\0') && (s2[idx] != '\0') && (result == 0) && (idx < n))
    {
        result = s1[idx] - s2[idx];
        idx++;
    }

    return (result);
}      
