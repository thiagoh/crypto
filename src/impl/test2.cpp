/*
 * test1.cpp
 *
 *  Created on: Jul 1, 2015
 *      Author: thiagoh
 */

#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#ifndef SRC_TEST_2_CPP_
#define SRC_TEST_2_CPP_

void __handleErrors(void) {
	ERR_print_errors_fp(stderr);
	abort();
};

int _encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
	EVP_CIPHER_CTX *ctx;

	int len;

	int ciphertext_len;

	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
		__handleErrors();

	/* Initialise the encryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits */
	if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
//	if (1 != EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key, iv))
		__handleErrors();

	/* Provide the message to be encrypted, and obtain the encrypted output.
	 * EVP_EncryptUpdate can be called multiple times if necessary
	 */
	if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
		__handleErrors();
	ciphertext_len = len;

	/* Finalise the encryption. Further ciphertext bytes may be written at
	 * this stage.
	 */
	if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
		__handleErrors();
	ciphertext_len += len;

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);

	return ciphertext_len;
}

int _decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
	EVP_CIPHER_CTX *ctx;

	int len;

	int plaintext_len;

	/* Create and initialise the context */
	if (!(ctx = EVP_CIPHER_CTX_new()))
		__handleErrors();

	/* Initialise the decryption operation. IMPORTANT - ensure you use a key
	 * and IV size appropriate for your cipher
	 * In this example we are using 256 bit AES (i.e. a 256 bit key). The
	 * IV size for *most* modes is the same as the block size. For AES this
	 * is 128 bits */
	if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
//	if (1 != EVP_DecryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key, iv))
		__handleErrors();

	/* Provide the message to be decrypted, and obtain the plaintext output.
	 * EVP_DecryptUpdate can be called multiple times if necessary
	 */
	if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
		__handleErrors();
	plaintext_len = len;

	/* Finalise the decryption. Further plaintext bytes may be written at
	 * this stage.
	 */
	if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
		__handleErrors();
	plaintext_len += len;

	/* Clean up */
	EVP_CIPHER_CTX_free(ctx);

	return plaintext_len;
}

int test2() {

	/* Set up the key and iv. Do I need to say to not hard code these in a
	 * real application? :-)
	 */

	/* A 256 bit key */
	unsigned char *key = (unsigned char *) "01234567890123456789012345678901";

	/* A 128 bit IV */
	unsigned char *iv1 = (unsigned char *) "01234567890123456";

	/* Message to be encrypted */
	unsigned char *plaintext = (unsigned char *) "The quick brown fox jumps over the lazyefoiajef oaijf aoiej affe iab nhaaaaaaau";

	/* Buffer for ciphertext. Ensure the buffer is long enough for the
	 * ciphertext which may be longer than the plaintext, dependant on the
	 * algorithm and mode
	 */
	unsigned char ciphertext[128];

	/* Buffer for the decrypted text */
	unsigned char decryptedtext[128];

	int decryptedtext_len, ciphertext_len;

	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////

	/* Load the human readable error strings for libcrypto */
	ERR_load_crypto_strings();

	/* Load all digest and cipher algorithms */
	OpenSSL_add_all_algorithms();

	/* Load config file, and other important initialisation */
	OPENSSL_config(NULL);

	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
	/* ... Do some crypto stuff here ... */

	/* Encrypt the plaintext */
	ciphertext_len = _encrypt(plaintext, strlen((char *) plaintext), key, iv1, ciphertext);

	/* Do something useful with the ciphertext here */
	printf("Ciphertext is:\n");

	for (unsigned int i = 0; i < ciphertext_len; i++) {
		printf("%x", ciphertext[i] & 0xff);
	}

	printf("\n");

	BIO_dump_fp(stdout, (const char *) ciphertext, ciphertext_len);

	/* Decrypt the ciphertext */
	decryptedtext_len = _decrypt(ciphertext, ciphertext_len, key, iv1, decryptedtext);

	/* Add a NULL terminator. We are expecting printable text */
	decryptedtext[decryptedtext_len] = '\0';

	/* Show the decrypted text */
	printf("Decrypted text is:\n %s\n", decryptedtext);

	/* ... End Do some crypto stuff here ... */
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
	/* Clean up */

	/* Removes all digests and ciphers */
	EVP_cleanup();

	/* if you omit the next, a small leak may be left when you make use of the BIO (low level API) for e.g. base64 transformations */
	CRYPTO_cleanup_all_ex_data();

	/* Remove error strings */
	ERR_free_strings();

	return 0;
}

#endif
