#include <unistd.h>

/**
 * _putchar - it will Writes Char c into stdout
 *
 * @c: Char To be Printed
 *
 * Return: 1 for  Success
 *
 * On error, return  -1, while errno Set Appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
