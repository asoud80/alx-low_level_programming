#include "lists.h"

/**
* free_dlistint - Function
*
* @head: Pointer To 1st Node Of dbl Linkd_List
* Decription: Function To Free dbl Linkd_List
*
* Return: if success 0.
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *temph = head;

	if (head == NULL)
		return;

	while (head->next != NULL)
	{
		temph = head;
		head = head->next;
		free(temph);
	}
	free(head);
}
