// Equipment.cpp
#include "Equipment.h"

Equipment::Equipment(int id, std::string type, std::string cond, int user_id)
    : id_equipment(id), type_equipment(type), condition_equipment(cond), id_user(user_id) {}

int Equipment::get_id_equipment() const { return id_equipment; }
std::string Equipment::get_type_equipment() const { return type_equipment; }
std::string Equipment::get_condition_equipment() const { return condition_equipment; }
int Equipment::get_id_user() const { return id_user; }
void Equipment::set_id_user(int user_id) { id_user = user_id; }
