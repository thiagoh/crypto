
add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (test Crypt.cpp)

install(TARGETS test DESTINATION bin)

find_package( Boost REQUIRED COMPONENTS thread system unit_test_framework REQUIRED)

target_link_libraries(test ${Boost_LIBRARIES} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
include_directories(
    ${Boost_INCLUDE_DIRS} 
    ${CMAKE_SOURCE_DIR} 
	${CMAKE_SOURCE_DIR}/src 
	${CMAKE_SOURCE_DIR}/src/include
	${CMAKE_SOURCE_DIR}/include)
