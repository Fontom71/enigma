// Encrypt.cpp
#include "Encrypt.h"
#include <fstream>

Encrypt::Encrypt() {}

Encrypt::~Encrypt() {}

std::string Encrypt::plain() const {
    return _plain;
}

std::string Encrypt::cipher() const {
    return _cipher;
}

void Encrypt::read(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::getline(file, _plain);
        file.close();
    }
}

void Encrypt::write(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << _cipher;
        file.close();
    }
}
