#include "ui.h"
#include "../controller/UserController.h"
#include "../repository/FieldRepository.h"
#include "../repository/EquipmentRepository.h"
#include "../repository/UserRepository.h"
#include "../controller/MatchController.h"
#include "../repository/MatchRepository.h"
#include "../controller/EquipmentController.h"

#include <iostream>
#include <string>

#include "FieldController.h"


void showMenu() {
    std::cout << "\n===== MENIU PRINCIPAL =====\n";
    std::cout << "1. Rezervare teren\n";
    std::cout << "2. Rezervare echipament\n";
    std::cout << "3. Adauga meci\n";
    std::cout << "4. Afiseaza toate meciurile\n";
    std::cout << "5. Cauta meci după sport\n";
    std::cout << "6. Inscrie-te la un meci\n";
    std::cout << "7. Afisează locuri disponibile la un meci\n";
    std::cout << "8. Afiseaza userii\n";
    std::cout << "9. Afiseaza terenuri\n";
    std:: cout<< "10. Afiseaza echipament\n";
    std::cout << "11. Specteaza un meci\n";
    std::cout << "0. Iesire\n";
}

void runUI() {
    UserRepository ur;
    FieldRepository fr;
    EquipmentRepository er;
    MatchRepository mr;



    ur.load_from_file("../data/users.txt");
    fr.load_from_file("../data/fields.txt");
    er.load_from_file("../data/equipment.txt");
    mr.load_from_file("../data/match.txt");

    UserController uc(ur, fr, er);
    FieldController fc(fr);
    MatchController mc(mr);
    EquipmentController ec(er);


    //fc.show_fields();

    int opt;
    do {
        showMenu();
        std::cout << "Opțiune: ";
        std::cin >> opt;
        std::cin.ignore();

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
            std::cout << "Număr bucăți: "; std::cin >> qty;
            if (uc.equipment_reservation(user_id, type, qty))
                std::cout << "Echipament rezervat cu succes.\n";
            else
                std::cout << "Eroare: utilizatorul nu are teren sau nu există echipament suficient.\n";

        } else if (opt == 3) {
            std::string sport, location;
            int capacity;
            bool isPublic;

            std::cout << "Sport: "; std::getline(std::cin, sport);
            std::cout << "Locație: "; std::getline(std::cin, location);
            std::cout << "Capacitate: "; std::cin >> capacity;
            std::cout << "Este public (1/0): "; std::cin >> isPublic;
            mc.addMatch(sport, location, capacity, isPublic);
            std::cout << "Meci adăugat cu succes!\n";

        } else if (opt == 4) {
            auto matches = mc.getAllMatches();
            for (const auto& match : matches) {
                std::cout << "ID: " << match.getId()
                          << ", Sport: " << match.getSport()
                          << ", Locație: " << match.getLocation()
                          << ", Locuri disponibile: " << match.getAvailableSpots()
                          << ", Public: " << (match.getIsPublic() ? "Da" : "Nu")
                          << ", Participanți: ";

                for (const auto& p : match.getParticipants())
                    std::cout << p << " ";

                std::cout << ", Spectatori: ";
                for (const auto& s : match.getSpectators())
                    std::cout << s << " ";

                std::cout << "\n";
            }


        } else if (opt == 5) {
            std::string sport;
            std::cout << "Sport cautat: "; std::getline(std::cin, sport);
            auto found = mc.searchBySport(sport);
            for (const auto& match : found) {
                std::cout << "ID: " << match.getId() << ", Locatie: " << match.getLocation()
                          << ", Locuri: " << match.getAvailableSpots() << "\n";
            }

        } else if (opt == 6) {
            int id;
            std::string name;
            std::cout << "ID meci: "; std::cin >> id;
            std::cin.ignore();
            std::cout << "Nume utilizator: "; std::getline(std::cin, name);
            if (mc.enrollUserToMatch(id, name))
                std::cout << "Înscriere reușită!\n";
            else
                std::cout << "Înscriere eșuată. Verifică dacă meciul este public și are locuri.\n";

        } else if (opt == 7) {
            int match_id;
            std::cout << "Introdu ID-ul meciului: ";
            std::cin >> match_id;
            auto available = mc.getAvailableSpots(match_id);
            if (available.has_value()) {
                std::cout << "Locuri disponibile pentru meciul cu ID " << match_id << ": " << available.value() << "\n";
            } else {
                std::cout << "Meciul cu ID-ul " << match_id << " nu a fost găsit.\n";
            }
        }

        else if (opt ==8)
            uc.show_users();
        else if (opt == 9) {
            fc.show_fields();
        }
        else if (opt == 10) {
          ec.show_equipment();
        }
        else if (opt == 11) {
            int match_id;
            std::string name;
            std::cout << "ID meci: "; std::cin >> match_id;
            std::cin.ignore();
            std::cout << "Nume utilizator: "; std::getline(std::cin, name);

            auto match = mc.getMatchById(match_id);
            if (!match) {
                std::cout << "Meciul nu există.\n";
            } else {
                if (match->getIsPublic()) {
                    match->addSpectator(name);
                    std::cout << "Ați fost adăugat ca spectator la meciul public.\n";
                } else {
                    std::cout << "Acesta este un meci privat. Spectarea costă 10 lei. Continuați? (1/0): ";
                    int confirm;
                    std::cin >> confirm;
                    if (confirm == 1) {
                        match->addSpectator(name);
                        std::cout << "Ați fost adăugat ca spectator la meciul privat.\n";
                    } else {
                        std::cout << "Spectarea a fost anulată.\n";
                    }
                }
            }
        }

        // ur.save_to_file("../data/users.txt");
        // fr.save_to_file("../data/fields.txt");
        // er.save_to_file("../data/equipment.txt");
        // er.save_to_file("../data/match.txt");


    } while (opt != 0);

    ur.save_to_file("../data/users.txt");
    fr.save_to_file("../data/fields.txt");
    er.save_to_file("../data/equipment.txt");
    mr.save_to_file("../data/match.txt");



    std::cout << "La revedere!\n";
}
