#include "main.h"

/**
 * _memset -ironnou
 * @s:pointer to char pramas
 * @b:data to change
 * @n: index
 * return: *s
 */

char * _memset(char * s, char b, unsigned int n)
{
unsigned int n;

	for (i =0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}
