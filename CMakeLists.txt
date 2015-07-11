cmake_minimum_required(VERSION 2.8)

project(crypto_c)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")

add_subdirectory(src)
add_subdirectory(test)

enable_testing()