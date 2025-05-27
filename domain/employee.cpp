//
// Created by User on 5/27/2025.
//

#include "employee.h"
Employee::Employee(int id, const std::string& name,
                   const std::string& position, double salary,
                   std::vector<int> ids_field,
                   std::vector<int> ids_equipment)
    : User(id, name, ids_field, ids_equipment),
      position(position), salary(salary) {}

std::string Employee::get_position() const {
    return position;
}

double Employee::get_salary() const {
    return salary;
}

void Employee::set_position(const std::string& pos) {
    position = pos;
}

void Employee::set_salary(double sal) {
    salary = sal;
}