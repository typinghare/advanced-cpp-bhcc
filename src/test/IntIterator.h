#ifndef ADVANCED_CPP_BHCC_INTITERATOR_H
#define ADVANCED_CPP_BHCC_INTITERATOR_H

#include <iostream>

class IntIterator {
public:
    IntIterator() { curr = nullptr; }

    explicit IntIterator(int *begin) : curr(begin) {}

    int *getCurr() { return curr; }

    /**
     * Overload pre-increment operator
     */
    IntIterator &operator++() {
        curr += 1;
        return *this;
    }

    /**
     * @brief Overload of post-increment operator
     */
    IntIterator operator++(int) {  // NOLINT(*)
        IntIterator copy(*this);
        curr += 1;
        return copy;
    }

private:
    int *curr;
};

#endif
