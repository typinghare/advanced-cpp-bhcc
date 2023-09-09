
#include <iostream>

namespace china {
    /**
     * Prints the namespace I am in.
     */
    void whereAmI() {
        std::cout << "You are in China." << std::endl;
    }

    /**
     * How much money can I earn every month?
     * @param rmb The money in RMB I can earn every month
     */
    void earn(int rmb) {
        std::cout << "You earn " << rmb << " RMB every month." << std::endl;
    }

    /**
     * How much money can I earn every day?
     * @param rmb The money in RMB I can earn every day
     */
    void earn(double rmb) {
        std::cout << "You earn " << rmb << " RMB every day." << std::endl;
    }
}