
#pragma once

#include "Field.h"
#include <vector>
#include "../repository/FieldRepository.h"

class FieldController {
private:
    std::vector<Field> fields;

public:
    FieldController(FieldRepository& fr);
    void add_field(const Field& field);
    void show_fields();
    Field* get_field_by_id(int id);
    std::vector<Field>& get_all_fields();
};

