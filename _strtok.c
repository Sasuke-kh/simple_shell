#include "main.h"

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

	if (str != NULL)
		token = str;
	if (token == NULL || *token == '\0')
		return (NULL);
	current_token = token;
	while (*token != '\0')
	{
		for (d = delim; *d != '\0'; d++)
		{
			if (*token == *d)
			{
				*token = '\0';
				next_token = token + 1;
				token = next_token;
				return (current_token);
			}
		}
		token++;
	}
	return (current_token);
}
