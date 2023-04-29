#include "lists.h"

/**
 * free_list - Function that frees a list_t list.
 * @head: This is the linked listi
 */

void free_list(list_t *head)
{

	if (head == NULL)
	{
		return;
	}
	while (head != NULL)
	{
		list_t *temp;

		temp = head;
		free(temp->str);
		free(temp);
		head = head->next;
	}
}
