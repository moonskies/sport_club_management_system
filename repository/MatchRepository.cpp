//
// Created by andre on 12/05/2025.
//
#include "MatchRepository.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <filesystem>

void MatchRepository::addMatch(const std::string& sport, const std::string& location, int capacity, bool isPublic) {
    Match match(nextId++, sport, location, capacity, isPublic);
    matches.push_back(match);
    std::cout << "Current working directory: "
              << std::filesystem::current_path() << std::endl;

    save_to_file("../data/match.txt");

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

void MatchRepository::save_to_file(const std::string& filename) const {


    std::ofstream out(filename);
    if (!out) throw std::runtime_error("Could not open file for writing: " + filename);

    std::cout<<"salutt";

    for (const auto& match : matches) {
        out << match.getId() << "|"
            << match.getSport() << "|"
            << match.getLocation() << "|"
            << match.getMaxParticipants() << "|"
            << (match.getIsPublic() ? 1 : 0) << "|";

        // participants
        for (size_t i = 0; i < match.getParticipants().size(); ++i) {
            out << match.getParticipants()[i];
            if (i != match.getParticipants().size() - 1)
                out << ",";
        }

        out << "|";

        // spectators
        for (size_t i = 0; i < match.getSpectators().size(); ++i) {
            out << match.getSpectators()[i];
            if (i != match.getSpectators().size() - 1)
                out << ",";
        }

        out << "\n";
    }

    out.close();
}

void MatchRepository::load_from_file(const std::string& filename) {

    //filename="../match.txt";

    std::ifstream in(filename);
    if (!in) throw std::runtime_error("Could not open file for reading: " + filename);

    matches.clear();
    nextId = 1;

    std::string line;
    while (std::getline(in, line)) {
        std::istringstream ss(line);
        std::string token;

        std::getline(ss, token, '|');
        int id = std::stoi(token);

        std::getline(ss, token, '|');
        std::string sport = token;

        std::getline(ss, token, '|');
        std::string location = token;

        std::getline(ss, token, '|');
        int capacity = std::stoi(token);

        std::getline(ss, token, '|');
        bool isPublic = std::stoi(token) == 1;

        std::getline(ss, token, '|');
        std::vector<std::string> participants;
        std::istringstream pss(token);
        std::string name;
        while (std::getline(pss, name, ',')) {
            if (!name.empty()) participants.push_back(name);
        }

        std::getline(ss, token, '|');
        std::vector<std::string> spectators;
        std::istringstream sss(token);
        while (std::getline(sss, name, ',')) {
            if (!name.empty()) spectators.push_back(name);
        }

        Match match(id, sport, location, capacity, isPublic);
        for (const auto& p : participants) match.addParticipant(p);
        for (const auto& s : spectators) match.addSpectator(s);

        matches.push_back(match);
        nextId = std::max(nextId, id + 1);
    }

    in.close();
}




//design pattern ..., mvc???, dc e referinta acolo la clasa, templetizare polimorfism, stl standard template levels