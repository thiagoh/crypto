cmake_minimum_required(VERSION 2.8)

file(GLOB SOURCES impl/*.cpp)
include_directories(include)

add_executable(myapp main.cpp ${SOURCES})
add_library(app_project main.cpp ${SOURCES})

install(TARGETS myapp DESTINATION bin)

find_package( Boost REQUIRED COMPONENTS thread system)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(myapp ${Boost_LIBRARIES} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_link_libraries(myapp crypto ssl)

find_package(OpenSSL)
include_directories(${OpenSSL_INCLUDE_DIRS})
target_link_libraries ( myapp ${OpenSSL_LIBRARIES} )

#set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /data/dev/cpp/cpp-netlib/build )
#find_package ( cppnetlib 0.11.0 REQUIRED )
#include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )
#target_link_libraries ( myapp ${CPPNETLIB_LIBRARIES} )

target_link_libraries( myapp ${ITK_LIBRARIES})
