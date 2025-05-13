//
// Created by andre on 12/05/2025.
//
#include "Match.h"

Match::Match(int id, const std::string& sport, const std::string& location, int maxParticipants, bool isPublic)
    : id(id), sport(sport), location(location), maxParticipants(maxParticipants), isPublic(isPublic) {}

int Match::getId() const { return id; }
std::string Match::getSport() const { return sport; }
std::string Match::getLocation() const { return location; }
int Match::getMaxParticipants() const { return maxParticipants; }
bool Match::getIsPublic() const { return isPublic; }
std::vector<std::string> Match::getParticipants() const { return participants; }

int Match::getAvailableSpots() const {
    return maxParticipants - participants.size();
}

void Match::addParticipant(const std::string& username) {
    if (participants.size() < maxParticipants && !isUserEnrolled(username)) {
        participants.push_back(username);
    }
}

bool Match::isUserEnrolled(const std::string& username) const {
    for (const auto& user : participants) {
        if (user == username)
            return true;
    }
    return false;
}

void Match::addSpectator(const std::string& name) {
    spectators.push_back(name);
}

std::vector<std::string> Match::getSpectators() const {
    return spectators;
}

