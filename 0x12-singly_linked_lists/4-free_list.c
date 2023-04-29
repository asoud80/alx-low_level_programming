#include "lists.h"
#include <stdlib.h>
/**
 * free_list - Frees a list_t list.
 * @head: A pointer to the head node of the list.
 *
 * Description: This function frees each node of a list_t linked list.
 *
 * Return: Nothing.
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next;
		free(head->str);
		free(head);
		head = temp;
	}
}
