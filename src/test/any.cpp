
#include <iostream>

using namespace std;

int main() {
    const int SIZE = 30;
    int myArray[SIZE]{};

    for (int i : myArray) {
        cout << i << endl;
    }

    return 0;
}