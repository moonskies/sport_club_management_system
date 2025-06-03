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
    MatchRepository& repo; //referinta la MatchRepository pt a accesa sau modifica date despre meciuri

public:
    // Constructor care primeste o referinta la un repository
    MatchController(MatchRepository& repo);

    void addMatch(const std::string& sport, const std::string& location, int capacity, bool isPublic);

    std::vector<Match> getAllMatches() const;

    std::vector<Match> searchBySport(const std::string& sport) const;

    // incearca sa înscrie un utilizator la un meci, daca este public și are locuri
    bool enrollUserToMatch(int matchId, const std::string& username);

    // Returneaza numarul de locuri disponibile pentru un meci (daca exista)
    std::optional<int> getAvailableSpots(int matchId) const;

    // caută un meci după ID-ul lui și returnează un pointer
    Match* getMatchById(int id);

    //cauta un meci dupa sport
    std::vector<Match> findMatchesBySport(const std::string& sport);


};

