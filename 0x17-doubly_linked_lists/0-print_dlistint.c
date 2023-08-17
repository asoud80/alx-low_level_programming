#include "lists.h"

/**
* print_dlistint - Function
*
* @h: Str To Print
* Description: function To Print All Elements In Dlistint_t List
*
* Return: Number Of Nodes
*/

size_t print_dlistint(const dlistint_t *h)
{
	int elements = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		elements++;
	}
	return (elements);
}
