/*
 * Crypto.h
 *
 *  Created on: Jul 2, 2015
 *      Author: thiagoh
 */

#ifndef SRC_CRYPTO_H_
#define SRC_CRYPTO_H_

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <stdio.h>

typedef int bool;
#define true 1;
#define false 0;

typedef struct {
	unsigned char* data;
	int length;
	bool error;
	const char* message;
} crypto_data;

void crypto_handle_errors(void);
crypto_data crypto_encrypt(unsigned char* plaintext, int plaintextLength, unsigned char *key, unsigned char* iv);
crypto_data crypto_decrypt(unsigned char* ciphertext, int ciphertextLength, unsigned char *key, unsigned char* iv);

#endif /* SRC_CRYPTO_H_ */
