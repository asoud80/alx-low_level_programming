#include <stdio.h>

/**
 * _memset -fill memory with constant values
 * @s: pointer to char params
 * @b: constant byte
 * @n: byte of mem area
 * Return: *s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int alx;

	for (alx = 0; alx < n; alx++)
	{
	s[alx] = b;
	}
	return (s);
}
