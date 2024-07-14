#include "unity.h"
#include "hashmap.h"

void test_allocate_hashmap(void){

    struct HashTable* hash_table = newHashMap();


    TEST_ASSERT_EQUAL(hash_table->size, 32);

}
