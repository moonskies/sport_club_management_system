//
// Created by andre on 12/05/2025.
//
#pragma once
#include <vector>
#include <string>
#include "Match.h"

class MatchRepository {
private:
    std::vector<Match> matches;  // lista de meciuri
    int nextId = 1;              // ID unic pentru fiecare meci

public:
    MatchRepository() = default;

    // Adaugă un meci nou
    void addMatch(const std::string& sport, const std::string& location, int capacity, bool isPublic);

    // Returnează toate meciurile
    std::vector<Match> getAllMatches() const;

    // Caută meciuri după sport (ex: „fotbal”)
    std::vector<Match> searchBySport(const std::string& sport) const;

    // Găsește un meci după ID (folosit pentru înscriere)
    Match* findById(int id);
};
