#include "EquipmentRepository.h"
#include "Equipment.h"
#include <fstream>
#include <sstream>
#include <iostream>

void EquipmentRepository::add_equipment(const Equipment& e) {
    equipments.push_back(e);
}

std::vector<Equipment>& EquipmentRepository::get_equipments() {
    return equipments;
}

void EquipmentRepository::save_to_file(const std::string& filename) {
    std::ofstream fout(filename);
    for (auto& e : equipments) {
        fout << e.get_id_equipment() << "|" << e.get_type_equipment() << "|"
             << e.get_condition_equipment() << "\n";
    }

}


void EquipmentRepository::load_from_file(const std::string& filename) {
    equipments.clear();
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "Could not open file for reading: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, '|')) {
            tokens.push_back(token);
        }

        if (tokens.size() != 3) {
            std::cerr << "Skipping malformed line in equipment file: " << line << std::endl;
            continue;
        }

        try {
            int id = std::stoi(tokens[0]);
            std::string type = tokens[1];
            std::string condition = tokens[2];

            equipments.emplace_back(id, type, condition);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << "\nReason: " << e.what() << std::endl;
        }
    }

    fin.close();
}


Equipment* EquipmentRepository::find_equipment(int id) {
    for (auto& equipment : equipments) {
        if (equipment.get_id_equipment() == id)
            return &equipment;
    }
    return nullptr;
}

bool EquipmentRepository::reserve_equipment(int id, int user_id) {
    Equipment* equipment = find_equipment(id);
    if (equipment && equipment->get_id_user() == -1) {
        equipment->set_id_user(user_id);
        return true;
    }
    return false;
}