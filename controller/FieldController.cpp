//
// Created by Alexandra Bota on 12.05.2025.
//
#include "FieldController.h"

#include <iostream>



void FieldController::show_fields()  {

    for ( auto field: fields) {
        std::cout <<  "fieldcontrollercpp";
        std::cout << field.get_id_field() << " "<< field.get_type_field() << " "
        << field.get_condition_field() << " "<< field.get_max_players_field()<< " "<< field.get_is_private();
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
