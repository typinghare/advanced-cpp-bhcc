#ifndef ADVANCED_CPP_BHCC_SECURE_H
#define ADVANCED_CPP_BHCC_SECURE_H

#include <iostream>

/**
 * Encrypts an message.
 * @param message The message to be encrypted.
 * @return The encrypted message.
 */
std::string encrypt(const std::string &message, const std::string &key);

/**
 * Decrypts an message.
 * @param encryptedMessage The message to be encrypted
 * @return The original message.
 */
std::string decrypt(const std::string &encryptedMessage, const std::string &key);

#endif
