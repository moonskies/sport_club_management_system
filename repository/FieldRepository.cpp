// FieldRepository.cpp
#include "FieldRepository.h"
#include <fstream>

void FieldRepository::add_field(const Field& f) {
    fields.push_back(f);
}

std::vector<Field>& FieldRepository::get_fields() {
    return fields;
}

void FieldRepository::save_to_file(const std::string& filename) {
    std::ofstream fout(filename);
    for (auto& f : fields) {
        fout << f.get_id_field() << " " << f.get_type_field() << " "
             << f.get_condition_field() << " " << f.get_max_players_field() << "\n";
    }
}

void FieldRepository::load_from_file(const std::string& filename) {
    std::ifstream fin(filename);
    int id, max_players;
    bool privat;
    std::string type, condition;
    while (fin >> id >> type >> condition >> max_players >> privat) {
        fields.emplace_back(id, type, condition, max_players,privat);
    }
}
