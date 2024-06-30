#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include<heapsort.h>

void sort_character_map(int* count_array, char* character_array, int index, int length){

    bool has_left, has_right = false;

    if (LEFT(index) < length) {
        has_left = true;
    }


    if (RIGHT(index) < length) {
        has_right = true;
    }

    if (has_left){
        sort(count_array, LEFT(index), length);
        if (count_array[LEFT(index)] > count_array[index]){
            swap(count_array, LEFT(index), index);
        }
    }

    if (has_right){
        sort(count_array, RIGHT(index), length);
        if (count_array[RIGHT(index)] > count_array[index]){
            swap(count_array, RIGHT(index), index);
        }
    }
}

void swap(int* count_array, char* character_array, int index1, int index2){
    int tmp = count_array[index1];
    char tmp_c = character_array[index1];

    count_array[index1] = count_array[index2];
    count_array[index2] = tmp;

    character_array[index1] = character_array[index2];
    character_array[index2] = tmp_c;
}
