#pragma once
#include <string>
#include "Entity.h"

class Equipment : public Entity {
    std::string type_equipment;
    std::string condition_equipment;
    int id_user;

public:
    Equipment(int id, std::string type, std::string cond);

    int get_id_equipment() const;
    std::string get_type_equipment() const;
    std::string get_condition_equipment() const;
    int get_id_user() const;
    void set_id_user(int id);

    std::string getInfo() const override;
};
