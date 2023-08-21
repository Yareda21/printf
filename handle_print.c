#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: a pointer to a formated string to be printed.
 * @list: List of arguments to be printed.
 * @ind: a pointer to to an integer
 * formating parameters
 * @flags:  shows how the charactor prints = c, d, i, f, p
 * @width: the minimum width of the printed charactor
 * @precision: Precision specification of printed charactor
 * @size: int, that specifies the size of printed charactor
 * @buffer: Buffer array to handle print.
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list,
char buffer[], int flags, int width, int precision, int size)
{
	int i;
	int unknown_len = 0;
	int printed_chars = -1;

	/*/ declaring format array => (fmt, pointer to a func) */
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	/*/ loop through the fmt_types array */
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	/*/ checking for format */
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len = unknown_len + write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len = unknown_len + write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len = unknown_len + write(1, &fmt[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}

