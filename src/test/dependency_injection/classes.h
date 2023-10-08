#ifndef ADVANCED_CPP_BHCC_CLASSES_H
#define ADVANCED_CPP_BHCC_CLASSES_H

#include <iostream>

class Closeable {
public:
    virtual void close() = 0;
};

class InputFileStream : public Closeable {
    void close() override {
        std::cout << "Input file stream closed." << std::endl;
    }
};

class OutputFileStream : public Closeable {
    void close() override {
        std::cout << "Output file stream closed." << std::endl;
    }
};

#endif
