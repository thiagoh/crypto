#include <crypto.h>
#include "time.h"
#include <check.h>

int main(int argc, char **argv) {

	long current_time; // real call is required here
	time(&current_time);

	/* A 256 bit key */
	unsigned char *key = (unsigned char *) "any256bitkey_chars_to_complete_0";

	/* A 128 bit IV */
	unsigned char *iv = (unsigned char *) "any128bitkey_000";

	unsigned char* plain = (unsigned char *) "Se hoje é o dia das crianças... Ontem eu disse: o dia da criança é o dia da mãe, dos pais, das professoras, mas também é o dia dos animais, sempre que você olha uma criança, há sempre uma figura oculta, que é um cachorro atrás. O que é algo muito importante!"; //"the fox jumped over the lazy dog";

	crypto_data cipheredPair = crypto_encrypt(plain, strlen((char*) plain), key, iv);
	crypto_data decipheredPair = crypto_decrypt(cipheredPair.data, cipheredPair.length, key, iv);

	ck_assert_int_eq(strlen((char*) plain), decipheredPair.length);
	ck_assert_int_eq(strncmp((const char *)plain, (const char *) decipheredPair.data, strlen((char*) plain)), 0);

	return 0;
}
