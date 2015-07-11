enable_testing()

find_package(OpenSSL REQUIRED)

include_directories(
    ${CMOCKA_PUBLIC_INCLUDE_DIRS}
    ${OpenSSL_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR} 
	${CMAKE_SOURCE_DIR}/src 
	${CMAKE_SOURCE_DIR}/src/impl 
	${CMAKE_SOURCE_DIR}/src/include)
	
message("OpenSSL root dir: ${OPENSSL_ROOT_DIR}")
message("OpenSSL version: ${OPENSSL_VERSION}")
message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message("OpenSSL libraries: ${OPENSSL_LIBRARIES}")

add_executable (test_crypt tests_1.c)

target_link_libraries(test_crypt 
	crypto_c
	${CMOCKA_SHARED_LIBRARY} 
	${OpenSSL_LIBRARIES}
	crypto ssl)
	
add_test(TestCase1 test_crypt)