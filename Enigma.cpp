// Enigma.cpp
#include "Enigma.h"
#include <stdexcept>

Enigma::Enigma(const std::string& key) {
    setKey(key);
}

Enigma::~Enigma() {}

void Enigma::setKey(const std::string& key) {
    if (key.length() == 26) {
        _key = key;
    } else {
        throw std::invalid_argument("Key must be of length 26.");
    }
}

void Enigma::encode() {
    for (char& c : _plain) {
        if (isalpha(c)) {
            // Convert character to uppercase for indexing the key
            c = toupper(c);

            // Check if the character is a valid uppercase letter
            if (c < 'A' || c > 'Z') {
                throw std::invalid_argument("Invalid character in the message.");
            }

            // Shift the character using the key
            c = _key[c - 'A'];
        }
    }

    _cipher = _plain;
}

void Enigma::decode() {
    for (char& c : _cipher) {
        if (isalpha(c)) {
            // Convert character to uppercase for indexing the key
            c = toupper(c);

            // Check if the character is a valid uppercase letter
            if (c < 'A' || c > 'Z') {
                throw std::invalid_argument("Invalid character in the message.");
            }

            // Find the original position of the character in the key
            size_t pos = _key.find(c);

            // Shift the character back to its original position
            c = static_cast<char>('A' + pos);
        }
    }

    _plain = _cipher;
}