#include <iostream>

using namespace std;

int main() {
    vector values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto iter{cbegin(values)}; iter != cend(values); iter++) {
        cout << *iter << " ";
    }

    return 0;
}