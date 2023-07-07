#include "main.h"

/**
 * get_endianness - Endianness to be Check ed
 *
 * Return: If a Big Endian it will be 0, If a small Endian it will be 0.
 */
int get_endianness(void)
{
	int n;

	n = 1;
	if (*(char *)&n == 1)
		return (1);
	else
		return (0);
}
