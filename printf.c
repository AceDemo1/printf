#include "main.h"

/**
 * _printf - Printf
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *fmt, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list arr;
	char buffer[BUFF_SIZE];

	if (fmt == NULL)
		return (-1);

	va_start(arr, fmt);

	for (i = 0; fmt && fmt[i] != '\0'; i++)
	{
		if (fmt[i] != '%')
		{
			buffer[buff_ind++] = fmt[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(fmt, &i);
			width = get_width(fmt, &i, arr);
			precision = get_precision(fmt, &i, arr);
			size = get_size(fmt, &i);
			++i;
			printed = handle_print(fmt, &i, arr, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buff(buffer, &buff_ind);

	va_end(arr);

	return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buff(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
