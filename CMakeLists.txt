cmake_minimum_required(VERSION 3.22)
project(stackvec C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_library(stackvec
        src/stackvec.c
        include/stackvec.h
)

enable_testing()

add_executable(test_create tests/create.c)
target_link_libraries(test_create PRIVATE stackvec)
add_test(NAME test_create COMMAND $<TARGET_FILE:test_create>)

add_executable(test_add tests/add.c)
target_link_libraries(test_add PRIVATE stackvec)
add_test(NAME test_add COMMAND $<TARGET_FILE:test_add>)

add_executable(test_remove tests/remove.c)
target_link_libraries(test_remove PRIVATE stackvec)
add_test(NAME test_remove COMMAND $<TARGET_FILE:test_remove>)

