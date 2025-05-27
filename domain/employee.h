#pragma once
#include "User.h"

class Employee : public User {
    std::string position;
    double salary;

public:
    Employee(int id, const std::string& name,
             const std::string& position, double salary,
             std::vector<int> ids_field = {}, std::vector<int> ids_equipment = {});

    std::string get_position() const;
    double get_salary() const;
    void set_position(const std::string& pos);
    void set_salary(double sal);
};
