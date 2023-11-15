#include "main.h"
/**
* _atoi - converts string to int
* @s: string int to be converted
*
* Return: int
*/
int _atoi(char *s)
{
	int i = 0, start_i = 0, end_i = 0;
	int digit_encountered = 0;
	int minus_count = 0;
	int mul_10 = 1;
	unsigned int result = 0;

	while (s[i] != 0)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (!(digit_encountered))
				start_i = i;
			end_i = i;
			digit_encountered = 1;
		}
		else
		{
			if (digit_encountered)
			{
				break;
			}
			else
			{
				if (s[i] == '-')
					minus_count++;
			}
		}
		i++;
	}
	if (!(digit_encountered))
		return (0);
	result = ((int)s[end_i] - (int)'0');
	for (i = end_i - 1; i >= start_i; i--)
	{	mul_10 *= 10;
		result += ((int) s[i] - (int)'0') * mul_10;
	}
	if (minus_count % 2)
		result = (int)-(result);
	return ((int)(result));
}

/**
 * is_number - idk
 * @str: idk
 * Return: idk
 */

int is_number(char *str)
{
	int result = 1;

	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			result = 0;
			break;
		}
		str++;
	}
	return (result);
}
