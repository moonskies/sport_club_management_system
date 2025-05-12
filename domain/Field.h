// Field.h
#pragma once
#include <string>
#include <vector>


class Field {
    int id_field;
    std::string type_field;
    std::string condition_field;
    int max_players_field;
    bool is_private; //true-private, false-public
    std::vector<int> spectators;

public:
    Field(int id, std::string type, std::string cond, int max_players, bool privat);
    int get_id_field() const;
    std::string get_type_field() const;
    std::string get_condition_field() const;
    int get_max_players_field() const;
    bool get_is_private() const;
    std::vector<int> get_spectators() const

    void add_spectator(int id_user)
};
