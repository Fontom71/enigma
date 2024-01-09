// main.cpp
#include "Enigma.h"
#include <iostream>

int main() {
    try {
        // Créer une machine Enigma avec deux clés de rotor
        Enigma enigma("QWERTYUIOPASDFGHJKLZXCVBNM", "MNBVCXZLKJHGFDSAPOIUYTREWQ");

        // Lire un message à partir d'un fichier
        enigma.read("input.txt");

        // Afficher le message d'origine
        std::cout << "Message d'origine : " << enigma.plain() << std::endl;

        // Encoder le message
        enigma.encode();

        // Afficher le message encodé
        std::cout << "Message encodé : " << enigma.cipher() << std::endl;

        // Décoder le message
        enigma.decode();

        // Afficher le message décodé
        std::cout << "Message décodé : " << enigma.plain() << std::endl;

        // Écrire le message décodé dans un fichier
        enigma.write("output.txt");
    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
