#include "unity.h"
#include "test_hashmap.h"
#include "test_heapsort.h"

void setUp(void){



}

void tearDown(void){

}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_heap_sort);
    RUN_TEST(test_allocate_hashmap);
    return UNITY_END();
}