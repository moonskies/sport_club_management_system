//
// Created by andre on 12/05/2025.
//
#pragma once
#include "MatchRepository.h"
#include <optional>
#include <vector>
#include <string>

class MatchController {
private:
    MatchRepository& repo;

public:
    // Constructor care primește o referință la un repository
    MatchController(MatchRepository& repo);

    // Adaugă un meci nou
    void addMatch(const std::string& sport, const std::string& location, int capacity, bool isPublic);

    // Returnează toate meciurile
    std::vector<Match> getAllMatches() const;

    // Returnează meciuri filtrate după sport
    std::vector<Match> searchBySport(const std::string& sport) const;

    // Încearcă să înscrie un utilizator la un meci, dacă este public și are locuri
    bool enrollUserToMatch(int matchId, const std::string& username);

    // Returnează numărul de locuri disponibile pentru un meci (dacă există)
    std::optional<int> getAvailableSpots(int matchId) const;
};
