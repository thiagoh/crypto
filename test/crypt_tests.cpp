/*
 * Crypto.cpp
 *
 *  Created on: Jul 5, 2015
 *      Author: thiago
 */

#define BOOST_TEST_MODULE example
#define BOOST_TEST_LOG_LEVEL all

#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/detail/unit_test_parameters.hpp>
#include <boost/test/unit_test_log.hpp>
#include <boost/test/auto_unit_test.hpp>

#include <iostream>
#include <stdio.h>
#include "time.h"
#include "Crypt.h"
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

using namespace boost::unit_test;
using namespace com::thiagoh::crypt;

BOOST_AUTO_TEST_SUITE(Suite)

BOOST_AUTO_TEST_CASE(test_init) {

	boost::unit_test::unit_test_log.set_threshold_level( log_successful_tests );
	boost::unit_test::unit_test_log.set_format( CLF);

	long current_time; // real call is required here
	time(&current_time);

	BOOST_TEST_MESSAGE( "Test initialization..." );
	BOOST_TEST_MESSAGE( "Current time:" << current_time );
}

BOOST_AUTO_TEST_CASE(mytest1) {

	BOOST_CHECK_EQUAL("a", "a");
	BOOST_CHECK_EQUAL("ac", "ac");
	BOOST_CHECK_EQUAL("ab", "ab");
}

BOOST_AUTO_TEST_CASE(mytest2) {

	/* A 256 bit key */
	unsigned char *key = (unsigned char *) "any256bitkey_chars_to_complete_0";

	/* A 128 bit IV */
	unsigned char *iv = (unsigned char *) "any128bitkey_000";

	unsigned char* plain = (unsigned char *) "the fox jumped over the lazy dog";
	unsigned char ciphered[1024];
	unsigned char deciphered[1024];
	int len = 0, delen = 0;

	Crypt::encrypt(plain, strlen((char*) plain), key, iv, ciphered, &len);
	Crypt::decrypt(ciphered, len, key, iv, deciphered, &delen);

//	BOOST_CHECK_PREDICATE(std::not_equal_to<unsigned char*>(), (ciphered, deciphered));
	BOOST_CHECK_EQUAL(plain, deciphered);
}

BOOST_AUTO_TEST_CASE(test_tear_down) {

	long current_time; // real call is required here
	time(&current_time);

	BOOST_TEST_MESSAGE( "Test tear down..." );
	BOOST_TEST_MESSAGE( "Current time:" << current_time );
}

BOOST_AUTO_TEST_SUITE_END()
