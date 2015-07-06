enable_testing()
set(LIBS ${LIBS} ${CHECK_LIBRARIES} app_project)

add_definitions (-DBOOST_TEST_DYN_LINK)

#find_package(Check REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread system unit_test_framework REQUIRED)

include_directories(
	. ../src
	${CHECK_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS} 
    ${CMAKE_SOURCE_DIR} 
	${CMAKE_SOURCE_DIR}/src 
	${CMAKE_SOURCE_DIR}/src/include
	${CMAKE_SOURCE_DIR}/include)

add_executable (test_crypt Crypt.cpp)
target_link_libraries(test_crypt ${Boost_LIBRARIES} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${LIBS})
add_test(TestCase1 test_crypt)
add_test(TestCase2 ${CMAKE_CURRENT_BINARY_DIR}/test_crypt)