#include "main.h"

/**
 * get_endianness - return endianness of the system
 *
 * Return: 0 for  endian, 1 for small
 */

int get_endianness(void)
{
	unsigned long int n = 1;

	return (*(char *)&n);
}
