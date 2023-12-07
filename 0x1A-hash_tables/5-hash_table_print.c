#include "hash_tables.h"

/**
 * hash_table_print - function that prints a hash table.
 * @ht: pointer to hash table to be printed.
 *
 * Return: No return.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *temp;
	unsigned long int i = 0, n = 0;

	if (!ht)
		return;
	printf("{");

	for (i = n; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			temp = ht->array[i];
			while (temp)
			{
				printf("%s'%s': '%s'", n == 0 ? "" : ", ",
					   temp->key, temp->value),
					n++;
				temp = temp->next;
			}
		}
	}
	printf("}\n");
}
