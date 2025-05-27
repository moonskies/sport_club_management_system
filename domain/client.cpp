//
// Created by User on 5/27/2025.
//

#include "client.h"
Client::Client(int id, const std::string& name,
               const std::string& email, const std::string& phone,
               std::vector<int> ids_field,
               std::vector<int> ids_equipment)
    : User(id, name, ids_field, ids_equipment),
      email(email), phone(phone) {}

std::string Client::get_email() const {
    return email;
}

std::string Client::get_phone() const {
    return phone;
}

void Client::set_email(const std::string& em) {
    email = em;
}

void Client::set_phone(const std::string& ph) {
    phone = ph;
}
