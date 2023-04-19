#include <stdio.h>
#include "FUNCTION_POINTER.H"

/**
 * print_name - prints a name
 * @name: string containing the name
 * @f: pointer to function
 *
 */

void print_name(char *name, void (*f)(char *));
{
	if (f != NULL)
	{
		(f) (name);
	}
}
