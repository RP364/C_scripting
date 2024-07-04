#ifndef HEAPSORT_H
#define HEAPSORT_H

#define LEFT(a) (2*a + 1)

#define RIGHT(a) (2*a + 2)


void sort_character_map(int* count_array, char* character_array, int index, int length);

void sort(int* count_array, char* character_array, int length);

void swap(int* count_array, char* character_array, int index1, int index2);

#endif