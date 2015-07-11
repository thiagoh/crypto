
/*
 #include<stdio.h>

 int main(int argc, char const *argv[]) {

 printf("Hello World");
 }
 */
#define BOOST_NETWORK_ENABLE_HTTPS
/*`
 This is a part of the 'Hello World' example.  We create a client
 object and make a single HTTP request.  If we use make this request
 to the `hello_world_server`, then the output is simply "Hello,
 World!".
 */
#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <Crypto.h>

#include <string.h>
#include <openssl/rand.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

using namespace com::thiagoh::crypt;

void print(unsigned char* text, int len) {

	for (unsigned int i = 0; i < (unsigned int) len; i++) {
		printf("%x", text[i] & 0xff);
	}
}

int main(int argc, char *argv[]) {

	// author: thiagoh

	printf("do main again");

//	try {
//
//		/* Set up the key and iv. Do I need to say to not hard code these in a
//		 * real application? :-)
//		 */
//
//		/* A 256 bit key */
//		unsigned char *key = (unsigned char *) "any256bitkey_chars_to_complete_0";
//
//		/* A 128 bit IV */
//		unsigned char *iv = (unsigned char *) "any128bitkey_000";
//
//		/* Message to be encrypted */
//		unsigned char *plaintext = (unsigned char *) argv[1]; //"The quick brown fox jumps over the lazyefoiajef oaijf aoiej affe iab nhaaaaaaau";
//		unsigned char *plaintext2 = (unsigned char *) argv[2]; //"The quick brown fox jumps over the lazyefoiajef oaijf aoiej affe iab nhaaaaaaau";
//
//		/* Buffer for ciphertext. Ensure the buffer is long enough for the
//		 * ciphertext which may be longer than the plaintext, dependant on the
//		 * algorithm and mode
//		 */
//		unsigned char ciphertext[128];
//		unsigned char ciphertext2[128];
//
//		/* Buffer for the decrypted text */
//		unsigned char decryptedtext[128];
//		unsigned char decryptedtext2[128];
//
//		int decryptedtext_len, decryptedtext_len2, ciphertext_len, ciphertext_len2;
//
//		/* Encrypt the plaintext */
//		Crypt::encrypt(plaintext, strlen((char *) plaintext), key, iv, ciphertext, &ciphertext_len);
//		Crypt::encrypt(plaintext2, strlen((char *) plaintext2), key, iv, ciphertext2, &ciphertext_len2);
//
//		/* Do something useful with the ciphertext here */
//		printf("Ciphertext is:\n");
//		print(ciphertext, ciphertext_len);
//		printf("\n");
//		print(ciphertext2, ciphertext_len2);
//		printf("\n");
//
//		//BIO_dump_fp(stdout, (const char *) ciphertext, ciphertext_len);
//
//		/* Decrypt the ciphertext */
//		Crypt::decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
//		Crypt::decrypt(ciphertext2, ciphertext_len2, key, iv, decryptedtext2, &decryptedtext_len2);
//
//		/* Add a NULL terminator. We are expecting printable text */
//		decryptedtext[decryptedtext_len] = '\0';
//		decryptedtext2[decryptedtext_len2] = '\0';
//
//		/* Show the decrypted text */
//		printf("Decrypted text is:\n %s\n", decryptedtext);
//		printf("Decrypted text is:\n %s\n", decryptedtext2);
//
//	} catch (std::exception &e) {
//		std::cerr << e.what() << std::endl;
//		return 1;
//	}
}

