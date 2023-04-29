#include "lists.h"
#include <stdlib.h>

/**
 * free_list - frees a list_t lists.
 * @head: A pointer to the head node of the list.
 *
 * Description: this function frees each node of a list_t linked list
 *
 * Retrun nothing
 */

void free_list(list_t *head)
{
	while (head != NULL)
	{
		free(head->str);
		free(head);
		head = head->next;
	}
}
