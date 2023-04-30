#include "lists.h"

/**
 * add_nodeint_end - functio that add a new node at the end of listint_t
 * @head: input header pointer
 * @n: input data int
 * Return: the adress of new elements.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *tmp, *ptr;

	tmp = malloc(sizeof(listint_t));
	if (tmp == NULL)
		return (NULL);
	tmp->n = n;
	tmp->next = NULL;
	if (*head == NULL)
		*head = tmp;
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
	}
	return (tmp);
}


