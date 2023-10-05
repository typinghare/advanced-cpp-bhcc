#ifndef ADVANCED_CPP_BHCC_SUPERUSER_H
#define ADVANCED_CPP_BHCC_SUPERUSER_H

#include <iostream>
#include "User.h"

class SuperUser : public User {
private:
    std::byte privileges;
public:
    SuperUser(std::string userName, std::string password, int userID, std::byte privileges);

    ~SuperUser();

    std::byte getPrivileges();

    std::string toString() override;

    void changePrivileges(std::byte _privileges);

    // overload all comparison operators (based on the privileges)

    // I find it hard to establish a criteria after wandering for ten minutes. Here's my attempt:
    // If superuser A has all privileges that superuser B has, A >= B; only if superuser A has an
    // extra privilege that superuser B doesn't have, A > B. Likewise for the <= and <.
    // If superuser A's privilege number equals to superuser B's privilege number, then A == B;
    // otherwise, A != B.
    bool operator>(const SuperUser &superUser);

    bool operator<(const SuperUser &superUser);

    bool operator!=(const SuperUser &superUser);

    bool operator==(const SuperUser &superUser);

    bool operator<=(const SuperUser &superUser);

    bool operator>=(const SuperUser &superUser);


public:
    static const std::byte PRIVILEGE_READ = std::byte{0b00000001};
    static const std::byte PRIVILEGE_EDIT = std::byte{0b00000010};
    static const std::byte PRIVILEGE_ADD = std::byte{0b00000100};
    static const std::byte PRIVILEGE_DELT = std::byte{0b00001000};
};

#endif
