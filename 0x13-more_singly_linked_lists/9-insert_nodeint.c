#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - function that inserts a new node at a given position
 * @head: the head of the list
 * @idx: the index to add a node at, begging at 0
 * @n: the value of the node to add
 * Return: if success new node adress, otherwise NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *ptr, *prev = NULL;
	int ct = idx;

	if (head == NULL)
		return (NULL);

	for (ptr = *head; ct && ptr != NULL; ct--, ptr = ptr->next)
		prev = ptr;
	if (ct)
		return (NULL);

	ptr = malloc(sizeof(listint_t));
	if (ptr == NULL)
		return (NULL);

	if (prev != NULL)
	{
		ptr->next = prev->next;
		prev->next = ptr;
	}
	else
	{
		ptr->next = NULL;
	}
	if (*head == NULL || idx == 0)
	{
		ptr->next = *head;
		*head = ptr;
	}
	ptr->n = n;
	return (ptr);
}
