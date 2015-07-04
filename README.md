# Crypto C++ library

## Usage

int len;
char ciphertext[128];

char* plaintext = "the fox jumped over the lazy dog";

Crypto::encode(plaintext, strlen(plaintext), key, iv, &ciphertext, &len);

## build process

```bash
mkdir build
cd build
rm -rf ./* 
cmake --debug-output .. 
make -j 4
``` 
