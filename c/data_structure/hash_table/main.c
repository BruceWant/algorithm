#include "hash_table.h"
#include <stdio.h>

int main()
{
    ht_hash_table* ht = ht_new();
    if (ht == NULL)
        printf("ht: NULL\n");
    ht_insert(ht, "first", "test");
    printf("%s\n", ht_search(ht, "first"));
    ht_del_hash_table(ht);
}
