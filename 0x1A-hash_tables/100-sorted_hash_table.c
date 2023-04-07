int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *node, *temp;

    if (ht == NULL || key == NULL || strcmp(key, "") == 0)
        return 0;

    index = key_index((unsigned char *)key, ht->size);

    /* Check if key already exists */
    temp = ht->array[index];
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            /* Update value if key already exists */
            free(temp->value);
            temp->value = strdup(value);
            return 1;
        }
        temp = temp->next;
    }

    /* Create new node */
    node = malloc(sizeof(shash_node_t));
    if (node == NULL)
        return 0;
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = ht->array[index];
    node->sprev = NULL;
    node->snext = NULL;

    /* Insert node into array */
    ht->array[index] = node;

    /* Insert node into sorted list */
    if (ht->shead == NULL)
    {
        /* Empty list */
        ht->shead = node;
        ht->stail = node;
    }
    else if (strcmp(node->key, ht->shead->key) < 0)
    {
        /* Insert at beginning of list */
        node->snext = ht->shead;
        ht->shead->sprev = node;
        ht->shead = node;
    }
    else
    {
        /* Find insertion position using insertion sort */
        temp = ht->shead;
        while (temp->snext != NULL && strcmp(node->key, temp->snext->key) >= 0)
            temp = temp->snext;

        /* Insert node */
        node->snext = temp->snext;
        node->sprev = temp;
        if (temp->snext == NULL)
            ht->stail = node;
        else
            temp->snext->sprev = node;
        temp->snext = node;
    }

    return 1;
}
