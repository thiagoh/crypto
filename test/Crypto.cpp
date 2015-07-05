/*
 * Crypto.cpp
 *
 *  Created on: Jul 5, 2015
 *      Author: thiago
 */

#include <boost/test/unit_test.hpp>
#include <boost/test/auto_unit_test.hpp>
#include "include/Crypt.h"

using namespace com::thiagoh::crypt;

BOOST_AUTO_TEST_CASE(TestCase1) {


	/* A 256 bit key */
	unsigned char *key = (unsigned char *) "any256bitkey_chars_to_complete_0";

	/* A 128 bit IV */
	unsigned char *iv = (unsigned char *) "any128bitkey_000";

	unsigned char* plain = "the fox jumped over the lazy dog";
	unsigned char* ciphered = new unsigned char[1024];
	unsigned char* deciphered = new unsigned char[1024];
	int len = 0, delen = 0;

	Crypt::encrypt(plain, strlen((char*) plain), key, iv, ciphered, &len);
	Crypt::decrypt(ciphered, len, key, iv, deciphered, &delen);

	BOOST_CHECK_EQUAL(ciphered, deciphered);
}
