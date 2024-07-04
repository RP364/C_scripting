cmake_minimum_required(VERSION 3.0)
project(C_scripting)
add_executable(compression src/huffman_encoding/encoder.c src/hashmap/hashmap.c src/huffman_encoding/encoder.c src/heapsort/heapsort.c include/hashmap.h include/heapsort.h)
target_include_directories(compression PRIVATE include)