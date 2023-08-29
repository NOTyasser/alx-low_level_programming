#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end -  adds a new node at the end of a listint_t list
 *
 * @head: head of the list
 * @n: the value to give new node
 *
 * Return: the adress of a new node
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *ptr, *end;

	if (head == NULL)
		return (NULL);
	end = *head;
	if (end != NULL)
		while (end->next != NULL)
			end = end->next;

	ptr = malloc(sizeof(listint_t));
	if (ptr == NULL)
		return (NULL);

	ptr->n = n;
	if (*head == NULL)
	{
		*head = ptr;
		ptr->next = NULL;
	}
	else
	{
		end->next = ptr;
		ptr->next = NULL;
	}
	return (ptr);
}
