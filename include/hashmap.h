#ifndef HASHMAP_H
#define HASHMAP_H

struct HashTable* newHashMap();

int    hash_function(char* key, int key_length);

void   assignValue(struct HashTable *table, char* key, void* value);

void*  getValue(struct HashTable *table, char* key);

struct HashEntry
{
    void* key;
    void* value;
};

struct HashTable
{
    struct HashEntry** entries;
    int size;
    int* (*hash_function)(char *, int);
};

#endif