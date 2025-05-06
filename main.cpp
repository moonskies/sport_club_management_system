#include "controller/UserController.h"
#include "repository/FieldRepository.h"
#include "repository/EquipmentRepository.h"
#include "repository/UserRepository.h"

#include <iostream>

int main() {
    UserRepository ur;
    FieldRepository fr;
    EquipmentRepository er;//ceau

    ur.load_from_file("data/users.txt");
    fr.load_from_file("data/fields.txt.txt");
    er.load_from_file("data/equipment.txt");

    UserController uc(ur, fr, er);

    int opt;
    std::cout << "1. Rezervare teren\n2. Rezervare echipament\nAlege optiunea: ";
    std::cin >> opt;

    if (opt == 1) {
        int user_id;
        std::string type;
        std::cout << "ID user: "; std::cin >> user_id;
        std::cout << "Tip teren: "; std::cin >> type;
        if (uc.field_reservation(user_id, type))
            std::cout << "Teren rezervat cu succes.\n";
        else
            std::cout << "Nu s-a putut rezerva teren.\n";
    } else if (opt == 2) {
        int user_id, qty;
        std::string type;
        std::cout << "ID user: "; std::cin >> user_id;
        std::cout << "Tip echipament: "; std::cin >> type;
        std::cout << "Numar bucati: "; std::cin >> qty;
        if (uc.equipment_reservation(user_id, type, qty))
            std::cout << "Echipament rezervat cu succes.\n";
        else
            std::cout << "Eroare: utilizatorul nu are teren sau nu exista echipament suficient.\n";
    }

    ur.save_to_file("data/users.txt");
    fr.save_to_file("data/fields.txt.txt");
    er.save_to_file("data/equipment.txt");

    return 0;
}
