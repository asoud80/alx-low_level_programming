#include "lists.h"
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
