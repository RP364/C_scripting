#ifndef HASHMAP_H
#define HASHMAP_H

struct HashTable* newHashMap();

int*   hash_function(char* key);

void   assignValue(int ***map, char key, int value);

int*   getValue(int ***map, char key);

struct HashEntry
{
    void* key;
    void* value;
};

struct HashTable
{
    struct HashEntry** entries;
    int size;
    int* (*hash_function)(char *);
};

#endif