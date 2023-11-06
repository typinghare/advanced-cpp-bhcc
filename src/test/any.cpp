#pragma clang diagnostic push
#pragma ide diagnostic ignored "Simplify"

#include <iostream>
#include "IntIterator.h"

using namespace std;

int main() {
    int array[5]{1, 2, 3, 4, 5};
    int *begin{std::begin(array)}, *end{std::end(array)};

    for (IntIterator iter(begin); iter.getCurr() != end; ++iter) {
        std::cout << *iter.getCurr() << " ";
    }
    std::cout << std::endl;

    IntIterator iter(begin), capture;
    for (; iter.getCurr() != end; capture = iter++) {
        std::cout << *iter.getCurr() << " ";
    }
    // If "false" is printed, we can prove that extra IntIterators are created
    std::cout << std::endl << (&iter == &capture ? "true" : "false") << std::endl;

    return 0;
}

#pragma clang diagnostic pop