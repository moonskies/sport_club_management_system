#pragma once

#include "Field.h"
#include <vector>
#include "../repository/FieldRepository.h"

class FieldController {
private:
    std::vector<Field> fields;
    FieldRepository& repo;  // ADĂUGAT

public:
    FieldController(FieldRepository& fr);  // constructor
    void add_field(const Field& field);
    void show_fields();
    Field* get_field_by_id(int id);
    std::vector<Field>& get_all_fields();
};