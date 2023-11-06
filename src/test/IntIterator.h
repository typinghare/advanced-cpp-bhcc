#ifndef ADVANCED_CPP_BHCC_ITERATOR_H
#define ADVANCED_CPP_BHCC_ITERATOR_H

class Iterator {
public:
    explicit Iterator(int size) { data = new int[size]; }

    ~Iterator() { delete data; }

    void set(int index, int value) { data[index] = value; }

    int get(int index) { return data[index]; }

    // Overload of post-increment operator
    int operator++(int) {
        Iterator copy(*this);

    }

private:
    int *data;
};

#endif
