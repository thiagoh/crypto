cmake_minimum_required(VERSION 2.8)

file(GLOB SOURCES impl/*.cpp include/*.h)
include_directories(include)

add_executable(myapp main.cpp ${SOURCES})
add_library(app_project ${SOURCES})

install(TARGETS myapp DESTINATION bin)

find_package( Boost REQUIRED COMPONENTS thread system)
include_directories(${Boost_INCLUDE_DIRS})

find_package(OpenSSL)
include_directories(${OpenSSL_INCLUDE_DIRS})

target_link_libraries(myapp
	${Boost_LIBRARIES} 
	${OpenSSL_LIBRARIES}
	crypto ssl)

#set (CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} /data/dev/cpp/cpp-netlib/build )
#find_package ( cppnetlib 0.11.0 REQUIRED )
#include_directories ( ${CPPNETLIB_INCLUDE_DIRS} )
#target_link_libraries ( myapp ${CPPNETLIB_LIBRARIES} )
