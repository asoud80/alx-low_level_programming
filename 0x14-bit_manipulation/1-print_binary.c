#include <stdio.h>
#include "main.h"

/**
 * print_binary - Binary Representation Of Num will be printed
 *
 * @n: print a Decimal Numb As a Binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int tmp;
	int shft;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (tmp = n, shft = 0; (tmp >>= 1) > 0; shft++)
		;

	for (; shft >= 0; shft--)
	{
		if ((n >> shft) & 1)
			printf("1");
		else
			printf("0");
	}
}
