#include "lists.h"

/**
 * insert_nodeint_at_index- add node at the nth index
 *
 * @head: head of the node
 *
 * @index: index
 *
 * @new: struct int
 *
 * Return: listint_t
 */

listint_t *insert_nodeint_at_index(listint_t **head,
	unsigned int index, int n)
{
	unsigned int count = 0;
	listint_t *curr_node, *new_node = malloc(sizeof(listint_t));

	if (head == NULL || new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (!index)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	curr_node = *head;

	while (curr_node)
	{
		if (count == (index - 1))
		{
			new_node->next = curr_node->next;
			curr_node->next = new_node;
			return (new_node);
		}
		count++;
		curr_node = curr_node->next;
	}
	free(new_node);

	return (NULL);
}
