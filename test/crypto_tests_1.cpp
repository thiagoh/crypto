/*
 * Crypto.cpp
 *
 *  Created on: Jul 5, 2015
 *      Author: thiago
 */

#define BOOST_TEST_MODULE example
#define BOOST_TEST_LOG_LEVEL all
#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp>
#include <boost/test/detail/unit_test_parameters.hpp>
#include <boost/test/unit_test_log.hpp>
#include <boost/test/auto_unit_test.hpp>

#include "time.h"
#include <Crypto.h>

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

	unsigned char* plain = (unsigned char *) "Se hoje é o dia das crianças... Ontem eu disse: o dia da criança é o dia da mãe, dos pais, das professoras, mas também é o dia dos animais, sempre que você olha uma criança, há sempre uma figura oculta, que é um cachorro atrás. O que é algo muito importante!"; //"the fox jumped over the lazy dog";

	std::pair<unsigned char*, int> cipheredPair = Crypto::encrypt(plain, strlen((char*) plain), key, iv);
	std::pair<unsigned char*, int> decipheredPair = Crypto::decrypt(cipheredPair.first, cipheredPair.second, key, iv);

	BOOST_CHECK_EQUAL(strlen((char*) plain), decipheredPair.second);
	BOOST_CHECK(memcmp((const char *)plain, (const char *) decipheredPair.first, strlen((char*) plain)) == 0);
	BOOST_CHECK(strncmp((const char *)plain, (const char *) decipheredPair.first, strlen((char*) plain)) == 0);
	BOOST_TEST_MESSAGE(plain << " is equal to " << decipheredPair.first);
}

BOOST_AUTO_TEST_CASE(mytest3) {

	/* A 256 bit key */
	unsigned char *key = (unsigned char *) "any256bitkey_chars_to_complete_1";

	/* A 128 bit IV */
	unsigned char *iv = (unsigned char *) "any128bitkey_001";

	unsigned char* s1 = (unsigned char *) "the fox jumped over the lazy dog 1";
	unsigned char* s2 = (unsigned char *) "the fox jumped over the lazy dog 2";
	unsigned char* s3 = (unsigned char *) "the fox jumped over the lazy dog 3";
	unsigned char* p[3];
	p[0] = s1;
	p[1] = s2;
	p[2] = s3;

	for (unsigned int i = 0; i < 3; i++) {

		unsigned char* plain = p[i];

		std::pair<unsigned char*, int> cipheredPair = Crypto::encrypt(plain, strlen((char*) plain), key, iv);
		std::pair<unsigned char*, int> decipheredPair = Crypto::decrypt(cipheredPair.first, cipheredPair.second, key, iv);

		BOOST_CHECK_EQUAL(strlen((char*) plain), decipheredPair.second);
		BOOST_CHECK(memcmp((const char *)plain, (const char *) decipheredPair.first, strlen((char*) plain)) == 0);
		BOOST_CHECK(strncmp((const char *)plain, (const char *) decipheredPair.first, strlen((char*) plain)) == 0);
		BOOST_TEST_MESSAGE(plain << " is equal to " << decipheredPair.first);
	}
}

BOOST_AUTO_TEST_CASE(mytest4) {

	/* A 256 bit key */
	unsigned char *key = (unsigned char *) "any256bitkey_chars_to_complete_2";

	/* A 128 bit IV */
	unsigned char *iv = (unsigned char *) "any128bitkey_002";

	unsigned char* sc1 = (unsigned char *) "the fox jumped over the lazy dog c1";
	unsigned char* sc2 = (unsigned char *) "the fox jumped over the lazy dog c2";
	unsigned char* sc3 = (unsigned char *) "the fox jumped over the lazy dog c3";
	unsigned char* pc[3];
	pc[0] = sc1;
	pc[1] = sc2;
	pc[2] = sc3;

	unsigned char* se1 = (unsigned char *) "the fox jumped over the lazy dog e1";
	unsigned char* se2 = (unsigned char *) "the fox jumped over the lazy dog e2";
	unsigned char* se3 = (unsigned char *) "the fox jumped over the lazy dog e3";
	unsigned char* pe[3];
	pe[0] = se1;
	pe[1] = se2;
	pe[2] = se3;

	for (unsigned int i = 0; i < 3; i++) {

		unsigned char* plainC = pc[i];
		unsigned char* plainE = pe[i];

		std::pair<unsigned char*, int> cipheredPair = Crypto::encrypt(plainC, strlen((char*) plainC), key, iv);
		std::pair<unsigned char*, int> decipheredPair = Crypto::decrypt(cipheredPair.first, cipheredPair.second, key, iv);

		BOOST_CHECK_EQUAL(strlen((char*) plainC), decipheredPair.second);
		BOOST_CHECK(memcmp((const char *)plainC, (const char *) decipheredPair.first, strlen((char*) plainC)) == 0);
		BOOST_CHECK(strncmp((const char *)plainC, (const char *) decipheredPair.first, strlen((char*) plainC)) == 0);
		BOOST_TEST_MESSAGE(plainC << " is equal to " << decipheredPair.first);

		BOOST_CHECK(memcmp((const char *)plainE, (const char *) decipheredPair.first, strlen((char*) plainC)) != 0);
		BOOST_CHECK(strncmp((const char *)plainE, (const char *) decipheredPair.first, strlen((char*) plainC)) != 0);
		BOOST_TEST_MESSAGE(plainC << " is different from " << plainE);
	}
}

BOOST_AUTO_TEST_CASE(test_tear_down) {

	long current_time; // real call is required here
	time(&current_time);

	BOOST_TEST_MESSAGE( "Test tear down..." );
	BOOST_TEST_MESSAGE( "Current time:" << current_time );
}

BOOST_AUTO_TEST_SUITE_END()
