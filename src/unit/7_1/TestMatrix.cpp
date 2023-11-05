#include "Matrix.h"
#include <iostream>
#include <functional>

/**
 * @brief Returns the time of running a closure. This function saves a lot of work.
 * @param closure The closure to run.
 * @return The duration in microseconds.
 */
long measureExecutionTime(const std::function<void()> &closure) {
    auto start_time = std::chrono::high_resolution_clock::now();

    closure();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    return duration.count();
}

/**
 * Prints the event and the duration consumed.
 * @param event The description of the event.
 * @param duration The duration consumed.
 */
void printEventDuration(const std::string &event, long duration) {
    std::cout << event << ": " << duration << " microseconds." << std::endl;
}

/**
 * @note I tested when N = 20'000, and it works just fine. However, when I changed N to 50'000, the
 * program stopped and quit with code 137. I asked ChatGPT what happened and it said it properly
 * because of a memory run-out. My RAM is only 8G so I cannot run it on my dilapidated (just learned
 * this word) laptop.
 */
int main() {
    const int N = 50'000;
    long duration;

    duration = measureExecutionTime([]() {
        Matrix matrix(N, N);
    });
    printEventDuration("(1) Instantiate a matrix with 50,000 x 50,000 elements", duration);

    Matrix matrix(N, N);
    duration = measureExecutionTime([&matrix]() {
        Matrix copyConstructorMatrix = matrix;  // NOLINT(*)
    });
    printEventDuration("(2) Create a copy-constructor instance", duration);

    duration = measureExecutionTime([&matrix]() {
        Matrix moveConstructorMatrix = std::move(matrix);
    });
    printEventDuration("(3) Create a move-constructor of the class", duration);

    Matrix copyAssignmentMatrix(N, N);
    duration = measureExecutionTime([&matrix, &copyAssignmentMatrix]() {
        copyAssignmentMatrix = matrix;
    });
    printEventDuration("(4) Create a copy-assignment of the class", duration);

    Matrix moveAssignmentMatrix(N, N);
    duration = measureExecutionTime([&matrix, &moveAssignmentMatrix]() {
        moveAssignmentMatrix = std::move(matrix);
    });
    printEventDuration("(5) Create a move-assignment of the class", duration);

    return 0;
}