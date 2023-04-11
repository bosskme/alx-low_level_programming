#include <string.h>
#include <stdlib.h>

#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key
 * @ht: The hash table to look into
 * @key: The key to look for
 * Return: The value associated with the element, or NULL if key couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int index;
    hash_node_t *tmp;

    if (!ht || !key || !*key)
        return (NULL);

    index = key_index((unsigned char *)key, ht->size);

    tmp = ht->array[index];
    while (tmp)
    {
        if (!strcmp(tmp->key, key))
            return (tmp->value);
        tmp = tmp->next;
    }

    return (NULL);
}
