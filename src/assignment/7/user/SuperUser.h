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
    // Thanks to binary representation, if a person has one higher privilege, then their privilege
    // number is greater. For instance, if a person's privilege number is 0b100, they can ADD, and
    // by definition,
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
