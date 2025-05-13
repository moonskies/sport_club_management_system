// UserRepository.h
#pragma once
#include "../domain/User.h"
#include <vector>
#include <string>

class UserRepository {
    std::vector<User> users;

public:
    void add_user(const User& u);
    std::vector<User>& get_users();
    void save_to_file(const std::string& filename) const;
    void load_from_file(const std::string& filename);
};
