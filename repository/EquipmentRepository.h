// EquipmentRepository.h
#pragma once
#include "../domain/Equipment.h"
#include <vector>
#include <string>

class EquipmentRepository {
    std::vector<Equipment> equipments;

public:
    void add_equipment(const Equipment& e);
    std::vector<Equipment>& get_equipments();
    void save_to_file(const std::string& filename);
    void load_from_file(const std::string& filename);
    Equipment* find_equipment(int id);
    bool reserve_equipment(int id, int user_id);
};
