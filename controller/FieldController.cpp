//
// Created by Alexandra Bota on 12.05.2025.
//
#include "FieldController.h"

void FieldController::add_field(const Field& field) {
    fields.push_back(field);
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
