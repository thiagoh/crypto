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
#include "Crypt.h"

using namespace com::thiagoh::crypt;

void print(char* text, int len) {

	for (unsigned int i = 0; i < len; i++) {
		printf("%x", text[i] & 0xff);
	}
}

int main(int argc, char *argv[]) {

	try {

		unsigned char* plain = (unsigned char *) argv[1];
		int len = strlen(argv[1]);

		unsigned char* iv = (unsigned char *) "abcdef";
		unsigned char* key = (unsigned char *) "abcdefghij";

		std::cout << argv[1] << std::endl;

		int ciphertextLen = 0;

		unsigned char * ciphertext = new unsigned char(128); // or unsigned char ciphertext[128];

		Crypt::encrypt(plain, len, key, iv, ciphertext, &ciphertextLen);

		/* Do something useful with the ciphertext here */
		printf("Ciphertext is: %d\n", ciphertextLen);
		print((char*) ciphertext, ciphertextLen);
		std::cout << std::endl;

		int newplaintextLen = 0;
		unsigned char * newplaintext = new unsigned char(128);

		Crypt::decrypt(ciphertext, ciphertextLen, key, iv, newplaintext, &newplaintextLen);
		printf("DeCiphertext is: %d\n", newplaintextLen);
		print((char*) newplaintext, newplaintextLen);
		std::cout << std::endl;

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}

