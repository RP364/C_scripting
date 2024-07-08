#include "unity.h"
#include "hashmap.h"

void setUp(void){



}

void tearDown(void){

}

void test_allocate_hashmap(void){

    struct HashTable* hash_table = newHashMap();


    TEST_ASSERT_EQUAL(hash_table->size, 32);

}


int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_allocate_hashmap);
    return UNITY_END();
}