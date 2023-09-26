#include <iostream>

/**
 * Performs xor operations on each of the four bytes of the integer.
 * @param target The integer to perform on
 * @param num The byte to xor
 */
void xorOnInt(unsigned int &target, char num) {
    unsigned int _num = (int) num;
    for (int i = 0; i < 4; ++i) {
        target ^= _num;
        _num <<= 8;
    }
}

int main() {
    // Test xorOnInt()
    unsigned int num = 0b10000000100000001000010010000100;
    xorOnInt(num, 0b100);
    unsigned int expected_result = 0b10000100100001001000000010000000;
    std::cout << (num == expected_result) << std::endl;     // 1

    return 0;
}