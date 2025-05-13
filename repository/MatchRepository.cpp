//
// Created by andre on 12/05/2025.
//
#include "MatchRepository.h"
#include <iostream>

void MatchRepository::addMatch(const std::string& sport, const std::string& location, int capacity, bool isPublic) {
    Match match(nextId++, sport, location, capacity, isPublic);
    matches.push_back(match);
}

std::vector<Match> MatchRepository::getAllMatches() const {
    return matches;
}

std::vector<Match> MatchRepository::searchBySport(const std::string& sport) const {
    std::vector<Match> result;
    for (const auto& match : matches) {
        if (match.getSport() == sport) {
            result.push_back(match);
        }
    }
    return result;
}

Match* MatchRepository::findById(int id) {
    for (auto& match : matches) {
        if (match.getId() == id) {
            return &match;
        }
    }
    return nullptr;
}

std::vector<Match>& MatchRepository::getMatches() {
    return matches;
}


//design pattern ..., mwc???, dc e referinta acolo la clasa, templetizare polimorfism, stl standard template levels