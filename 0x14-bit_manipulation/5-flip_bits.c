#include <stdio.h>
#include "main.h"

/**
 * flip_bits - Converting One Num into Other Num By Flipping Bits.
 *
 * @n: 1st Num
 *
 * @m: Converting the 2nd Num.
 *
 * Return: Nums Of Bits Need To be Flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int dff;
	int count;

	dff = n ^ m;
	count = 0;

	while (dff)
	{
		count++;
		dff &= (dff - 1);
	}

	return (count);
}
