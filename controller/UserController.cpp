#include "UserController.h"

#include <iostream>

UserController::UserController(UserRepository& ur, FieldRepository& fr, EquipmentRepository& er)
    : user_repo(ur), field_repo(fr), equipment_repo(er) {}

void UserController::show_users() {
    for (auto user: user_repo.get_users() ) {
        std::cout << "id: "<< user.get_id_user() <<",name: "<< user.get_name_user() ;
        std::cout<< ", ids_field: ";
        for (auto field: user.get_field_user())
            std::cout <<field<<" ";
        std::cout<< ", ids_equipment: ";
        for (auto equipment: user.get_equipment_user())
            std::cout << equipment<<" ";
        std::cout << std::endl;
    }

}

void UserController::add_user(int id,std::string name) {
    user_repo.add_user(User(id,name));
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

bool UserController::spectate_match(int user_id, int field_id) {
    for (auto& user : user_repo.get_users()) {
         if (user.get_id_user() == user_id) {
            for (auto& field : field_repo.get_fields()) {
                 if (field.get_id_field() == field_id) {
                     field.add_spectator(user_id);
                     return true;
                 }
            }
         }
    }
    return false;
}