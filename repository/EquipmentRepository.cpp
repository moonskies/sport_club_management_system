// EquipmentRepository.cpp
#include "EquipmentRepository.h"
#include <fstream>

void EquipmentRepository::add_equipment(const Equipment& e) {
    equipments.push_back(e);
}

std::vector<Equipment>& EquipmentRepository::get_equipments() {
    return equipments;
}

void EquipmentRepository::save_to_file(const std::string& filename) {
    std::ofstream fout(filename);
    for (auto& e : equipments) {
        fout << e.get_id_equipment() << " " << e.get_type_equipment() << " "
             << e.get_condition_equipment() << "\n";
    }
}

void EquipmentRepository::load_from_file(const std::string& filename) {
    std::ifstream fin(filename);
    int id;
    std::string type, condition;
    while (fin >> id >> type >> condition) {
        equipments.emplace_back(id, type, condition);
    }
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

