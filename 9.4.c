// Algorithm 3 Searching a key with an open addressing hashtable

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HASHTABLESIZE 11
#define PRIME 7

typedef struct {
    int key[HASHTABLESIZE];
    int state[HASHTABLESIZE];
    /* -1 = lazy delete, 0 = empty, 1 = occupied */
} hashtable;

/* The hash function */
int hash(int input);
int hash2(int input);
int hash_linear(int i, int input);
int hash_quadratic(int i, int input);
int hash_random(int i, int input);
int double_hasing(int i, int input);
void open_addressing_insert(int item, hashtable *ht);
int open_addressing_search(int item, hashtable *ht);
void open_addressing_delete(int item, hashtable *ht);

int main()
{
    hashtable ht;
    int item = 1942;
    open_addressing_insert(1055, &ht);
    open_addressing_insert(1492, &ht);
    open_addressing_insert(1776, &ht);
    open_addressing_insert(1812, &ht);
    open_addressing_insert(1918, &ht);
    open_addressing_insert(1942, &ht);
    printf("open_addressing_search(): %d\n", open_addressing_search(item, &ht));
    open_addressing_delete(1942, &ht);
    printf("open_addressing_search(): %d\n", open_addressing_search(item, &ht));
    return 0;
}

int hash(int input)
{
    return input % HASHTABLESIZE;
}

int hash2(int input)
{
    return input % PRIME;
}

int hash_linear(int i, int input)
{
    return (hash(input) + i) % HASHTABLESIZE;
}

int hash_quadratic(int i, int input)
{
    return (hash(input) + i * i) % HASHTABLESIZE;
}

int hash_random(int i, int input)
{
    srand(time(NULL));
    return (hash(input) + rand());
}

int double_hashing(int i, int input)
{
    return (hash(input) + i * hash2(i)) % HASHTABLESIZE;
}

void open_addressing_insert(int item, hashtable *ht)
{
    int hash_value, i;
    hash_value = hash(item);
    i = hash_value;
    while (ht->state[i] == 1)
    {
        if (ht->key[i] == item)
        {
            fprintf(stderr, "Duplicate entry\n");
            exit(1);
        }
        i = double_hashing(i, item);
        if (i == hash_value) 
        {
            fprintf(stderr, "The table is full\n");
            exit(1);
        }
    }
    ht->key[i] = item;
    ht->state[i] = 1;
}   

int open_addressing_search(int item, hashtable *ht)
{
    // get the hash
    int hashIndex = hash(item);

    // move in array until an empty
    while (ht->state[hashIndex] == 1)
    {
        if (ht->key[hashIndex] == item) return ht->key[hashIndex];
        hashIndex = double_hashing(hashIndex, item);
        if (hashIndex == hash(item)) return -1;
    }
    return -1;
}

void open_addressing_delete(int item, hashtable *ht)
{
    // get the hash
    int hashIndex = hash(item);

    // move in the array until an empty
    while (ht->state[hashIndex] == 1)
    {
        if (ht->key[hashIndex] == item) ht->state[hashIndex] = -1;
        hashIndex = double_hashing(hashIndex, item);
    }
}