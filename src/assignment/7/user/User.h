#ifndef ADVANCED_CPP_BHCC_USER_H
#define ADVANCED_CPP_BHCC_USER_H

#include <iostream>
#include <utility>

class User {
private:
    std::string userName;
    std::string password;
    int userID;
public:
    User(std::string userName, std::string password, int userID);

    ~User();

    /**
     * @brief Sets password for this user.
     * @param password The password to set.
     */
    void setPassword(std::string_view password);

    /**
     * @brief Returns user's name.
     */
    std::string getUserName();

    /**
     * @brief Returns user's password.
     */
    std::string getPassword();

    /**
     * @brief Returns user ID.
     */
    [[nodiscard]] int getUserID() const;

    /**
     * @brief Returns a string of description of this user.
     */
    virtual std::string toString();
};

#endif
