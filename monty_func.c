#include "monty.h"

/**
 * _isdigit - function that check for a digit
 * @str: string to check
 *
 * Return: 1 if its an integer, else 0
 */

int _isdigit(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;

	if (*str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
