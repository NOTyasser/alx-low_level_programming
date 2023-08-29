#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - function that frees a listint_t list
 * @head: the head of list to free
 * Return: void of listint
 */
void free_listint(listint_t *head)
{
	listint_t *next;

	if (head == NULL)
		return;

	for (next = head->next; head != NULL; head = next)
	{
		next = head->next;
		free(head);
	}
}
