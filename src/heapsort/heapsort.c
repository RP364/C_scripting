#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include "heapsort.h"

void sort(int* count_array, char* character_array, int length){
    int tmp;
    char tmp_c;

    for (int i = 0; i < length; i++){
        sort_character_map(&count_array[0], &character_array[0], 0, length-i);
        tmp = count_array[0];
        count_array[0] = count_array[length-i-1];
        count_array[length-i-1] = tmp;

        tmp_c = character_array[0];
        character_array[0] = character_array[length-i-1];
        character_array[length-i-1] = tmp_c;

    }

}

void sort_character_map(int* count_array, char* character_array, int index, int length){

    bool has_left, has_right = false;

    if (LEFT(index) < length) {
        has_left = true;
    }


    if (RIGHT(index) < length) {
        has_right = true;
    }

    if (has_left){
        sort_character_map(count_array, character_array, LEFT(index), length);
        if (count_array[LEFT(index)] > count_array[index]){
            swap(count_array, character_array, LEFT(index), index);
        }
    }

    if (has_right){
        sort_character_map(count_array, character_array, RIGHT(index), length);
        if (count_array[RIGHT(index)] > count_array[index]){
            swap(count_array, character_array, RIGHT(index), index);
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
