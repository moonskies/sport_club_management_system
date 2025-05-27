#include "Field.h"

Field::Field(int id, std::string type, std::string cond, int max_players, bool privat)
    : Entity(id), // apelăm constructorul clasei de bază
      type_field(type),
      condition_field(cond),
      max_players_field(max_players),
      is_private(privat) {}

// Nu mai avem nevoie de id_field, folosim id din Entity
int Field::get_id_field() const {
    return id;
}

std::string Field::get_type_field() const {
    return type_field;
}

std::string Field::get_condition_field() const {
    return condition_field;
}

int Field::get_max_players_field() const {
    return max_players_field;
}

void Field::add_spectator(int id_user) {
    spectators.push_back(id_user);
}

std::vector<int> Field::get_spectators() const {
    return spectators;
}

bool Field::get_is_private() const {
    return is_private;
}

void Field::set_is_private(bool value) {
    is_private = value;
}
std::string Field::getInfo() const {
    return "Field: " + type_field + " (" + condition_field + ")";
}
