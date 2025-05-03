// UserController.cpp
#include "UserController.h"

UserController::UserController(UserRepository& ur, FieldRepository& fr, EquipmentRepository& er)
    : user_repo(ur), field_repo(fr), equipment_repo(er) {}

void UserController::add_user(int id) {
    user_repo.add_user(User(id));
}

bool UserController::field_reservation(int user_id, const std::string& field_type) {
    for (auto& field : field_repo.get_fields()) {
        if (field.get_type_field() == field_type) {
            for (auto& user : user_repo.get_users()) {
                if (user.get_id_user() == user_id) {
                    user.add_field(field.get_id_field());
                    return true;
                }
            }
        }
    }
    return false;
}

bool UserController::equipment_reservation(int user_id, const std::string& type, int qty) {
    for (auto& user : user_repo.get_users()) {
        if (user.get_id_user() == user_id && !user.get_field_user().empty()) {
            int count = 0;
            for (auto& eq : equipment_repo.get_equipments()) {
                if (eq.get_type_equipment() == type) {
                    user.add_equipment(eq.get_id_equipment());
                    if (++count == qty) return true;
                }
            }
        }
    }
    return false;
}
