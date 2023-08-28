#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - prepends a node to the listint list
 *
 * @head: head of list to add the node to
 * @n: value to give n in node
 *
 * Return: new head adress
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *ptr;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(listint_t));
	if (ptr == NULL)
		return (NULL);

	ptr->n = n;
	ptr->next = *head;
	*head = ptr;
	return (*head);
}
