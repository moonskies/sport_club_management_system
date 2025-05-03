// Field.h
#pragma once
#include <string>

class Field {
    int id_field;
    std::string type_field;
    std::string condition_field;
    int max_players_field;

public:
    Field(int id, std::string type, std::string cond, int max_players);
    int get_id_field() const;
    std::string get_type_field() const;
    std::string get_condition_field() const;
    int get_max_players_field() const;
};
