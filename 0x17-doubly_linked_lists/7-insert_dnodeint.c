#include "lists.h"

/**
* insert_dnodeint_at_index - Function
*
* @h: Double Pointer To 1st Node Of dbl Linkd_List
*
* @idx: Indx To Where New Node Is Added
*
* @n: Data Of New Node
* Description: a Function To Insert New Node At Given Indx
*
* Return: address Of New Node Or NULL If Fail.
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *newNode, *temph = *h;
	unsigned int toindex = 0;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = n;
	if (*h == NULL)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		*h = newNode;
		return (newNode);
	}
	if (idx == 0)
		return (add_dnodeint(h, n));
	while (toindex < idx - 1)
	{
		if (temph == NULL)
			return (NULL);
		temph = temph->next;
		toindex++;
	}
	if (temph->next == NULL)
	{
		temph->next = newNode;
		newNode->prev = temph;
		newNode->next = NULL;
		return (newNode);
	}
	newNode->next = temph->next;
	temph->next = newNode;
	newNode->prev = temph;
	newNode->next->prev = newNode;
	return (newNode);
}
