#include <iostream>

namespace america {
    /**
     * Prints the namespace I am in.
     */
    void whereAmI() {
        std::cout << "You are in the United States." << std::endl;
    }

    /**
     * How much money can I earn every month?
     * @param dollar The money in dollar I can earn every month
     */
    void earn(int dollar) {
        std::cout << "You earn " << dollar << " dollar every month." << std::endl;
    }

    /**
     * How much money can I earn every day?
     * @param dollar The money in dollar I can earn every day
     */
    void earn(double dollar) {
        std::cout << "You earn " << dollar << " dollar every day." << std::endl;
    }
}