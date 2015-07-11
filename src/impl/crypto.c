/*
 * Crypto.cpp
 *
 *  Created on: Jul 2, 2015
 *      Author: thiagoh
 */

#include <crypto.h>
#include <string.h>

void crypto_handle_errors() {
	ERR_print_errors_fp(stderr);
	abort();
};

crypto_data crypto_encrypt(unsigned char* plaintext, int plaintextLength, unsigned char *key, unsigned char* iv) {

	crypto_data p;

	if (!plaintext) {
		p.error = true;
		p.message = "Plaintext must be defined";
		return p;
	}

	if (plaintextLength < 0) {
		p.error = true;
		p.message = "Plaintext length must be positive";
		return p;
	}

	unsigned char* ciphertext = malloc(sizeof(unsigned char) * (plaintextLength + 16));

	/* Load the human readable error strings for libcrypto */
	ERR_load_crypto_strings();

	/* Load all digest and cipher algorithms */
	OpenSSL_add_all_algorithms();

	/* Load config file, and other important initialisation */
	OPENSSL_config(NULL);

	EVP_CIPHER_CTX *ctx;

	int len;
	int ciphertext_len;
	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
		crypto_handle_errors();

	/* Initialise the encryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits */
	if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
		crypto_handle_errors();

	/* Provide the message to be encrypted, and obtain the encrypted output.
	 * EVP_EncryptUpdate can be called multiple times if necessary
	 */
	if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintextLength))
		crypto_handle_errors();

	ciphertext_len = len;

	/* Finalise the encryption. Further ciphertext bytes may be written at
	 * this stage.
	 */
	if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
		crypto_handle_errors();

	ciphertext_len += len;

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);

	/* Clean up */

	/* Removes all digests and ciphers */
	EVP_cleanup();

	/* if you omit the next, a small leak may be left when you make use of the BIO (low level API) for e.g. base64 transformations */
	CRYPTO_cleanup_all_ex_data();

	/* Remove error strings */
	ERR_free_strings();

	p.error = false;
	p.data = ciphertext;
	p.length = ciphertext_len;

	return p;
}

crypto_data crypto_decrypt(unsigned char* ciphertext, int ciphertextLength, unsigned char *key, unsigned char* iv) {

	crypto_data p;

	if (!ciphertext) {
		p.error = true;
		p.message = "Cipher text must be defined";
		return p;
	}

	if (ciphertextLength < 0) {
		p.error = true;
		p.message = "Cipher text length must be positive";
		return p;
	}

	unsigned char* plaintext = malloc(sizeof(unsigned char) * (ciphertextLength));

	/* Load the human readable error strings for libcrypto */
	ERR_load_crypto_strings();

	/* Load all digest and cipher algorithms */
	OpenSSL_add_all_algorithms();

	/* Load config file, and other important initialisation */
	OPENSSL_config(NULL);

	EVP_CIPHER_CTX *ctx;

	int len;
	int plaintext_len;

	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
		crypto_handle_errors();

	/* Initialise the decryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits */
	if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
		crypto_handle_errors();

	/* Provide the message to be decrypted, and obtain the plaintext output.
	 * EVP_DecryptUpdate can be called multiple times if necessary
	 */
	if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertextLength))
		crypto_handle_errors();

	plaintext_len = len;

	/* Finalise the decryption. Further plaintext bytes may be written at
	 * this stage.
	 */
	if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
		crypto_handle_errors();

	plaintext_len += len;

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);

	/* Removes all digests and ciphers */
	EVP_cleanup();

	/* if you omit the next, a small leak may be left when you make use of the BIO (low level API) for e.g. base64 transformations */
	CRYPTO_cleanup_all_ex_data();

	/* Remove error strings */
	ERR_free_strings();

	plaintext[plaintext_len] = '\0';

	p.error = false;
	p.data = plaintext;
	p.length = plaintext_len;

	return p;
}
