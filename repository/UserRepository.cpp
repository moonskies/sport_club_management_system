// UserRepository.cpp
#include "UserRepository.h"
#include <fstream>

void UserRepository::add_user(const User& u) {
    users.push_back(u);
}

std::vector<User>& UserRepository::get_users() {
    return users;
}

void UserRepository::save_to_file(const std::string& filename) {
    std::ofstream fout(filename);
    for (auto& u : users) {
        fout << u.get_id_user() << "\n";
    }
}

void UserRepository::load_from_file(const std::string& filename) {
    std::ifstream fin(filename);
    int id;
    while (fin >> id) {
        users.emplace_back(id);
    }
}
