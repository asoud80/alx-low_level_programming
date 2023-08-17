#include "lists.h"

/**
* sum_dlistint - Function
*
* @head: Pointer To 1st Node in dbl Linkd_List
* Description: a Function To Return Sum Of All data (N) In dbl List
*
* Return: Sum Of Data Or 0
*/

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *temph;
	int sum = 0;

	if (head == NULL)
		return (0);

	temph = head;
	while (temph != NULL)
	{
		sum += temph->n;
		temph = temph->next;
	}
	return (sum);
}
