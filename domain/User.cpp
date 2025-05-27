#include "User.h"

User::User(int id, std::string name,
           std::vector<int> ids_field,
           std::vector<int> ids_equipment)
    : Entity(id), name(name),
      ids_field(ids_field),
      ids_equipment(ids_equipment) {}

int User::get_id_user() const {
    return id;  // moștenit din Entity
}

std::string User::get_name_user() const {
    return name;
}

std::vector<int> User::get_field_user() const {
    return ids_field;
}

std::vector<int> User::get_equipment_user() const {
    return ids_equipment;
}

void User::add_field(int id_field) {
    ids_field.push_back(id_field);
}

void User::add_equipment(int id_equipment) {
    ids_equipment.push_back(id_equipment);
}

std::string User::getInfo() const {
    return "User: " + name;
}

