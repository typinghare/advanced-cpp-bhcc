#include "SuperUser.h"

#include <utility>
#include "User.h"

SuperUser::SuperUser() : User(), privileges(std::byte{0}) {
}

SuperUser::SuperUser(
    std::string userName,
    std::string password,
    int userID,
    std::byte privileges
) : User(std::move(userName), std::move(password), userID), privileges(privileges) {
}

SuperUser::~SuperUser() = default;

std::byte SuperUser::getPrivileges() {
    return privileges;
}

std::string SuperUser::toString() {
    return User::toString() + "; Privileges: " + std::to_string((int) privileges);
}

void SuperUser::changePrivileges(std::byte _privileges) {
    privileges = _privileges;
}

bool SuperUser::operator>(const SuperUser &superUser) {
    return (privileges & superUser.privileges) == superUser.privileges
           && privileges > superUser.privileges;
}

bool SuperUser::operator<(const SuperUser &superUser) {
    return (privileges & superUser.privileges) == privileges
           && privileges < superUser.privileges;
}

bool SuperUser::operator>=(const SuperUser &superUser) {
    return (privileges & superUser.privileges) == superUser.privileges;
}

bool SuperUser::operator<=(const SuperUser &superUser) {
    return (privileges & superUser.privileges) == privileges;
}

bool SuperUser::operator!=(const SuperUser &superUser) {
    return privileges != superUser.privileges;
}

bool SuperUser::operator==(const SuperUser &superUser) {
    return privileges == superUser.privileges;
}

std::istream &operator>>(std::istream &is, SuperUser &superUser) {
    int privileges;
    is >> static_cast<User &>(superUser) >> privileges;
    superUser.privileges = std::byte(privileges);

    return is;
}

std::ostream &operator<<(std::ostream &os, SuperUser &superUser) {
    return os << static_cast<User &>(superUser)
              << static_cast<int>(superUser.privileges);
}
