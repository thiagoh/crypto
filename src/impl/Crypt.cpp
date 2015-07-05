/*
 * Crypt.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: thiagoh
 */

#include "Crypt.h"
#include <sstream>
#include <iostream>
#include <string.h>

namespace com {
namespace thiagoh {
namespace crypt {

Crypt::Crypt() {

}

Crypt::~Crypt() {
}

void Crypt::encrypt(unsigned char* plaintext, int plaintextLength, unsigned char *key, unsigned char* iv, unsigned char* ciphertext, int* ciphertextLength) {

	EVP_CIPHER_CTX *ctx;

	int len;

	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
		handleErrors();

	/* Initialise the encryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits */
//	if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
	if (1 != EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key, iv))
		handleErrors();

	/* Provide the message to be encrypted, and obtain the encrypted output.
	 * EVP_EncryptUpdate can be called multiple times if necessary
	 */
	if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintextLength))
		handleErrors();
	(*ciphertextLength) = len;

	/* Finalise the encryption. Further ciphertext bytes may be written at
	 * this stage.
	 */
	if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
		handleErrors();
	(*ciphertextLength) += len;

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
}

void Crypt::decrypt(unsigned char* ciphertext, int ciphertextLength, unsigned char *key, unsigned char* iv, unsigned char* plaintext, int* plaintextLength) {

	EVP_CIPHER_CTX *ctx;

	int len;

	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
		handleErrors();

	/* Initialise the decryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits */
//	if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
	if (1 != EVP_DecryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key, iv))
		handleErrors();

	/* Provide the message to be decrypted, and obtain the plaintext output.
	 * EVP_DecryptUpdate can be called multiple times if necessary
	 */
	if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertextLength))
		handleErrors();

	(*plaintextLength) = len;

	/* Finalise the decryption. Further plaintext bytes may be written at
	 * this stage.
	 */
	if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
		handleErrors();

	(*plaintextLength) += len;

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);
}

} /* namespace crypt */
} /* namespace thiagoh */
} /* namespace com */
