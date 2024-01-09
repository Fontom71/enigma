// Encrypt.h
#pragma once

#include <string>

class Encrypt {
protected:
    std::string _plain;
    std::string _cipher;

public:
    Encrypt();
    virtual ~Encrypt();

    std::string plain() const;
    std::string cipher() const;

    virtual void encode() = 0;
    virtual void decode() = 0;

    void read(const std::string& filename);
    void write(const std::string& filename);
};
