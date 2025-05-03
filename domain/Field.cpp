// Field.cpp
#include "Field.h"

Field::Field(int id, std::string type, std::string cond, int max_players)
    : id_field(id), type_field(type), condition_field(cond), max_players_field(max_players) {}

int Field::get_id_field() const { return id_field; }
std::string Field::get_type_field() const { return type_field; }
std::string Field::get_condition_field() const { return condition_field; }
int Field::get_max_players_field() const { return max_players_field; }
