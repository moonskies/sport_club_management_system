//User.h
#pragma once
#include <string>
#include <vector>

class User {
    friend class UserRepository;
    int id_user;
    std::string name;
    std::vector<int> ids_field;
    std::vector<int> ids_equipment;

public:
    User(int id, std::string name, std::vector<int> ids_field={}, std::vector<int> ids_equipment={});


    int get_id_user() const;
    std::vector<int> get_field_user() const;
    std::vector<int> get_equipment_user() const;
    void add_field(int id);
    void add_equipment(int id);
};
