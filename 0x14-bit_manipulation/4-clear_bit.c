#include <stdio.h>
#include "main.h"

/**
 * clear_bit - Value Of Bit will be set into 0 At Given Indx
 *
 * @n: Change a Pointer into a Decimal Num
 *
 * @index: Change the Indx Position
 *
 * Return: if working will be 1, If Error will be -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int hld;
	unsigned long int c;

	if (index > 64)
		return (-1);
	hld = index;
	for (c = 1; hld > 0; c *= 2, hld--)
		;

	if ((*n >> index) & 1)
		*n -= c;

	return (1);
}
