#ifndef HASHMAP_H
#define HASHMAP_H

int*** newHashMap();

int*   hash(char key);

void   assignValue(int ***map, char key, int value);


#endif