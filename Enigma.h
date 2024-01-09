// Enigma.h
#pragma once

#include "Encrypt.h"

class Enigma : public Encrypt {
private:
    std::string _key;

public:
    Enigma(const std::string& key);
    ~Enigma();

    void setKey(const std::string& key);
    void encode() override;
    void decode() override;
};
