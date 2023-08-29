#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: head of list
 * Return:  the head node’s data (n)
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (0);

	n = (*head)->n;
	next = (*head)->next;
	free(*head);
	*head = next;
	return (n);
}
