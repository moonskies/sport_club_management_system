// Equipment.cpp
#include "Equipment.h"
#include <string>

Equipment::Equipment(int id, std::string type, std::string cond)
    : id_equipment(id), type_equipment(type), condition_equipment(cond) {}

int Equipment::get_id_equipment() const { return id_equipment; }
std::string Equipment::get_type_equipment() const { return type_equipment; }
std::string Equipment::get_condition_equipment() const { return condition_equipment; }
