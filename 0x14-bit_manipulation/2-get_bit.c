#include <stdio.h>
#include "main.h"

/**
 * get_bit - Get Value Of Bit in Given Indx
 *
 * @n: Num To be Evaluated
 *
 * @index: Start the Index From 0, Of a Bit Should b Got
 *
 * Return: the value Of a Bit of an Indx,  incase of Error -1.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int hld;

	if (Indx > 64)
		return (-1);

	hld = n >> Indx;

	return (hld & 1);
}
