// main.cpp
#include "Enigma.h"
#include <iostream>

int main() {
    // Create an Enigma machine with a key
    Enigma enigma("QWERTYUIOPASDFGHJKLZXCVBNM");

    // Read a message from a file
    enigma.read("input.txt");

    // Display the original message
    std::cout << "Original Message: " << enigma.plain() << std::endl;

    // Encode the message
    enigma.encode();

    // Display the encoded message
    std::cout << "Encoded Message: " << enigma.cipher() << std::endl;

    // Decode the message
    enigma.decode();

    // Display the decoded message
    std::cout << "Decoded Message: " << enigma.plain() << std::endl;

    // Write the decoded message to a file
    enigma.write("output.txt");

    return 0;
}
