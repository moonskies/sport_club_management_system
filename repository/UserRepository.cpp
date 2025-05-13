// UserRepository.cpp
#include "UserRepository.h"
#include "../domain/User.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <iostream>

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
    std::cout<<" hello";
    users.clear();
    std::ifstream fin(filename);
    std::string line;

    if (!fin.is_open()) {throw std::runtime_error("File does not exist");}


    while (std::getline(fin, line)) {

        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> tokens;

        while (std::getline(ss, segment, '|')) {
            tokens.push_back(segment);
        }

        if (tokens.size() < 4) continue;

        User user(0,0);
        user.id_user = std::stoi(tokens[0]);
        user.name = tokens[1];

        user.ids_field.clear();
        std::stringstream field_ss(tokens[2]);
        while (std::getline(field_ss, segment, ',')) {
            user.ids_field.push_back(std::stoi(segment));
        }

        user.ids_equipment.clear();
        std::stringstream equip_ss(tokens[3]);
        while (std::getline(equip_ss, segment, ',')) {
            user.ids_equipment.push_back(std::stoi(segment));
        }
        std::cout<<user.id_user<< " "<< user.name;
        users.push_back(user);
    }
}

