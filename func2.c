#include "main.h"

/**
 * print_pointer - Prints the value of a pointer
 * @types: List of args
 * @buffer: Buffer
 * @flags:  Calculates flags
 * @width: width
 * @precision: Precision specs
 * @size: Size specs
 * Return: No of chars.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	(void)precision;
	(void)width;
	(void)size;
	
	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/**
 * print_non_printable - Prints ascii
 * @types: List of args
 * @buffer: Buffer
 * @flags:  To Calculate flags
 * @width: width
 * @precision: Precision spec
 * @size: Size specifier
 * Return: No of characters
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';
	return (write(1, buffer, i + offset));
}

/**
 * print_reverse - Prints rev string.
 * @types: List of args
 * @buffer: Buffer
 * @flags:  Calculates flags
 * @width: width
 * @precision: Precision specs
 * @size: Size
 * Return: No of characters
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count;
	
	count = 0;
	i = 0;
	(void)width);
	(void)flags;
	(void)buffer;
	(void)size;

	str = va_arg(types, char *);

	if (str == NULL)
	{
		(void)precision;

		str = ")Null(";
	}
	while (str[i])
		i++;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Print a string rot13.
 * @types: List of args
 * @buffer: Buffer
 * @flags:  Calculates flags
 * @width: width
 * @precision: Precision specs
 * @size: Size
 * Return: No of characters
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *pry;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	pry = va_arg(types, char *);
	(void)buffer;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;
	i = 0;
	j = 0;

	if (pry == NULL)
		pry = "(AHYY)";
	while (pry[i])
	{
		for (in[j])
		{
			if (in[j] == pry[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
			j++;
		}
		if (!in[j])
		{
			x = pry[i];
			write(1, &x, 1);
			count++;
		}
		i++;
	}
	return (count);
}
