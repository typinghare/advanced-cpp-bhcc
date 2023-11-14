#include "Hashtable.h"
#include <utility>

int Hashtable::hash(const std::string &key) {
    int sum = 0;
    for (char c: key) {
        sum += c;
    }

    return sum;
}

Hashtable::Hashtable() {
    for (auto &i: array) {
        i = nullptr;
    }
}

Hashtable::~Hashtable() {
    for (auto entry: array) {
        delete entry;
    }
}

void Hashtable::set(const std::string &key, std::vector<int> *value) {
    int hash_value = hash(key),
        index = hash_value % CAPACITY,
        i = index;

    // Address hash collision with linear probing
    for (int r = 0; r < CAPACITY; r++, i = ++i % CAPACITY) {
        if (array[i] != nullptr) {
            if (array[i]->getKey() == key) {
                throw std::runtime_error("Key already exists: " + key);
            }
        } else {
            break;
        }
    }

    array[i] = new Entry(key, value);
}

std::vector<int> *Hashtable::get(const std::string &key) {
    int hash_value = hash(key),
        index = hash_value % CAPACITY,
        i = index;

    for (int r = 0; r < CAPACITY; r++, i = ++i % CAPACITY) {
        Entry *entry = array[i];
        if (entry == nullptr) break;
        if (entry->getKey() == key) {
            return entry->getValue();
        }
    }

    throw std::runtime_error("Key does not exist: " + key);
}

std::vector<std::string> Hashtable::keys() {
    std::vector<std::string> keys;
    for (auto entry: array) {
        if (entry != nullptr) {
            keys.push_back(entry->getKey());
        }
    }

    return keys;
}

std::vector<int> *Hashtable::setIfAbsent(const std::string &key) {
    try {
        return get(key);
    } catch (std::runtime_error &error) {
        auto *newVector = new std::vector<int>();
        set(key, newVector);
        return newVector;
    }
}

Hashtable::Entry::Entry(std::string key, std::vector<int> *value)
    : key(std::move(key)), value(value) {
}

Hashtable::Entry::~Entry() {
    delete value;
}

std::string Hashtable::Entry::getKey() const {
    return key;
}

std::vector<int> *Hashtable::Entry::getValue() {
    return value;
}