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

add_executable (test_crypt crypto_tests_1.cpp)

target_link_libraries(test_crypt 
<<<<<<< HEAD
	crypto_c
	${CMOCKA_SHARED_LIBRARY} 
=======
	app_project
	${Boost_LIBRARIES} 
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} 
>>>>>>> parent of b2089b1... tests
	${OpenSSL_LIBRARIES}
	crypto ssl)
	
add_test(TestCase1 test_crypt)
add_test(TestCase2 ${CMAKE_CURRENT_BINARY_DIR}/test_crypt)