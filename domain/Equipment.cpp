// Equipment.cpp
#include "Equipment.h"

Equipment::Equipment(int id, std::string type, std::string cond)
    : id_equipment(id), type_equipment(type), condition_equipment(cond), id_user(-1) {}  // Default value for id_user is -1 (meaning no user assigned)

int Equipment::get_id_equipment() const {
    return id_equipment;
}

std::string Equipment::get_type_equipment() const {
    return type_equipment;
}

std::string Equipment::get_condition_equipment() const {
    return condition_equipment;
}

// Getter for id_user
int Equipment::get_id_user() const {
    return id_user;  // Return the user ID associated with the equipment
}

// Setter for id_user
void Equipment::set_id_user(int id) {
    id_user = id;  // Set the user ID associated with the equipment
}
