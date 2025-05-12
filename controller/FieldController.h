
#pragma once

#include "Field.h"
#include <vector>

class FieldController {
private:
    std::vector<Field> fields;

public:
    void add_field(const Field& field);
    Field* get_field_by_id(int id);
    std::vector<Field>& get_all_fields();
};

