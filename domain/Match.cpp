#include "Match.h"
#include <algorithm>

Match::Match(int id, const std::string& sport, const std::string& location, int maxParticipants, bool isPublic)
    : Entity(id), sport(sport), location(location), maxParticipants(maxParticipants), isPublic(isPublic) {}

int Match::getId() const {
    return id;
}

std::string Match::getSport() const {
    return sport;
}

std::string Match::getLocation() const {
    return location;
}

int Match::getMaxParticipants() const {
    return maxParticipants;
}

bool Match::getIsPublic() const {
    return isPublic;
}

std::vector<std::string> Match::getParticipants() const {
    return participants;
}

int Match::getAvailableSpots() const {
    return maxParticipants - static_cast<int>(participants.size());
}

void Match::addParticipant(const std::string& username) {
    participants.push_back(username);
}

bool Match::isUserEnrolled(const std::string& username) const {
    return std::find(participants.begin(), participants.end(), username) != participants.end();
}

void Match::addSpectator(const std::string& name) {
    spectators.push_back(name);
}

std::vector<std::string> Match::getSpectators() const {
    return spectators;
}

std::string Match::getInfo() const {
    return "Match: " + sport + " at " + location;
}
