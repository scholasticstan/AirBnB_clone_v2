/**
 * hash_djb2 - implements the djb2 algorithm
 * @str: string to hash
 *
 * Return: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash = 5381;
    int c;

    while ((c = *str++) != 0)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash);
}
