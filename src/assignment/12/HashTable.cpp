#include "HashTable.h"
#include <utility>

int HashTable::hash(const std::string &key) {
    int sum = 0;
    for (char c: key) {
        sum += c;
    }

    return sum;
}

HashTable::HashTable() {
    for (auto &element: hashTable) {
        element = nullptr;
    }
}

HashTable::~HashTable() {
    for (auto &element: hashTable) {
        delete element;
    }
}

void HashTable::set(const std::string &key, std::set<int> *value) {
    int hash_value = hash(key),
        index = hash_value % CAPACITY,
        i = index;

    // Address hash collision with linear probing
    for (int r = 0; r < CAPACITY; r++, i = ++i % CAPACITY) {
        Entry *entry = hashTable[i];
        if (entry != nullptr) {
            if (entry->getKey() == key) {
                throw std::runtime_error("Key already exists: " + key);
            }
        } else {
            break;
        }
    }

    hashTable[i] = new Entry(key, value);
}

std::set<int> *HashTable::get(const std::string &key) {
    int hash_value = hash(key),
        index = hash_value % CAPACITY,
        i = index;

    for (int r = 0; r < CAPACITY; r++, i = ++i % CAPACITY) {
        Entry *entry = hashTable[i];
        if (entry == nullptr) break;
        if (entry->getKey() == key) {
            return entry->getValue();
        }
    }

    return nullptr;
}

std::vector<std::string> HashTable::keys() {
    std::vector<std::string> keys;
    for (auto entry: hashTable) {
        if (entry != nullptr) {
            keys.push_back(entry->getKey());
        }
    }

    return keys;
}

std::set<int> *HashTable::setIfAbsent(const std::string &key) {
    std::set<int> *value = get(key);

    if (value == nullptr) {
        value = new std::set<int>();
        set(key, value);
    }

    return value;
}

HashTable::Entry::Entry(std::string key, std::set<int> *value) :
    key(std::move(key)), value(value) {
}

std::string HashTable::Entry::getKey() const {
    return key;
}

std::set<int> *HashTable::Entry::getValue() {
    return value;
}