#include <iostream>
#include <vector>

using namespace std;

int findAdditionalElement(const vector<int> &a, const vector<int> &b) {
    // How to implement this function?
    return 0;
}

int main() {
    int result = findAdditionalElement(
        vector{1, 4, 9, 9, 3},
        vector{9, 3, 4, 5, 9, 1}
    );
    std::cout << result << std::endl;   // expect: "5"

    return 0;
}


