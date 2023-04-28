#include "list.h"

/**
 * list_len - find the number of elements in
 * alinked list_t list
 * @h: the linked list_t list
 *
 * return the number of elements in h
 */

size_t list_len(const list_t *h)
{
	size_t elements = 0;

	while (h)
	{
		elements++;
		h = h->next;
	}

	return (elements);
}
