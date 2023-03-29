#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: Pointer to current index in the format string
 * @list: va_list of arguments to be printed
 *
 * Return: Precision
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	/* If the next character is not '.', return -1 */
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;
	curr_i++;

	/* If the next character is '*', get precision from arguments */
	if (format[curr_i] == '*')
	{
		curr_i++;
		precision = va_arg(list, int);
	}
	else
	{
		/* Get precision from characters in format string */
		while (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
			curr_i++;
		}
	}

	*i = curr_i - 1;

	return (precision);
}
