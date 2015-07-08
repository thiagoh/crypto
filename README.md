# Crypto C++ library 

[![Build Status](https://travis-ci.org/thiagoh/crypto.svg?branch=master)](https://travis-ci.org/thiagoh/crypto)

This library is intented to encrypt and decrypt data

## Usage

```
unsigned char* iv = "0123456789123456"; //128 bits
unsigned char* key = "01234567891234567890123456789012"; // 256 bits

const char* plaintext = "the fox jumped over the lazy dog";

The default cipher mode is CBC and algorithm is 3DES_EDE 

std::pair<unsigned char*, int> ciphertext = Crypto::encrypt(plaintext, strlen(plaintext), key, iv, &len);

std::pair<unsigned char*, int> newplaintext = Crypto::decrypt(ciphertext, strlen(ciphertext), key, iv, &newlen);

ciphertext.first; // data encrypted
ciphertext.second; // length

newplaintext.first; // data unencrypted
newplaintext.second; // length

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
