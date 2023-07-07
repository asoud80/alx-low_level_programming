
#include <stdio.h>
#include "main.h"

/**
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
	int lgth;

	if (b == NULL)
		return (0);

	for (lgth = 0; b[lgth]; lgth++)
	{
		if (b[lgth] != '0' && b[lgth] != '1')
			return (0);
	}

	for (pow = 1, tot = 0, lgth--; lgth >= 0; lgth--, pow *= 2)
	{
		if (b[lgth] == '1')
			tot += pow;
	}

	return (tot);
}
