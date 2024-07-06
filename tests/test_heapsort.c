#include "unity.h"
#include "heapsort.h"

void setUp(void){



}

void tearDown(void){

}

void test_heap_sort(void){
    int test_frequencies[5] = {3,4,2,5,1};
    char test_characters[5] = {'a', 'b', 'c', 'd', 'e'};
    int expected_frequencies[5] = {1,2,3,4,5};
    int expected_characters[5] = {'e', 'c', 'a', 'b', 'd'};

    sort(&test_frequencies[0], &test_characters[0], 5);

    TEST_ASSERT_EQUAL_INT32_ARRAY(expected_frequencies, test_frequencies, 5);

}


int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_heap_sort);
    return UNITY_END();
}