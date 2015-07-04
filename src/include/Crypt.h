/*
 * Crypt.h
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

namespace com {
namespace thiagoh {
namespace crypt {

class Crypt {
public:
	Crypt();
	virtual ~Crypt();

	static void handleErrors(void) {
		ERR_print_errors_fp(stderr);
		abort();
	};

	static void encrypt(unsigned char* plaintext, int plaintextLength, unsigned char *key, unsigned char* iv, unsigned char* ciphertext, int* ciphertextLength);
	static void decrypt(unsigned char* ciphertext, int ciphertextLength, unsigned char *key, unsigned char* iv, unsigned char* plaintext, int* plaintextLength);
};

} /* namespace crypt */
} /* namespace thiagoh */
} /* namespace com */

#endif /* SRC_CRYPT_H_ */
