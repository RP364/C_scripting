cmake_minimum_required(VERSION 3.0)
project(C_scripting)


include(FetchContent)
FetchContent_Declare(
  unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(unity)
set(COMMON_SOURCES src/huffman_encoding/encoder.c src/hashmap/hashmap.c src/huffman_encoding/encoder.c src/heapsort/heapsort.c include/hashmap.h include/heapsort.h)
set(HEADER_SOURCES include/hashmap.h include/heapsort.h)
set(TEST_SOURCES tests/test_heapsort.c tests/test_hashmap.c tests/test.c)
set(TEST_HEADERS tests/include/test_heapsort.h tests/include/test_hashmap.h)

add_custom_target(build)
add_executable(compression ${COMMON_SOURCES} ${HEADER_SOURCES})
target_include_directories(compression PRIVATE include)


add_executable(test_compression ${COMMON_SOURCES} ${HEADER_SOURCES} ${TEST_SOURCES} ${TEST_HEADERS})
target_link_libraries(test_compression unity)
target_include_directories(test_compression PRIVATE include tests/include)
add_custom_target(tests)
add_dependencies(tests test_compression)
