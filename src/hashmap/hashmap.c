#include<hashmap.h>
#include<stdlib.h>
#include<stdio.h>

const int MINIMUM_TABLE_SIZE = 32;

struct HashTable* newHashMap(){
    struct HashTable *table;
    table = malloc(sizeof(struct HashTable*));
    table->entries = malloc(sizeof(struct HashEntry*) * MINIMUM_TABLE_SIZE);
    table->size = MINIMUM_TABLE_SIZE;
    table->hash_function = &hash_function;
};

int* hash_function(char* key){

    int hash[2];
    int *hash_pt = hash; 
    int key_int = (int)*key;

    hash[0] = key_int/32;
    hash[1] = key_int%32;

    return hash_pt;

}

// void assignValue(int ***map, char key, int value){
//     int* hash_pointer = hash(key);
//     int hash_index = hash_pointer[0];
//     int bucket_index = hash_pointer[1];

//     if (map[hash_index] == NULL){
//         map[hash_index] = malloc(sizeof(int*) * 32);
//     }
//     if (map[hash_index][bucket_index] == NULL){
//         map[hash_index][bucket_index] = malloc(sizeof(int));
//     }
//     *map[hash_index][bucket_index] = value;
// }

// int* getValue(int ***map, char key){
//     int *hash_pointer = hash(key);
//     if (map[hash_pointer[0]] == NULL) {
//         return NULL;
//     }
//     else if (map[hash_pointer[0]][hash_pointer[1]] == NULL)
//     {
//         return NULL;
//     }
//     else {
//         return map[hash_pointer[0]][hash_pointer[1]];
//     }
    
// }