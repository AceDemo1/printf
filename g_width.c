#include "main.h"

/**
 * get_width - Calculates the width
 * @fmt: Formatted string
 * @a: List of args
 * @arr: list of args.
 * Return: width.
 */
int get_width(const char *fmt, int *a, va_list arr)
{
	int curr_a;
	int width = 0;

	for (curr_a = *a + 1; fmt[curr_a] != '\0'; curr_a++)
	{
		if (is_digit(fmt[curr_a]))
		{
			width *= 10;
			width += fmt[curr_a] - '0';
		}
		else if (fmt[curr_a] == '*')
		{
			curr_a++;
			width = va_arg(arr, int);
			break;
		}
		else
			break;
	}
	*a = curr_a - 1;
	return (width);
}
