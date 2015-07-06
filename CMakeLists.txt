cmake_minimum_required(VERSION 2.8)

project(app_project)

#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
#    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    set(warnings "-Wall -Wextra -Werror")
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
#    set(warnings "/W4 /WX /EHsc")
#endif()
#if (NOT CONFIGURED_ONCE)
#    set(CMAKE_CXX_FLAGS "${warnings}"
#        CACHE STRING "Flags used by the compiler during all build types." FORCE)
#    set(CMAKE_C_FLAGS   "${warnings}"
#        CACHE STRING "Flags used by the compiler during all build types." FORCE)
#endif()

#set(CMAKE_C_COMPILER "gcc-4.2")
#set(CMAKE_CXX_COMPILER "/usr/bin/clang++-3.6")
#set(CMAKE_CXX_LINK_EXECUTABLE "/usr/bin/clang++-3.6")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
#add_test (TestCase1 test)
#add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS test)
