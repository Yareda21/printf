#include "main.h"

/**
 * get_flags - Calculate and returns active flags from given flags
 * @format: Formatted string in which to print the arguments
 * @i: pointer to an integer.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j;
	int curr_i;
	int flags = 0;

	/*/ flags that are chars  */
	const char FLAGS_CHAR[6] = {'-', '+', '0', '#', ' ', '\0'};

	/*/ flags that are array */
	const int FLAGS_ARRAY[6] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	/*/ loop itrates through the chars of the formated string */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CHAR[j])
			{
				flags = flags | FLAGS_ARRAY[j];
				break;
			}

		if (FLAGS_CHAR[j] == 0)
			break;
	}

	/*/ sets the value of the pointer to curr_i - 1 */
	*i = curr_i - 1;

	return (flags);
}

