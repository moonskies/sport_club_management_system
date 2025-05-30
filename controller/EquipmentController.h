#ifndef EQUIPMENTCONTROLLER_H
#define EQUIPMENTCONTROLLER_H

#endif //EQUIPMENTCONTROLLER_H
#include "EquipmentRepository.h"
#include <vector>
#include <string>
#pragma once

class EquipmentController {
    EquipmentRepository& equipmentRepo;

public:
    EquipmentController(EquipmentRepository& repo) : equipmentRepo(repo) {}
    bool reserve_equipment(int user_id, int equipment_id);
    std::vector<Equipment> get_all_equipment() const;
    bool add_equipment(int id, const std::string& type, const std::string& condition);
    void show_equipment() const;
};