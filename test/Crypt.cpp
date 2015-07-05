/*
 * Crypto.cpp
 *
 *  Created on: Jul 5, 2015
 *      Author: thiago
 */

#define BOOST_TEST_MODULE example
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_log.hpp>
#include <boost/test/auto_unit_test.hpp>

#include "Crypt.h"

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(MasterSuite)

BOOST_AUTO_TEST_CASE(mytest1) {

	BOOST_CHECK( true /* test assertion */ );

	/* A 256 bit key */
	unsigned char *key = (unsigned char *) "any256bitkey_chars_to_complete_0";

	/* A 128 bit IV */
	unsigned char *iv = (unsigned char *) "any128bitkey_000";

	unsigned char* plain = (unsigned char *) "the fox jumped over the lazy dog";
	unsigned char ciphered[1024];
	unsigned char deciphered[1024];
	int len = 0, delen = 0;

	com::thiagoh::crypt::Crypt::encrypt(plain, strlen((char*) plain), key, iv, ciphered, &len);
	com::thiagoh::crypt::Crypt::decrypt(ciphered, len, key, iv, deciphered, &delen);

//	BOOST_CHECK_PREDICATE(std::not_equal_to<unsigned char*>, ciphered, deciphered);
	//BOOST_CHECK_EQUAL(plain, deciphered);
}

BOOST_AUTO_TEST_SUITE_END()
