#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - creates a new hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created hash table
 *         NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *hash_table;
    unsigned long int i;

    /* Allocate memory for the hash table */
    hash_table = malloc(sizeof(hash_table_t));
    if (hash_table == NULL)
        return (NULL);

    /* Allocate memory for the array */
    hash_table->array = malloc(sizeof(hash_node_t *) * size);
    if (hash_table->array == NULL)
    {
        free(hash_table);
        return (NULL);
    }

    /* Initialize each element of the array to NULL */
    for (i = 0; i < size; i++)
        hash_table->array[i] = NULL;

    /* Set the size of the hash table */
    hash_table->size = size;

    /* Return a pointer to the hash table */
    return (hash_table);
}
