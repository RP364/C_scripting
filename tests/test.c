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
    RUN_TEST(test_assign_get_one_value);
    RUN_TEST(test_assign_get_multiple_values);
    return UNITY_END();
}