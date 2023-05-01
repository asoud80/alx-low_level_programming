#include "lists.h"

/**
 * get_nodeint_at_index - function to find nth of node
 * @head: address of the first node in a list
 * @index: position of the node to find (starting from 0)
 * @Return: this is the return of node address.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (head == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < index; i++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}
	return (head);
}

