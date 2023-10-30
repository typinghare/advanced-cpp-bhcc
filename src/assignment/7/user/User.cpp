#include "User.h"
#include "Secure.h"
#include <sstream>

const std::string User::KEY = "MySecretKey";

User::User() : userID(0) {
}

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

std::istream &operator>>(std::istream &is, User &user) {
    std::string encryptedUserName, encryptedPassword;
    is >> encryptedUserName >> encryptedPassword >> user.userID;
    user.userName = decrypt(encryptedUserName, User::KEY);
    user.password = decrypt(encryptedPassword, User::KEY);

    return is;
}


std::ostream &operator<<(std::ostream &os, const User &user) {
    return os << encrypt(user.userName, User::KEY) << " "
              << encrypt(user.password, User::KEY) << " "
              << user.userID << " ";
}
