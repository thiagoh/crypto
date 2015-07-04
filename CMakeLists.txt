cmake_minimum_required(VERSION 2.8)

#set(CMAKE_C_COMPILER "gcc-4.2")
#set(CMAKE_CXX_COMPILER "/usr/bin/clang++-3.6")
#set(CMAKE_CXX_LINK_EXECUTABLE "/usr/bin/clang++-3.6")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

project(app_project)

file(GLOB SOURCES src/impl/*.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} src/include)

add_executable(myapp main.cpp ${SOURCES})

install(TARGETS myapp DESTINATION bin)

find_package( Boost REQUIRED COMPONENTS thread system)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(myapp ${Boost_LIBRARIES})
target_link_libraries(myapp crypto ssl)

find_package(OpenSSL)
include_directories(${OpenSSL_INCLUDE_DIRS})
target_link_libraries ( myapp ${OpenSSL_LIBRARIES} )

#set ( CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /data/dev/cpp/cpp-netlib-build )
set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /data/dev/cpp/cpp-netlib/build )
find_package ( cppnetlib 0.11.0 REQUIRED )
include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )
target_link_libraries ( myapp ${CPPNETLIB_LIBRARIES} )

target_link_libraries( myapp ${ITK_LIBRARIES})
