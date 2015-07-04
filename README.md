# Crypto C++ library

## Usage

int len;
char ciphertext[128];

unsigned char* iv = "0123456789123456"; //128 bits
unsigned char* key = "01234567891234567890123456789012"; // 256 bits

const char* plaintext = "the fox jumped over the lazy dog";

Crypto::encrypt(plaintext, strlen(plaintext), key, iv, &ciphertext, &len);

int newlen;
char newplaintext[128];

Crypto::decrypt(ciphertext, strlen(ciphertext), key, iv, newplaintext, &newlen);

## build process

```bash
mkdir build
cd build
rm -rf ./* 
cmake --debug-output .. 
make -j 4
``` 
