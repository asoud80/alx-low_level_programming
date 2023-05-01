#include "lists.h"
#include <stdio.h>
#include <stlib.h>

/**
 * get_nodeint_at_index - Function returns to nth of node
 * @head: address of the first node in a list
 * @index: position of the node to find (starting from 0)
 * @Return: this is the return of node address.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;
	if (head == NULL)
		return (NULL);

	while (i != index)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
		i++:
	}
	return (head);
}

