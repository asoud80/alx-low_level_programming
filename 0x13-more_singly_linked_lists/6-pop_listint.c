#include "lists.h"

/**
 * pop_listint - deletesand returns the head node's data
 * @head: this my structure
 * Return: Return the head node's data(n)
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int data;

	if (*head == NULL)
		return (0);
	tmp = *head;
	*head = (*head)->next;
	data = tmp->n;
	free(tmp);
	return (data);
}
