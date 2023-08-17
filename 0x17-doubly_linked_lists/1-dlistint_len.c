i#include "lists.h"

/**
* dlistint_len - Function
*
* @h: Pointer To Head Node Of a List
* Description: Function To Return Number Of Elements In Lnkd List
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
