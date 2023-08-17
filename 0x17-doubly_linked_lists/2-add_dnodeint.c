#include "lists.h"

/**
* add_dnodeint - a Function
*
* @head: Double Pointer To First Node
*
* @n: a New Node Data To be Added
* Description: a Function To Add New Node To Beginning Of dbl linkd_List
*
* Return: address Of New Element
*/

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode;
	int num = n;

	newNode = malloc(sizeof(dlistint_t));

	if (newNode == NULL)
		return (NULL);
	newNode->n = num;
	newNode->next = *head;
	newNode->prev = NULL;

	if (*head != NULL)
		(*head)->prev = newNode;

	*head = newNode;
	return (newNode);
}
