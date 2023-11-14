#ifndef ADVANCED_CPP_BHCC_HASHTABLE_H
#define ADVANCED_CPP_BHCC_HASHTABLE_H

#include <iostream>
#include <set>

/**
 * @brief This is a specific hash table for this assignment. In this hash table, keys are strings
 * (prefixes of courses), and values are integer sets (sets of course numbers).
 */
class HashTable {
private:
    /**
     * @brief Hashes a key; adds up the chars in the string, and returns the sum.
     * @param key The key to hash.
     * @return The hash value of the given key.
     */
    static int hash(const std::string &key);

public:
    /**
     * @brief Creates a hash table.
     */
    HashTable();

    /**
     * @brief Destructs this hash table.
     */
    ~HashTable();

    /**
     * @brief Sets the value associated with the given key in the hashtable.
     * @param key The key for the value.
     * @param value The set of integers to be associated with the key.
     */
    void set(const std::string &key, std::set<int> *value);

    /**
     * @brief Gets the value associated with the given key in the hashtable.
     * @param key The key for which to retrieve the value.
     */
    std::set<int> *get(const std::string &key);

    /**
     * @brief Returns all keys in this hashtable.
     */
    std::vector<std::string> keys();

    /**
     * @brief Sets the value associated with the given key in the hashtable if the key does not
     * exist.
     * @return the value associated with the given key if the key exists; a new integer vector if
     * the key does not exist; note that the new integer vector is bound to the key before being
     * returned.
     */
    std::set<int> *setIfAbsent(const std::string &key);

private:
    class Entry {
    public:
        /**
         * Creates an entry.
         * @param key The key of this entry.
         * @param value The value of this entry.
         */
        Entry(std::string key, std::set<int> *value);

        /**
         * @brief Returns the key of this entry.
         */
        [[nodiscard]] std::string getKey() const;

        /**
         * @brief Returns the value of this entry.
         */
        std::set<int> *getValue();

    private:
        std::string key;
        std::set<int> *value;
    };

    /**
     * The capacity of the hash table.
     */
    static const int CAPACITY = 8;

    /**
     * @brief Fixed-size array of entries to store key-value pairs in buckets.
     */
    Entry *hashTable[CAPACITY]{};
};

#endif
