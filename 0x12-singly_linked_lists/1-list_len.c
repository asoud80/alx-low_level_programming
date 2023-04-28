#include "lists.h"
/**
 * list_len - functopn that returns the number of elements in a linked list_t
 * list_len.
 *
 * @h: the single list
 *
 * retrun the number of elements in a single list
 */
size_t list_len(const list_t *h)
{
	int count = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		count += 1;
		h = h->next;
	}
	return (count);
}
