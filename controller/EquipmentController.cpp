//
// Created by Claudia on 5/13/2025.
//
#pragma once
#include <vector>
#include <string>
#include "EquipmentController.h"
#include <iostream>

bool EquipmentController::reserve_equipment(int user_id, int equipment_id) {
    return equipmentRepo.reserve_equipment(equipment_id, user_id);
}

std::vector<Equipment> EquipmentController::get_all_equipment() const {
    return equipmentRepo.get_equipments();
}

bool EquipmentController::add_equipment(int id, const std::string& type, const std::string& condition) {
    Equipment equipment(id, type, condition);
    equipmentRepo.add_equipment(equipment);
    return true;
}

void EquipmentController::show_equipment() const {
    for (const auto& eq : equipmentRepo.get_equipments()) {
        std::cout << "ID: " << eq.get_id_equipment() << ", Tip: " << eq.get_type_equipment()
                  << ", Stare: " << eq.get_condition_equipment() << ", ID Utilizator: " << eq.get_id_user() << '\n';
    }
}

