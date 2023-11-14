
#include "User.h"
#include "SuperUser.h"
#include "Secure.h"

/**
 * @brief Test User and SuperUser.
 * @link https://online.bhcc.edu/mod/assign/view.php?id=1980936
 */
int main() {
    const int FIRST_USER_ID{1000};
    int userId = FIRST_USER_ID;

    // Create two users, one of which is on the heap
    User userOnStack("James", "123456", userId++);
    auto *userOnHeap = new User("Andrew", "654321", userId++);

    // Create two superusers, one of which is on the heap
    SuperUser superUserOnStack(
        "Hellen", "abc123", userId++,
        SuperUser::PRIVILEGE_ADD | SuperUser::PRIVILEGE_READ
    );
    auto *superUserOnHeap = new SuperUser(
        "Patrick", "321cba", userId++,
        SuperUser::PRIVILEGE_DELT | SuperUser::PRIVILEGE_EDIT
    );

    // Test toString()
    std::cout << userOnHeap->toString() << std::endl;
    std::cout << superUserOnStack.toString() << std::endl;

    // Test setPassword() and getters
    userOnStack.setPassword("19990312");
    std::cout << userOnStack.getPassword() << std::endl;                // 19990312
    std::cout << userOnStack.getUserID() << std::endl;                  // 1000
    std::cout << superUserOnHeap->getUserName() << std::endl;           // Patrick
    std::cout << (short) superUserOnHeap->getPrivileges() << std::endl; // 10

    // Test comparison operators #1
    std::cout << (superUserOnStack < *superUserOnHeap) << std::endl;    // 0
    std::cout << (superUserOnStack >= *superUserOnHeap) << std::endl;   // 0
    std::cout << (superUserOnStack != *superUserOnHeap) << std::endl;   // 1

    // Test changePrivileges
    // 1. Add a privilege
    superUserOnStack.changePrivileges(
        superUserOnStack.getPrivileges() | SuperUser::PRIVILEGE_DELT
    );
    std::cout << (short) superUserOnStack.getPrivileges() << std::endl; // 13
    // 2. Remove a privilege
    superUserOnHeap->changePrivileges(
        superUserOnHeap->getPrivileges() ^ SuperUser::PRIVILEGE_EDIT
    );
    std::cout << (short) superUserOnHeap->getPrivileges() << std::endl; // 12_dated

    // Test comparison operators #2
    // Now superUserOnStack has ADD, READ, DELT, while superUserOnHeap has DELT
    std::cout << (superUserOnStack >= *superUserOnHeap) << std::endl;   // 1
    std::cout << (superUserOnStack > *superUserOnHeap) << std::endl;    // 1

    // Test Secure (encrypt and decrypt)
    std::string message = "James";
    std::string key = "JumpHigher";
    std::string encryptedMessage = encrypt(message, key);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    std::cout << "Original message: " << decrypt(encryptedMessage, key) << std::endl;

    // Output a user
    std::cout << "User on stack: " << userOnStack << std::endl;
    std::cout << "User on heap: " << *userOnHeap << std::endl;

    // New user
//    User user = User();
//    std::cout << "Input: ";
//    std::cin >> user;
//    std::cout << user.getUserName() << std::endl;

    std::cout << "Super user on stack: " << superUserOnStack << std::endl;
//    SuperUser superUser = SuperUser();
//    std::cin >> superUser;
//    std::cout << (int) superUser.getPrivileges() << std::endl;

    // Delete variables on the heap
    delete userOnHeap;
    delete superUserOnHeap;

    return 0;
}