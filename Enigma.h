// Enigma.h
#pragma once

#include "Encrypt.h"

class Enigma : public Encrypt {
private:
    std::string _keyRotor1;
    std::string _keyRotor2;

public:
    Enigma(const std::string& keyRotor1, const std::string& keyRotor2);
    ~Enigma();

    void setKeys(const std::string& keyRotor1, const std::string& keyRotor2);
    void encode() override;
    void decode() override;
};
