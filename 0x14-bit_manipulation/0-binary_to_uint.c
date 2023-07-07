
#include <stdio.h>
#include "main.h"

/**
 *
 * binary_to_uint - it Converts the Binary Num To Uunsigned Integer.
 *
 * @b: Character String.
 *
 * Return: if there's uncovertable character, it will Convert Decimal Num Or 0
 *
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int tot, pow;
	int length;

	if (b == NULL)
		return (0);

	for (len = 0; b[len]; len++)
	{
		if (b[len] != '0' && b[len] != '1')
			return (0);
	}

	for (pow = 1, tot = 0, len--; len >= 0; len--, pow *= 2)
	{
		if (b[len] == '1')
			tot += pow;
	}

	return (tot);
}
