#include "lists.h"

/**
 * free_listint - function that frees a listint list
 * @head: input header pointer
 * Return nothing
 */
void free_listint(listint_t *head)
{
	listint_t *nptr;

	while (head != NULL)
	{
		nptr = head;
		head = head->next;
		free(nptr);
	}
}

