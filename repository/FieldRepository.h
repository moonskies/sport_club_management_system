// FieldRepository.h
#pragma once
#include "../domain/Field.h"
#include <vector>
#include <string>

class FieldRepository {
    std::vector<Field> fields;

public:
    void add_field(const Field& f);
    std::vector<Field>& get_fields();
    void save_to_file(const std::string& filename);
    void load_from_file(const std::string& filename);
};
