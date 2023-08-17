#include "lists.h"

/**
* get_dnodeint_at_index - Function
*
* @head: Pointer To 1st Node In Linkd_list
*
* @index: Space In Indx To Get Node
* Description: a Function To Return nth Node Of dbl Linkd_List
*
* Return: nth Node Or If Node Doesn't Exist, NULL
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temph;
	unsigned int toindex = 0;

	temph = head;

	while (temph != NULL)
	{
		if (toindex == index)
			return (temph);
		toindex++;
		temph = temph->next;
	}
	if (toindex == 0 || toindex < index)
		return (temph);

	temph = head;
	return (temph->next);
}
