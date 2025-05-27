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

    // adauga un meci nou
    void addMatch(const std::string& sport, const std::string& location, int capacity, bool isPublic);

    // returneaza toate meciurile
    std::vector<Match> getAllMatches() const;

    // cauta meciuri dupa sport (ex: „fotbal”)
    std::vector<Match> searchBySport(const std::string& sport) const;

    // gaseste un meci după ID (folosit pentru inscriere)
    Match* findById(int id);

    // returnează referință la vectorul intern cu meciuri
    std::vector<Match>& getMatches();

    void save_to_file(const std::string& filename) const;
    void load_from_file(const std::string& filename);


};
