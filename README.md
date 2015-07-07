# Crypto C++ library

This library is intented to encrypt and decrypt strings

## Usage

```
int len;

unsigned char* iv = "0123456789123456"; //128 bits
unsigned char* key = "01234567891234567890123456789012"; // 256 bits

const char* plaintext = "the fox jumped over the lazy dog";

The default cipher mode is CBC and algorithm is 3DES_EDE 

unsigned char* ciphertext = Crypto::encrypt(plaintext, strlen(plaintext), key, iv, &len);

int newlen;

unsigned char* newplaintext = Crypto::decrypt(ciphertext, strlen(ciphertext), key, iv, &newlen);

```

## build process

```
bash
mkdir build
cd build
rm -rf ./* 
cmake --debug-output .. 
make -j 4
``` 
