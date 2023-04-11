#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "hash_tables.h"

/**
 * hash_table_set - Add an element to a hash table
 * @ht: The hash table to modify
 * @key: The key to add
 * @value: The value to add or update
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    hash_node_t *new_node, *tmp;

    if (!ht || !key || !*key)
        return (0);

    index = key_index((unsigned char *)key, ht->size);

    tmp = ht->array[index];
    while (tmp)
    {
        if (!strcmp(tmp->key, key))
        {
            free(tmp->value);
            tmp->value = strdup(value);
            return (1);
        }
        tmp = tmp->next;
    }

    new_node = malloc(sizeof(hash_node_t));
    if (!new_node)
        return (0);

    new_node->key = strdup(key);
    new_node->value = strdup(value);
    if (!new_node->key || !new_node->value)
    {
        free(new_node->key);
        free(new_node->value);
        free(new_node);
        return (0);
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return (1);
}
