#include "FieldController.h"
#include <iostream>

FieldController::FieldController(FieldRepository& fr) : repo(fr) {
    fields = repo.get_fields();
}

void FieldController::add_field(const Field& field) {
    fields.push_back(field);
    repo.add_field(field);
}

void FieldController::show_fields() {



    for (const auto& field : fields) {
        std::cout << "ID: " << field.get_id_field()
                  << ", Tip: " << field.get_type_field()
                  << ", Conditie: " << field.get_condition_field()
                  << ", Max jucatori: " << field.get_max_players_field()
                  << ", Privat: " << (field.get_is_private() ? "Da" : "Nu") << "\n";
    }
}

Field* FieldController::get_field_by_id(int id) {

    for (auto& field : fields) {
        if (field.get_id_field() == id) {
            return &field;
        }
    }
    return nullptr;
}

std::vector<Field>& FieldController::get_all_fields() {

    return fields;
}