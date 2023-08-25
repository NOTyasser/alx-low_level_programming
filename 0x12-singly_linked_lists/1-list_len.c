#include "lists.h"
#include <stdio.h>

/**
 * list_len - returns the number of the nodes starting at the element h
 *
 * @h: the first node of linked list to the count form
 *
 * Return: the number of the nodes printed
 */
size_t list_len(const list_t *h)
{
	size_t len = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		len++;
		h = h->next;
	}
	return (len);
}
