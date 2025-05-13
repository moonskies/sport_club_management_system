#include "User.h"

User::User(int id, std::string name, std::vector<int> ids_field, std::vector<int> ids_equipment)
    : id_user(id), name(name), ids_field(ids_field), ids_equipment(ids_equipment) {}

int User::get_id_user() const { return id_user; }

std::vector<int> User::get_field_user() const { return ids_field; }

std::vector<int> User::get_equipment_user() const { return ids_equipment; }

void User::add_field(int id) { ids_field.push_back(id); }

void User::add_equipment(int id) { ids_equipment.push_back(id); }
