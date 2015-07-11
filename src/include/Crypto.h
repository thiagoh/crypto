/*
 * Crypto.h
 *
 *  Created on: Jul 2, 2015
 *      Author: thiagoh
 */

#ifndef SRC_CRYPT_H_
#define SRC_CRYPT_H_

#include <string>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <utility>

namespace com {
namespace thiagoh {
namespace crypt {

class Crypto {

public:
	Crypto();
	virtual ~Crypto();

	static void handleErrors(void) {
		ERR_print_errors_fp(stderr);
		abort();
	};

	static std::pair<unsigned char*, int> encrypt(unsigned char* plaintext, int plaintextLength, unsigned char *key, unsigned char* iv);
	static std::pair<unsigned char*, int> decrypt(unsigned char* ciphertext, int ciphertextLength, unsigned char *key, unsigned char* iv);
};

} /* namespace crypt */
} /* namespace thiagoh */
} /* namespace com */

#endif /* SRC_CRYPT_H_ */
