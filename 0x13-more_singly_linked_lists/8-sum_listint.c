#include "lists.h"

/**
 * sum_listint - sum of all data (n)
 *
 * @head: head of node
 *
 * Return: void
 */

int sum_listint(listint_t *head)
{
	unsigned int count = 0;

	while (head != NULL)
	{
		count += head->n;
		head = head->next;
	}
	return (count);
}
