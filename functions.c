#include "main.h"

/****** printing charactors *******/

/**
 * print_char - Prints a single char
 * @types: List of arguments passed to the function
 * @buffer: array that will store the char that will be printed
 * formating parameters
 * @flags:  shows how the charactor prints = c, d, i, f, p
 * @width: the minimum width of the printed charactor
 * @precision: Precision specification of printed charactor
 * @size: int, that specifies the size of printed charactor
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	/* / int- the char to be printed (c), buffer- store the char */
	char c = va_arg(types, int);

	/*/ handle write- writing the char to the buffer */
	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/******* PRINTING STRING ******/
/**
 * print_string - Prints a string
 * @types: List of arguments passed to the function
 * @buffer: array that will store the char that will be printed
 * formating parameters
 * @flags:  shows how the charactor prints = c, d, i, f, p
 * @width: the minimum width of the printed charactor
 * @precision: Precision specification of printed charactor
 * @size: int, that specifies the size of printed charactor
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	int length = 0;
	int i;

	char *str = va_arg(types, char *);
	/*/ checking the string is null */
	if (str == NULL)
	{/*/ giving null string to str */
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	/*/ figure out the length of the string */
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)/*/ length takes percision value,*/
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/****** PRINT PERCENT SIGN ******/
/**
 * print_percent - Just prints a percent sign when double percent is available
 * @types: List of arguments passed to the function
 * @buffer: array that will store the char that will be printed
 * formating parameters
 * @flags:  shows how the charactor prints = c, d, i, f, p
 * @width: the minimum width of the printed charactor
 * @precision: Precision specification of printed charactor
 * @size: int, that specifies the size of printed charactor
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/****** PRINT INTEGERS ******/
/**
 * print_int - Prints integers from the buffer
 * @types: List of arguments passed to the function
 * @buffer: array that will store the char that will be printed
 * formating parameters
 * @flags:  shows how the charactor prints = c, d, i, f, p
 * @width: the minimum width of the printed charactor
 * @precision: Precision specification of printed charactor
 * @size: int, that specifies the size of printed charactor
 * Return: The Number of chars printed
 */

int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2, is_negative = 0;

    /*/ converting into long int */
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/****** PRINT BINARY *******/
/**
 * print_binary - Prints binary number
 * @types: List of arguments passed to the function
 * @buffer: array that will store the char that will be printed
 * formating parameters
 * @flags:  shows how the charactor prints = c, d, i, f, p
 * @width: the minimum width of the printed charactor
 * @precision: Precision specification of printed charactor
 * @size: int, that specifies the size of printed charactor
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(types, unsigned int);
	m = 2147483648; /* 2 the power of 31 */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}

	sum = 0;
	count = 0;

	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

