#include "lists.h"

/**
 * free_listint2 - frees a list
 * @head: address of the first node of a list.
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head == NULL)
		return;

		while (*head != NULL)
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
		}
}
