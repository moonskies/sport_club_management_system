#pragma once
#include "User.h"

class Client : public User {
    std::string email;
    std::string phone;

public:
    Client(int id, const std::string& name,
           const std::string& email, const std::string& phone,
           std::vector<int> ids_field = {}, std::vector<int> ids_equipment = {});

    std::string get_email() const;
    std::string get_phone() const;
    void set_email(const std::string& em);
    void set_phone(const std::string& ph);
};
