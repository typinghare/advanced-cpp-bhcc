/**
 * @link https://docs.google.com/document/d/1201149lGj4eNoYeJfLTzMEG5S4bDd_dtQW5yK_ua8ag
 * @link https://stackoverflow.com/questions/32488011/printing-the-binary-representation-of-a-number
 *
 * @note Requirements of Unit 4 Project 1.
 * Create a program that asks 8 true/false questions. Store the correct answers as bits in an 8 bit
 * number. You should not go to the trouble of figuring out what your 8 bit number corresponds to
 * in decimal. You should store the questions in an array. Ask the user the questions in a random
 * order by using another 8-bit value that indicates whether a question has been asked or not. Check
 * the answers against your saved answers using bitwise operators, reporting whether correct or not.
 * Your questions cannot be all true or all false.
 *
 * 1. Run through all of your eight questions, but do not repeat any of them, using the same type
 * of bitwise operations.
 * 2. Starting with 2 as the score for 1 wrong, for every wrong answer, double the score. Use a
 * bitwise operator for this.
 * 3. Make sure your program is refactored so that you have a function to display your binary
 * numbers as well as the getBit function outlined at the link in step 1.
 * 4. Think about why / when a developer might prefer to use these methods rather than an array of
 * T/F values or multiplication by 2.
 */

#include <iostream>
#include <random>
#include <sstream>

/**
 * Gets a bit at the specified position (start from the right, from 0); either 0 or 1 is returned
 * @param number The number to get a bit.
 * @param position The position of the bit to get.
 */
short getBit(unsigned short number, short position) {
    return (number >> position) & 1;
}

/**
 * Prints a number in binary form.
 * @param binaryNumber The binary number to print.
 */
std::string getBinaryNumberString(short binaryNumber) {
    std::stringstream ss;
    for (char i = 7; i >= 0; i--) {
        ss << getBit(binaryNumber, i);
    }

    return ss.str();
}

/**
 * @brief Unit 4 Project 1.
 * @date Sep 22, 2023
 */
int main() {
    const short SIZE{8};

    // Put the eight questions in an array.
    const std::string_view questions[SIZE]{
        "There are fifty states in America.",                           // True
        "Rabbit is a kind of invertebrate.",                            // False
        "An object's gravity is independent of its mass.",              // False
        "You can't flip a coin 100 times in a row and get heads.",      // False
        "Carbon monoxide is odorless.",                                 // True
        "parallel circuits always divide the current equally.",         // False
        "The first derivative of a continuous function must exist.",    // True
        "The human cerebellum is responsible for thermoregulation."     // True
    };

    // Correct answers to the eight questions (stored in an 8-bit integer)
    const short answers = 0b11010001;

    // The score will double for every wrong answer; 1 represents no wrong answers
    short score{1};

    // Whether a question has been asked; 0 represents yet to be asked
    short asked{0};

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(time(nullptr)));

    while (asked < 255) {
        int questionIndex{std::rand() % 8};

        // Skip the question if it has already been asked; record it if yet to be asked
        if (getBit(asked, questionIndex)) continue;
        asked |= (1 << questionIndex);

        bool questionAnswered = false;
        while (!questionAnswered) {
            // Print the question out
            std::cout << questions[questionIndex] << " (y/n) ";

            // Get the input char (answer)
            char input_char;
            std::cin >> input_char;

            if (input_char == 'y' || input_char == 'n') {
                short ans = input_char == 'y' ? 1 : 0;
                short correctAns = getBit(answers, questionIndex);
                score <<= correctAns != ans;
                questionAnswered = true;
            } else {
                std::cout << "Please enter either 'y' or 'n'." << std::endl;
            }
        }
    }

    // Print the score
    std::cout << "Your score (the higher the worse): " << score << std::endl;

    // Test getBinaryNumberString()
    std::cout << std::endl << "The binary number of " << answers << " is: "
              << getBinaryNumberString(answers);

    return 0;
}