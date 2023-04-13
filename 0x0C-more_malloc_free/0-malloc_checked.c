#include <stdio.h>
#include <stdlib.h>

/**
*malloc_checked - function that allocates memory using malloc.
*
*@b: This is the length to allocate in the memory
*
*Return: Returns a pointer to the allocated memory
*if malloc fails, the malloc_checked function should cause normal 
*process
*termination with a status value of 98
*
*/
void *malloc_checked(unsigned int b)
{
	char *i;

	i = malloc(b);
		if (i == NULL)
		exit(98);
		else
	return (i);
}
