#include "unity.h"
#include "hashmap.h"
#include <stdlib.h>

void test_allocate_hashmap(void){

    struct HashTable* hash_table = newHashMap();


    TEST_ASSERT_EQUAL(hash_table->size, 32);

}

void test_assign_get_one_value(void){

    struct HashTable* hash_table = newHashMap();

    char key[] = "abc";
    int value;
    int expected_value = 1;
    void* expected_value_ptr = &expected_value;
    void* value_ptr;


    assignValue(hash_table, key, expected_value_ptr);
    
    value_ptr = getValue(hash_table, key);

    value = *(int*)value_ptr;

    TEST_ASSERT_EQUAL(value, 1);

}

void test_assign_get_multiple_values(void){

    struct HashTable* hash_table = newHashMap();

    char key[] = "abc";
    char key2[] = "abcd";

    int expected_value_1 = 1;
    void* expected_value_ptr_1 = &expected_value_1;

    int expected_value_2 = 2;
    void* expected_value_ptr_2 = &expected_value_2;

    void* value_ptr_1;
    void* value_ptr_2;

    int value_1;
    int value_2;
    
    assignValue(hash_table, key, expected_value_ptr_1);    
    value_ptr_1 = getValue(hash_table, key); 

    assignValue(hash_table, key, expected_value_ptr_2);
    value_ptr_2 = getValue(hash_table, key);

    value_1 = *(int*)value_ptr_1;
    value_2 = *(int*)value_ptr_2;

    TEST_ASSERT_EQUAL(value_1, 1);
    TEST_ASSERT_EQUAL(value_2, 2);

}

