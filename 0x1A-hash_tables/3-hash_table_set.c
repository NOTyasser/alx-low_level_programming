#include "hash_tables.h"
/**
 * hash_table_set - Creates a new node and assigns key and value to it.
 * @ht: hash table you want to add or update the value/value to
 * @key: the key; cannot be empty
 * @value: value associated with the key.
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *temp;
	unsigned long int index;

	if (key == 0 || ht == NULL)
		return (0);
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	index = key_index((void *)key, ht->size);
	temp = ht->array[index];
	if (!temp)
	{
		temp = ht->array[index];
		while (!temp)
		{
			if (!strcmp(temp->key, node->key))
				return (1);
			temp = temp->next;
		}
		node->next = ht->array[index];
		ht->array[index] = node;
	}
	else
		node->next = NULL, ht->array[index] = node;
	return (1);
}
