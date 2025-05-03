#include "User.h"

User::User(int id) : id_user(id) {}

int User::get_id_user() const { return id_user; }

std::vector<int> User::get_field_user() const { return ids_field; }

std::vector<int> User::get_equipment_user() const { return ids_equipment; }

void User::add_field(int id) { ids_field.push_back(id); }

void User::add_equipment(int id) { ids_equipment.push_back(id); }
