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

void UserRepository::save_to_file(const std::string& filename) const {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const User& user : users) {
        fout << user.id << "|";
        fout << user.name << "|";

        // Write ids_field
        for (size_t i = 0; i < user.ids_field.size(); ++i) {
            fout << user.ids_field[i];
            if (i < user.ids_field.size() - 1)
                fout << ",";
        }

        fout << "|";

        // Write ids_equipment
        for (size_t i = 0; i < user.ids_equipment.size(); ++i) {
            fout << user.ids_equipment[i];
            if (i < user.ids_equipment.size() - 1)
                fout << ",";
        }

        fout << "\n";
    }

    fout.close();
}

void UserRepository::load_from_file(const std::string& filename) {
    users.clear();
    std::ifstream fin(filename);
    std::string line;

    if (!fin.is_open()) { throw std::runtime_error("File does not exist"); }

    while (std::getline(fin, line)) {


        std::stringstream ss(line);
        std::string segment;
        std::vector<std::string> tokens;

        while (std::getline(ss, segment, '|')) {
            tokens.push_back(segment);
        }


        if (tokens.size() != 4) continue;



        User user(0,"0");
        user.id = std::stoi(tokens[0]);
        user.name = tokens[1];

       //user.ids_field.clear();
        std::stringstream field_ss(tokens[2]);
        while (std::getline(field_ss, segment, ',')) {
            if (!segment.empty())
                user.ids_field.push_back(std::stoi(segment));
        }

        //user.ids_equipment.clear();
        std::stringstream equip_ss(tokens[3]);
        while (std::getline(equip_ss, segment, ',')) {
            if (!segment.empty())
                user.ids_equipment.push_back(std::stoi(segment));
        }
        users.push_back(user);
    }

}

