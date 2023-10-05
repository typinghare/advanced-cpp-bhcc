#include "User.h"
#include <sstream>

User::User(
    std::string userName,
    std::string password,
    int userID
) : userName(std::move(userName)), password(std::move(password)), userID(userID) {
}

User::~User() = default;

void User::setPassword(std::string_view _password) {
    password = _password;
}

std::string User::getUserName() {
    return userName;
}

std::string User::getPassword() {
    return password;
}

int User::getUserID() const {
    return userID;
}

std::string User::toString() {
    std::stringstream ss;

    ss << "ID: " << userID << "; "
       << "UserName: " << userName << "; "
       << "Password: " << password;

    return ss.str();
}