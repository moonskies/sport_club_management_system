// FieldRepository.cpp
#include "FieldRepository.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "FieldController.h"

//FieldController(FieldRepository& fr) : fields(fr.get_fields()) {}

void FieldRepository::add_field(const Field& f) {
    fields.push_back(f);
}

std::vector<Field>& FieldRepository::get_fields() {
    return fields;
}

void FieldRepository::save_to_file(const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cerr << "Could not open file for writing: " << filename << std::endl;
        return;
    }

    for (const Field& f : fields) {
        fout << f.get_id_field() << "|"
             << f.get_type_field() << "|"
             << f.get_condition_field() << "|"
             << f.get_max_players_field() << "|"
             << (f.get_is_private() ? 1 : 0) << "\n";
    }

    fout.close();
}

// Load fields from file
void FieldRepository::load_from_file(const std::string& filename) {
    fields.clear();
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cerr << "Could not open file for reading: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        while (std::getline(ss, token, '|')) {
            tokens.push_back(token);
        }

        if (tokens.size() != 5) {
            std::cerr << "Skipping malformed line: " << line << std::endl;
            continue;
        }

        try {
            int id = std::stoi(tokens[0]);
            std::string type = tokens[1];
            std::string condition = tokens[2];
            int max_players = std::stoi(tokens[3]);
            bool is_private = (std::stoi(tokens[4]) != 0);

            Field f(id, type, condition, max_players, is_private);
            fields.push_back(f);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << "\nReason: " << e.what() << std::endl;
        }
    }

    fin.close();
}
