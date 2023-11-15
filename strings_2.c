#include "strings.h"
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
	dup_str = (char *)_malloc(size);
	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		dup_str[i] = str[i];
	}
	return (dup_str);
}

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

/**
 * _strncmp - compair strings
 * @s1: str 1
 * @s2: str 2
 * @n: idk
 * Return: idk
 */

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

/**
 * _strtok - splits an array of srings
 * @str: the splited array of strings
 * @delim: the delemiter signe
 * Return: spleted string on succses and NULL if there is no more tokens
 */

char *_strtok(char *str, const char *delim)
{
	static char *token;
	static char *next_token;
	char *current_token;
	const char *d;
	static int prev_not_d;

	if (str != NULL)
	{
		token = str;
		prev_not_d = 0;   /* in case of new string but not first call*/
	}
	if (token == NULL || *token == '\0')
		return (NULL);
	current_token = token;
	while (*token != '\0')
	{
		d = delim;

		if (*token == *d)
		{
			if ((prev_not_d))
			{
				*token = '\0';
				next_token = token + 1;
				token = next_token;
				prev_not_d = 0;
				return (current_token);
			}
			else
				current_token++;
			prev_not_d = 0;
		}
		else
			prev_not_d = 1;
		token++;
	}
	if (prev_not_d)
		return (current_token);
	else
		return (NULL);
}
