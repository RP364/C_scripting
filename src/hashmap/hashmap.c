#include<hashmap.h>
#include<stdlib.h>
#include<stdio.h>

const int MINIMUM_TABLE_SIZE = 32;

struct HashTable* newHashMap(){
    struct HashTable *table;
    table = malloc(sizeof(struct HashTable*));
    table->entries = malloc(sizeof(struct HashEntry*) * MINIMUM_TABLE_SIZE);
    table->size = MINIMUM_TABLE_SIZE;
    table->hash_function = hash_function;
};

/*
Jenkins One at a Time Hash Function
https://en.wikipedia.org/wiki/Jenkins_hash_function
*/
int hash_function(char* key, int length){

    int hash = 0;

    for (int i =0; i < length; i++){
        
        hash += key[i];
        hash += hash << 10;
        hash ^= hash >> 6;
    }

    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;

    return hash;

}

void assignValue(struct HashTable *table, char* key, void* value){
    int key_length = sizeof(key)/sizeof(char);
    int hash = table->hash_function(key, key_length);
    int entry_index = hash % table->size;

    if (table->entries[entry_index] == NULL){
        table->entries[entry_index] = malloc(sizeof(struct HashEntry));
    }
    table->entries[entry_index]->key = key;
    table->entries[entry_index]->value = value;
}

void* getValue(struct HashTable *table, char* key){
    int key_length = sizeof(key)/sizeof(char);
    int hash = table->hash_function(key, key_length);
    int entry_index = hash % table->size;
    if (table->entries[entry_index] == NULL) {
        return NULL;
    }
    else {
        return table->entries[entry_index]->value;
    }
    
}