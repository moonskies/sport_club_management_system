#pragma once
#include <string>
#include <vector>
#include "Entity.h"

class Field : public Entity {
    std::string type_field;
    std::string condition_field;
    int max_players_field;
    bool is_private;
    std::vector<int> spectators;

public:
    Field(int id, std::string type, std::string cond, int max_players, bool privat);

    int get_id_field() const;
    std::string get_type_field() const;
    std::string get_condition_field() const;
    int get_max_players_field() const;
    bool get_is_private() const;
    std::vector<int> get_spectators() const;
    void set_is_private(bool value);
    void add_spectator(int id_user);

    std::string getInfo() const override;
};
