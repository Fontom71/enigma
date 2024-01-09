// Enigma.cpp
#include "Enigma.h"
#include <stdexcept>

Enigma::Enigma(const std::string& keyRotor1, const std::string& keyRotor2) {
    setKeys(keyRotor1, keyRotor2);
}

Enigma::~Enigma() {}

void Enigma::setKeys(const std::string& keyRotor1, const std::string& keyRotor2) {
    // Vérifier que les clés ont une longueur de 26 caractères
    if (keyRotor1.length() == 26 && keyRotor2.length() == 26) {
        _keyRotor1 = keyRotor1;
        _keyRotor2 = keyRotor2;
    } else {
        throw std::invalid_argument("Les clés doivent avoir une longueur de 26 caractères.");
    }
}

void Enigma::encode() {
    for (char& c : _plain) {
        if (isalpha(c)) {
            // Convertir le caractère en majuscule pour l'indexation des clés
            c = toupper(c);

            // Vérifier si le caractère est une lettre majuscule valide
            if (c < 'A' || c > 'Z') {
                throw std::invalid_argument("Caractère non valide dans le message.");
            }

            // Effectuer le décalage du caractère en utilisant le premier rotor
            c = _keyRotor1[c - 'A'];

            // Effectuer le décalage du caractère en utilisant le deuxième rotor
            c = _keyRotor2[c - 'A'];
        }
    }

    _cipher = _plain;
}

void Enigma::decode() {
    for (char& c : _cipher) {
        if (isalpha(c)) {
            // Convertir le caractère en majuscule pour l'indexation des clés
            c = toupper(c);

            // Vérifier si le caractère est une lettre majuscule valide
            if (c < 'A' || c > 'Z') {
                throw std::invalid_argument("Caractère non valide dans le message.");
            }

            // Trouver la position d'origine du caractère dans le deuxième rotor
            size_t posRotor2 = _keyRotor2.find(c);

            // Effectuer le décalage inverse du caractère en utilisant le deuxième rotor
            c = static_cast<char>('A' + posRotor2);

            // Trouver la position d'origine du caractère dans le premier rotor
            size_t posRotor1 = _keyRotor1.find(c);

            // Effectuer le décalage inverse du caractère en utilisant le premier rotor
            c = static_cast<char>('A' + posRotor1);
        }
    }

    _plain = _cipher;
}
