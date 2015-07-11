enable_testing()
#add_definitions (-DBOOST_TEST_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS thread system unit_test_framework REQUIRED)

find_package(OpenSSL REQUIRED)

include_directories(
    ${Boost_INCLUDE_DIRS} 
    ${OpenSSL_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR} 
	${CMAKE_SOURCE_DIR}/src 
	${CMAKE_SOURCE_DIR}/src/impl 
	${CMAKE_SOURCE_DIR}/src/include)
	
message("Boost include dir: ${Boost_INCLUDE_DIRS}")
message("Boost libraries: ${Boost_LIBRARIES}")
	
message("OpenSSL root dir: ${OPENSSL_ROOT_DIR}")
message("OpenSSL version: ${OPENSSL_VERSION}")
message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message("OpenSSL libraries: ${OPENSSL_LIBRARIES}")

add_executable (test_crypt crypto_tests_1.cpp)

target_link_libraries(test_crypt 
	app_project
	${Boost_LIBRARIES} 
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} 
	${OpenSSL_LIBRARIES}
	crypto ssl)
	
add_test(TestCase1 test_crypt)
add_test(TestCase2 ${CMAKE_CURRENT_BINARY_DIR}/test_crypt)