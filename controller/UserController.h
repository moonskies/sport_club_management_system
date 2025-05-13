// UserController.h
#pragma once
#include "../repository/UserRepository.h"
#include "../repository/FieldRepository.h"
#include "../repository/EquipmentRepository.h"

class UserController {
    UserRepository& user_repo;
    FieldRepository& field_repo;
    EquipmentRepository& equipment_repo;

public:
    UserController(UserRepository& ur, FieldRepository& fr, EquipmentRepository& er);
    void add_user(int id,std::string name);
    void show_users();
    bool field_reservation(int user_id, const std::string& field_type);
    bool equipment_reservation(int user_id, const std::string& type,int qty);
    bool spectate_match(int user_id, int field_id);

    User* get_user_by_id(int id); //pt utilizator extern
};
