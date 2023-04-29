#include "lists.h"
#include <stdlib.h>
/**
 * free_list - free a linked list.
 * @head: head of the linked list to free.
  *
 * Return: nothing.
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
