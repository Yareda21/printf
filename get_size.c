#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	/*/ initializing */
	int current_i = *i + 1;
	int size = 0;

	/*/ if we have l - its a long, h its a short */
	if (format[current_i] == 'l')
		size = S_LONG;
	else if (format[current_i] == 'h')
		size = S_SHORT;

	/*/ determining size by the type of arg */
	if (size == 0)
		*i = current_i - 1;
	else
		*i = current_i;

	return (size);
}

