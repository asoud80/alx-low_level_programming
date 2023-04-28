#include "lists.h"

/**
 * print_list - function that prints all the elements of a list_t list.
 *
 * @h: This take the value of the single list
 *
 * Return: Return: the number of nodes
 *         If str is NULL, print [0] (nil)
 */
size_t print_list(const list_t *h)
{
	if (h)
	{
		if (h->str)
			printf("[%d] %s%s", h->len, h->str, "\n");
		else
			printf("[%d} %s%s", 0, "(nil)", "\n");
		if (h->next)
		{
			return (1 + print_list(h->next));
		}
		return (1);
	}
	return (0);
}
