#include <iostream>
#include "ui.h"
void UI::reserve_equipment_ui() {
    int user_id, equipment_id;
    std::cout << "Introduceti ID-ul utilizatorului: ";
    std::cin >> user_id;
    std::cout << "Introduceti ID-ul echipamentului: ";
    std::cin >> equipment_id;
    if (userController.reserve_equipment(user_id, equipment_id)) {
        std::cout << "Echipament rezervat cu succes!\n";
    } else {
        std::cout << "Rezervare esuata. Verificati daca echipamentul este deja rezervat.\n";
    }
}