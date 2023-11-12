#ifndef ADVANCED_CPP_BHCC_HASHTABLE_H
#define ADVANCED_CPP_BHCC_HASHTABLE_H

#include <iostream>


/**
 * @brief This is a specific hashtable, where keys are string, and values are a vector of integers.
 * Moreover, the capacity of the hashtable is fixed 8.
 * @note The type of values are `std::vector<int>`.
 */
class Hashtable {
private:
    /**
     * Hashes a key; adds up the chars in the string, and returns the sum.
     * @param key The key to hash
     * @return The hash value of the given key.
     */
    static int hash(const std::string &key);

public:
    /**
     * @brief Creates a hashtable.
     */
    Hashtable();

    /**
     * @brief Destructs a hashtable.
     */
    ~Hashtable();

    /**
     * @brief Sets the value associated with the given key in the hashtable.
     * @param key The key for the value.
     * @param value The vector of integers to be associated with the key.
     */
    void set(const std::string &key, std::vector<int> *value);

    /**
     * @brief Gets the value associated with the given key in the hashtable.
     * @param key The key for which to retrieve the value.
     */
    std::vector<int> *get(const std::string &key);

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
    std::vector<int> *setIfAbsent(const std::string &key);

private:
    /**
     * @brief Entry with key and value.
     */
    class Entry {
    public:
        /**
         * @brief Creates an entry.
         */
        Entry(std::string key, std::vector<int> *value);

        /**
         * @brief Destructs this entry.
         */
        ~Entry();

        /**
         * @brief Returns the key of this entry.
         */
        [[nodiscard]] std::string getKey() const;

        /**
         * @brief Returns the value of this entry.
         */
        std::vector<int> *getValue();

    private:
        std::string key;
        std::vector<int> *value;
    };

    static const int CAPACITY = 8;

    /**
     * @brief Fixed-size array of vectors to store key-value pairs in buckets.
     */
    Entry *array[CAPACITY]{};
};

#endif
