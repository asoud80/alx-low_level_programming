#ifndef LISTS_H
#define LISTS_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/**
* struct dlistint_s - Doubly_Linked_List
*
* @n: Int
*
* @prev: it will Points To a Previous Node
*
* @next: it will Points To Next Node
* Description: Doubly_Linked_List Node Structure
*/

typedef struct dlistint_s
{
	int n;
	struct dlistint_s *next;
	struct dlistint_s *prev;
} dlistint_t;
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
int sum_dlistint(dlistint_t *head);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
#endif /* LISTS_H */
