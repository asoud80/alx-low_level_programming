#include "main.h"

/**
 * clear_bit - clears the bit at index
 * @n: the number to index
 * @index: the bit to clear
 *
 * Return: 1 for success, -1 for error.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	if (*n & 1L << index)
		*n ^= 1L << index;
	return (1);
}
