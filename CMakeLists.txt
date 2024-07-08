cmake_minimum_required(VERSION 3.0)
project(C_scripting)


include(FetchContent)
FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(unity)
add_executable(test_heapsort src/huffman_encoding/encoder.c src/hashmap/hashmap.c src/huffman_encoding/encoder.c src/heapsort/heapsort.c include/hashmap.h include/heapsort.h tests/test_heapsort.c)
target_link_libraries(test_heapsort unity)
target_include_directories(test_heapsort PRIVATE include)

add_executable(test_hashmap src/huffman_encoding/encoder.c src/hashmap/hashmap.c src/huffman_encoding/encoder.c src/heapsort/heapsort.c include/hashmap.h include/heapsort.h tests/test_heapsort.c)
target_link_libraries(test_hashmap unity)
target_include_directories(test_hashmap PRIVATE include)
