#include "main.h"

/**
 * get_flags - Calculates active flags
 * @fmt: Formatted string
 * @a: parameter
 * Return: Flags:
 */
int get_flags(const char *fmt, int *a)
{
	int j, curr_a;

	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	curr_a = *a + 1;

	while (fmt[curr_a] != '\0')
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (fmt[curr_a] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
		curr_a++;
	}
	*a = curr_a - 1;

	return (flags);
}
