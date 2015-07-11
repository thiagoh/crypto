cmake_minimum_required(VERSION 2.8)

file(GLOB SOURCES impl/*.c include/*.h)
include_directories(include)

add_executable(app main.c ${SOURCES})
add_library(crypto_c ${SOURCES})

install(TARGETS app DESTINATION bin)

find_package(OpenSSL)
include_directories(${OpenSSL_INCLUDE_DIRS})

target_link_libraries(app
	${OpenSSL_LIBRARIES}
	crypto ssl)