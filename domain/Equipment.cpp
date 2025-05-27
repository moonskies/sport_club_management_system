#include "Equipment.h"

Equipment::Equipment(int id, std::string type, std::string cond)
    : Entity(id), type_equipment(type), condition_equipment(cond), id_user(-1) {}  // Default value for id_user is -1

int Equipment::get_id_equipment() const {
    return id;  // folosim id moștenit din Entity
}

std::string Equipment::get_type_equipment() const {
    return type_equipment;
}

std::string Equipment::get_condition_equipment() const {
    return condition_equipment;
}

int Equipment::get_id_user() const {
    return id_user;
}

void Equipment::set_id_user(int id) {
    id_user = id;
}
std::string Equipment::getInfo() const {
    return "Equipment: " + type_equipment + " (" + condition_equipment + ")";
}
