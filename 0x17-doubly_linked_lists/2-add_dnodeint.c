#include "lists.h"

/**
* dlistint_len - a Function
*
* @h: Pointer To a Head Node Of a List
* Description: a Function To Return NO. Of Elements In Linkd_List
*
* Return: NO. Of Elements
*/

size_t dlistint_len(const dlistint_t *h)
{
	int elements = 0;

	while (h != NULL)
	{
		h = h->next;
		elements++;
	}
	return (elements);
}
