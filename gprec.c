#include "main.h"

/**
 * get_precision - Calculates the precision
 * @fmt: Formatted string
 * @a: args
 * @arr: list of args.
 *
 * Return: Precision.
 */
int get_precision(const char *fmt, int *a, va_list arr)
{
	int curr_a = *a + 1;
	int precision = -1;

	if (fmt[curr_a] != '.')
		return (precision);

	precision = 0;

	for (curr_a += 1; fmt[curr_a] != '\0'; curr_a++)
	{
		if (is_digit(format[curr_a]))
		{
			precision *= 10;
			precision += fmt[curr_a] - '0';
		}
		else if (fmt[curr_a] == '*')
		{
			curr_a++;
			precision = va_arg(arr, int);
			break;
		}
		else
			break;
	}

	*a = curr_a - 1;

	return (precision);
}
