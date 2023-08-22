#include "main.h"
/**
 * print_buffer - Prints the buffer if it exist
 * @buffer: Array of chars - which is a string entered
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - denotes Printf function
 * @format: the format specified.
 * Return: the return statement returns chars.
 */
int _printf(const char *format, ...)
{
	int i;
	int printed = 0;
	int printed_chars = 0;/* defining parameters */
	int flags, width, precision, size;
	int buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list list_arg;

	va_start(list_arg, format);
	if (format == NULL)
	{
		return (-1);
	}
	for (i = 0; format && format[i] != '\0'; i++)
	{/* looping through format string */
		if (format[i] != '%')
		{/* if the char is not format specifier */
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{/* calling and clearing buffer */
			print_buffer(buffer, &buff_ind);/*/ getting the parameters */
			flags = get_flags(format, &i);
			width = get_width(format, &i, list_arg);
			precision = get_precision(format, &i, list_arg);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list_arg, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars = printed_chars + printed;
		}
	}

	va_end(list_arg);/*/ performing argument cleanup */
	return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
