#include "Secure.h"

int getShiftDistance(const std::string &key) {
    int shift = 0;
    for (char i: key) shift += i;
    shift %= 26;

    return shift;
}

std::string encrypt(const std::string &message, const std::string &key) {
    int shiftDistance = getShiftDistance(key);

    std::string encrypted;
    for (char c: message) {
        unsigned char shiftedChar = c + shiftDistance;
        if (shiftedChar > 125) shiftedChar -= 77;
        encrypted += shiftedChar;
    }

    return encrypted;
}

std::string decrypt(const std::string &encryptedMessage, const std::string &key) {
    int shiftDistance = getShiftDistance(key);

    std::string original;
    for (char c: encryptedMessage) {
        unsigned char shiftedChar = c - shiftDistance;
        if (shiftedChar < 48) shiftedChar += 77;
        original += shiftedChar;
    }

    return original;
}
