#include "main.h"

/**
 * set_bit - At a Given Indx, the value will be Set Of  Bit To 1.
 *
 * @n: a Decimal Num will be Passed By A Pointer
 *
 * @index: Change the Indx Position, it will Start From 0.
 *
 * Return: if working will be 1, If Error will be -1.
 */
int set_bit(unsigned long int *n, unsigned int index)

{
	unsigned long int c;

	if (index > 64)
		return (-1);

	for (c = 1; index > 0; index--, c *= 2)
		;
	*n += c;

	return (1);
}
