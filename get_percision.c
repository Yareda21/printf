#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string
 * @i: List of arguments that will be printed
 * @list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1, precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/*/ itrating through the format */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		/*/ checking the input if it is a digit */
		if (is_digit(format[curr_i]))
		{
			precision = precision * 10;
			precision = precision + format[curr_i] - '0';
		}
		/*/ it is a * */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	/* / now return the percision */
	return (precision);
}

