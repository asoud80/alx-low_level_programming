#include "lists.h"

/**
* add_dnodeint_end - Function
*
* @head: Double Pointer To 1st Node Of List
*
* @n: New Node's Data
* Description: a Function To Add New Node At End Of dbl Linkd_List
*
* Return: Address Of New Element Or NULL If Fail
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *newNode;
	dlistint_t *lastNode;
	int num = n;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = num;
	newNode->next = NULL;

	if (*head == NULL)
	{
		newNode->prev = NULL;
		*head = newNode;
		return (newNode);
	}
	lastNode = *head;
	while (lastNode->next != NULL)
		lastNode = lastNode->next;
	lastNode->next = newNode;
	newNode->prev = lastNode;

	return (newNode);
}
