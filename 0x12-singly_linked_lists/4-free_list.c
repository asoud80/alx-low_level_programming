#include "lists.h"
#include <stdlib.h>
/**
 * free_list - frees a list_t list
 * @head: A pointer to the head node of the list
 *
 * Description: the function frees each node of a list_t linked list
 *
 * Return nothing
 */
void free_list(list_t *head)
	#include "lists.h"

void free_list(list_t *head)
{
	list_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current->str);
		free(current);
	}
}
